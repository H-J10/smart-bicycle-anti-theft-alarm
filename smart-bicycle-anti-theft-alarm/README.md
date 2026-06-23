# Smart Bicycle Anti-Theft Alarm  
### A Tilt-Based Detection System with Temporal Filtering

**Members:** ABDIHAKIM IBRAHIM - BSCCS/2023/63180 & THIAURI JOY - BSCCS/2024/44193
**Course:** BPY1111 - Physics for Computing  
**Project:** #19 – Smart Bicycle Anti-Theft Alarm  
**Date:** 22ND June 2026

---

## Abstract

Urban bicycle theft remains a widespread nuisance, often targeting unattended bicycles in public spaces. This project presents a low-cost, tilt-sensitive anti-theft alarm system designed to deter unauthorised movement. Unlike simple vibration sensors that trigger on ambient noise, our system implements a temporal filtering mechanism — requiring a continuous tilt for five seconds before activating the buzzer. This approach minimises nuisance alarms while maintaining high detection fidelity for genuine theft attempts. The system was successfully prototyped and verified using the Tinkercad simulation environment, demonstrating reliable state transitions between "Safe" and "Alert" modes.

---

## 1. Introduction

The primary challenge in designing a bicycle anti-theft device is distinguishing between accidental disturbances (wind, passing pedestrians, or the owner accidentally bumping the bike) and actual theft. A thief must physically lift or displace the bicycle, which typically requires several seconds of sustained movement.

We hypothesise that a sustained tilt angle is a more reliable indicator of theft than instantaneous vibration. To test this, we utilised an Arduino Uno to read a digital input (simulating a tilt switch) and control an auditory output. The 5-second delay acts as a simple digital filter, rejecting transient disturbances that would otherwise generate false alarms.

---

## 2. Methodology

### 2.1 Simulation Environment

The circuit was constructed using Autodesk Tinkercad, which allowed for rapid prototyping and logic verification without the need for physical components. This environment enabled us to iterate on the design and test edge cases efficiently.

### 2.2 Hardware Logic

A push button was employed to emulate the behaviour of a normally-open tilt sensor. The circuit follows standard pull-down resistor logic to ensure a defined state when the switch is open.

| Component | Connection |
|-----------|------------|
| Button Terminal A (top-left) | Arduino 5V |
| Button Terminal B (top-right) | Arduino D2 |
| 10kΩ Resistor (Leg 1) | Arduino D2 (same point as button) |
| 10kΩ Resistor (Leg 2) | Arduino GND |
| Buzzer (+) | Arduino D8 |
| Buzzer (-) | Arduino GND |

The resistor ensures that D2 reads LOW when the button is not pressed. When the button is pressed, 5V overrides the resistor, pulling D2 HIGH.

### 2.3 Algorithm Design

The embedded C++ code operates on a simple state machine. The system continuously monitors the tilt pin. When a tilt is detected, a timer begins. Only when the tilt condition persists for at least 5000 milliseconds does the system transition to the alarm state. This temporal hysteresis ensures that brief vibrations or accidental bumps do not trigger the buzzer.

---

## 3. Results

The simulation validated the system's operational criteria as expected.

- **Idle State:** The Serial Monitor continuously returns the status "Safe", indicating the bicycle is upright and secure.
- **Brief Perturbation (< 5 seconds):** Pressing and releasing the button quickly resulted in no alarm trigger, confirming that our false-alarm reduction logic is functional.
- **Sustained Tilt (≥ 5 seconds):** Holding the button for the full duration successfully engaged the buzzer and printed the "ALARM: Bike tilted!" flag to the serial interface.

---

## 4. Discussion

The primary challenge addressed in this design was balancing sensitivity against usability. While a zero-delay trigger is simpler to implement, it is impractical for real-world bicycles subjected to wind, road vibrations, or accidental bumps. The 5-second threshold provides a reasonable balance: it is short enough to detect a thief attempting to lift the bike, yet long enough to avoid frustrating false alarms.

We acknowledge that in a real-world scenario, a 5-second delay might allow a skilled thief to cut a lock. However, the loud audible buzzer acts as a powerful deterrent, drawing immediate attention to the act. Future iterations could reduce this delay or incorporate a secondary sensor (e.g., GPS) for added security.

---

## 5. Future Work & Physical Implementation

While this project was conducted entirely in simulation, the transition to physical hardware is straightforward and planned:

1. Replace the push button with a genuine ball-tilt sensor (e.g., SW-520D).
2. Encapsulate the circuit in a waterproof housing to protect against weather.
3. Power the system using a 9V rechargeable battery or a small power bank for independent operation.
4. Optionally, integrate a GSM or Bluetooth module to send real-time alerts to the owner's smartphone.

---

## 6. Repository Structure
smart-bicycle-anti-theft-alarm/
├── README.md
├── code/
│ └── anti_theft_alarm.ino
└── images/
├── circuit.png
├── code_snippet.png
└── serial_monitor.png

---

## 7. Members Contributions

- **Abdihakim Ibrahim Adan :** Circuit design, algorithm implementation, and simulation testing.
- **Thiauri Joy Gacheri :** Documentation, screenshot capture, and presentation preparation.

---

## 8. Tinkercad Simulation

**Link:** https://www.tinkercad.com/things/gJVWhx1mgLa/editel?returnTo=%2Fdashboard&sharecode=yWyaWC9pH8-UkBioRJagEOgLCEunCnEizoJ_y-euaZc

---

## Acknowledgments

This project was developed as part of the BPY1111 curriculum, focusing on the application of computational physics to real-world electronic systems.

---

*Built as part of BPY1111 practicals – June 2026*
