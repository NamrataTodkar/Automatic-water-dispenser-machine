# Automatic-water-dispenser-machine
The Automatic Water Dispenser Machine uses an Arduino Nano, flow sensor, and manual buttons to control water dispensing. It measures flow in real time, stopping after a set volume or manually via the Stop button. The system is ideal for bottle filling and automation demos.
# Automatic Water Dispenser Machine

This project demonstrates a simple **Automatic Water Dispenser Machine** using an **Arduino Nano**, a **flow sensor**, and **manual control buttons**. It is designed as a miniaturized model of a bottle filling system.

##  Components Used

- Arduino Nano  
- YF-S201 Water Flow Sensor  
- Relay Module / Transistor (to control a pump or solenoid valve)  
- Push Button (Start)  
- Push Button (Stop)  
- Water Pump or Solenoid Valve  
- Breadboard and jumper wires  
- Power supply (depending on pump voltage)

##  Working Principle

- When the **Start button** is pressed, the water dispensing process begins.
- Water flows through a flow sensor which measures how much has been dispensed.
- The Arduino calculates the flow in real time.
- If the **Stop button** is pressed during the process, it will immediately stop the water filling.
- The system can also be configured to automatically stop after dispensing a fixed amount (e.g., 250 mL).

##  Code Overview

- The Arduino uses an interrupt to read pulses from the flow sensor.
- The water flow rate is calculated based on pulse count and time.
- Volume is calculated and compared against a threshold (e.g., 250 mL).
- Manual stop overrides automatic control.

##  Features

- Flow-controlled water filling using a flow sensor  
- Manual **Start** and **Stop** push buttons  
- Arduino Nano for processing and control  
- Simple, scalable design for water dispensing systems

##  Setup

1. Connect the flow sensor to digital pin **D2** (interrupt pin).
2. Connect **Start** button to digital pin **D4** and **Stop** button to **D5**.
3. Connect pump control (via relay or transistor) to pin **D3**.
4. Upload the provided Arduino code (`water_dispenser.ino`) to your Arduino Nano.

##  Applications

- Bottle filling machines  
- Home/office automatic dispensers  
- Educational automation demos  
- Scaled models of industrial systems
