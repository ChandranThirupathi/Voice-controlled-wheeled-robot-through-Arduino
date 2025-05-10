# Voice-controlled-wheeled-robot-through-Arduino
A Gen-AI inspired autonomous robot prototype with voice control capabilities using Arduino and Embedded C. This repository showcases the initial phase focusing on real-time robot movement through voice commands.

📌 Project Summary

- Phase 1: Robot controlled through voice commands sent via Bluetooth.
- Technology Used: Arduino UNO/Nano, HC-05 Bluetooth module, Embedded C.
- Input: Voice commands captured on a smartphone and sent as text via Bluetooth.

🧩 Components Used

- Arduino UNO or Nano
- HC-05 Bluetooth Module
- L298N Motor Driver
- 2 DC Motors + Wheels
- Robot Chassis
- Battery Pack (9V or 12V)
- Smartphone with Bluetooth voice control app (e.g., "Arduino Bluetooth Controller", "BT Voice Control for Arduino")

⚙️ Circuit Connections

- HC-05 to Arduino
  - HC-05 TX → Arduino RX (D0)
  - HC-05 RX → Arduino TX (D1) (with voltage divider)
  - VCC → 5V
  - GND → GND

- L298N Motor Driver
  - IN1/IN2/IN3/IN4 → D pins on Arduino (e.g., D2 to D5)
  - ENA/ENB → Connected to 5V or PWM pins
  - Motors → OUT1/OUT2 and OUT3/OUT4
  - Power Supply → 12V input to L298N and GND common with Arduino
  - 
🔤 Supported Voice Commands

Speak the following into your phone app (converted to text and sent via Bluetooth):
- `forward`
- `backward`
- `left`
- `right`
- `stop`

✅ Operation Steps

1. Upload the `.ino` code to Arduino using the Arduino IDE.
2. Power the robot and pair the smartphone with the HC-05 Bluetooth module (default PIN: 1234).
3. Open the voice control app and connect via Bluetooth.
4. Speak commands like "forward", "stop", "left", etc.
5. The robot will move accordingly.

🧠 Future Additions

- Integrate Generative AI for smarter, adaptive behaviors
- Camera module for object tracking
- SOS response and obstacle detection
- GPT-based voice feedback using edge-AI devices

📄 License

MIT License

🤝 Contribute

Pull requests, issues, and suggestions are welcome!
