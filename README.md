# CP-arduino-test

This project simulates a simple Arduino controller with:

- 3 buttons: `HIRED`, `REJECTED`, and `NEXT`
- 5 LEDs functioning as a countdown timer (30 seconds total)

Built and tested in **TinkerCAD Circuits**.

## Components Used

- Arduino Uno R3
- Breadboard
- 3 push buttons (connected to pins 2, 3, and 4)
- 5 LEDs with 220Ω resistors (connected to pins 5 to 9)
- Jumper wires
- Serial Monitor for output

## How It Works

- The LED countdown runs for 30 seconds (each LED lights up every 6 seconds).
- Pressing a button ("HIRED", "REJECTED", or "NEXT") resets the countdown and logs the action via Serial.
- If no decision is made in 30 seconds, it logs `"TIMEOUT"` and resets automatically.
