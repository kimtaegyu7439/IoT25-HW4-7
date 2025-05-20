# IoT25-HW4-7

This repository contains assignments HW4 to HW7 for the "Sensors and Wireless Technologies / Introduction to IoT" course at the School of Computing, Gachon University (Spring 2025), instructed by Prof. Jaehyuk Choi.  
Each assignment was implemented using the ESP32 microcontroller and the Arduino IDE environment.

---

## HW4. ESP32 Bluetooth Classic with Arduino IDE

**Objective:**  
To practice Bluetooth Classic communication using the ESP32 and test it with a smartphone app.

**Tasks:**
- Modify BLE device name to your own name
- Upload example Bluetooth Classic sketch from Arduino IDE
- Connect using the Android app "Serial Bluetooth Terminal"
- Test pairing and data exchange

**Result:**

![HW4 Result](https://github.com/user-attachments/assets/0104b695-8053-4046-8510-f964412549ed)

---

## HW5. BLE & ESP32 BLE Server and Client

**Objective:**  
To implement Bluetooth Low Energy communication between two ESP32 devices acting as a BLE Server and Client.

**Tasks:**
- Implement BLE Server and Client using provided example
- Test connection and data transfer
- Use the "nRF Connect" mobile app to verify BLE Server behavior

**Result:**

![HW5 Result](https://github.com/user-attachments/assets/405e6b7f-0e68-4163-8b93-6e49beb18ab6)

**Demo Video:**  
🎥 [https://youtu.be/JhUhMVVAv-8](https://youtu.be/JhUhMVVAv-8)

---

## HW6. ESP32 Web Server

**Objective:**  
To build a simple web server with ESP32 that controls outputs (e.g., two LEDs) via a web interface.

**Tasks:**
- Follow the tutorial to create a web server on ESP32
- Control outputs through the browser interface

**Result:**

![HW6 Result](https://github.com/user-attachments/assets/d5d1c993-7c55-402c-97fe-8c95ce4e4a4b)

**Demo Video:**  
🎥 [https://youtu.be/DpQLliApMH8](https://youtu.be/DpQLliApMH8)

---

## HW7. Team BLE-based Distance Estimation System

**Objective:**  
To estimate distance between two ESP32 devices using BLE signal strength (RSSI) and txPower, then compare estimated vs actual distances.

**Tasks:**
1. Establish BLE communication between ESP32 Server and Client
2. Measure RSSI from advertisement packets
3. Apply a distance estimation model:
4. Display estimated distance on the Serial Monitor in real time
5. Conduct measurements at distances (0.5m, 1m, 2m, 3m, 4m)
6. Visualize results in a table and bar chart

**Demo Video:**  
🎥 [https://youtu.be/9aF2WBM4O5k](https://youtu.be/9aF2WBM4O5k)

**Result Images:**

![HW7 Distance Estimation](https://github.com/user-attachments/assets/a376d532-07a0-4408-84c5-a6f6dc772adb)

![HW7 Distance Bar Chart](https://github.com/user-attachments/assets/a7aa58fd-2a98-4859-82cd-bdbacf50dd37)

---

### 🔧 Advanced Features (Bonus)

**1. Real-time distance display on Web Server (5 pts)**  
Displays the estimated BLE distance on a live ESP32-hosted web interface.

**2. LED Proximity Alert (5 pts)**  
An LED blinks when the detected distance is less than a predefined threshold (e.g., within 1 meter).

**Results:**

![Web Server UI](https://github.com/user-attachments/assets/2464e5bc-58a0-4e7b-bfa7-fbef992f7c7f)
![LED Alert](https://github.com/user-attachments/assets/061c3d9a-73fd-4dbf-84cf-9f6fb3ef5ddb)
![Live Feedback](https://github.com/user-attachments/assets/91c02561-35cd-4fdc-9ac4-5d3bf9833a55)


