#include <WiFi.h>
#include <BLEDevice.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

// — 네트워크 설정 —
const char* WIFI_SSID = "KT_GiGA_E882";
const char* WIFI_PWD  = "private";

// — BLE 필터 설정 —
#define TARGET_NAME  "IoT_E"
#define TARGET_UUID  "81a1c112-d7c0-48fc-bc38-7032db57e3f9"

// — 경로손실 모델 파라미터 —
// 1m 에서 평균 RSSI 값으로 txPower = –80 dBm 사용
const int   txPower     = -80;
const float PATH_LOSS   = 2.0;
const int   SCAN_SEC    = 2;
const float ALERT_DIST  = 1.0;
const int   LED_PIN     = 2;

// — 이동평균 윈도우 크기 —
const int   WINDOW_SIZE = 5;
float       distBuf[WINDOW_SIZE];
int         bufIdx = 0;

// — 서버 & 상태 변수 —
WiFiServer web(80);
float currentDistance = -1.0;

// 거리 계산 함수
float estimateDistance(int rssi) {
  // rssi 는 음수, txPower 도 음수이므로 (txPower - rssi)
  return pow(10.0f, float(txPower - rssi) / (10.0f * PATH_LOSS));
}

// BLE 폴링 스캔
void doBleScan() {
  BLEScan* scan = BLEDevice::getScan();
  scan->setActiveScan(true);
  BLEScanResults* res = scan->start(SCAN_SEC, false);

  float d = -1;
  for (int i = 0; i < res->getCount(); ++i) {
    auto dev = res->getDevice(i);
    if (dev.haveName() && dev.getName() == TARGET_NAME
      && dev.haveServiceUUID() && dev.isAdvertisingService(BLEUUID(TARGET_UUID))) {
      d = estimateDistance(dev.getRSSI());
      break;
    }
  }
  scan->clearResults();

  // 이동평균
  distBuf[bufIdx++] = (d > 0 ? d : 0);
  if (bufIdx >= WINDOW_SIZE) bufIdx = 0;
  float sum = 0;
  for (int i = 0; i < WINDOW_SIZE; i++) sum += distBuf[i];
  currentDistance = sum / WINDOW_SIZE;

  // LED 알림
  digitalWrite(LED_PIN, (currentDistance > 0 && currentDistance <= ALERT_DIST));
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  // Wi-Fi 연결
  WiFi.begin(WIFI_SSID, WIFI_PWD);
  while (WiFi.status() != WL_CONNECTED) delay(200);
  web.begin();

  // BLE 초기화
  BLEDevice::init("");
  for (int i = 0; i < WINDOW_SIZE; i++) distBuf[i] = 0;
}

void loop() {
  doBleScan();

  // 시리얼 출력
  Serial.printf("Smoothed Distance: %.2f m\n", currentDistance);

  // WebServer 처리
  WiFiClient client = web.available();
  if (!client) { delay(50); return; }
  while (client.connected() && client.available() && client.read() != '\n');
  client.print(F(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html\r\n"
    "Connection: close\r\n\r\n"
    "<!DOCTYPE html><html><body>"
  ));
  client.printf("<h1>Distance: %.2f m</h1>", currentDistance);
  if (currentDistance > 0 && currentDistance <= ALERT_DIST) {
    client.print(F("<p style='color:red;'>⚠ Within 1 m</p>"));
  }
  client.print(F("</body></html>"));
  client.stop();
}
