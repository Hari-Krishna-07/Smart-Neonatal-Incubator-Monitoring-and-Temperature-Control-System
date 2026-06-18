# Smart Neonatal Incubator Monitoring and Temperature Control System

## 📂Repository Structure

```text
Smart-Neonatal-Incubator-Monitoring-System/
│
├── README.md -->(Circuit connections are given)
├── Arduino_Code/
│   └── neonatal_incubator.ino
│
├── Images/
│   ├── circuit_diagram.png
│   ├── normal_condition.png
│   ├── fan_on_condition.png
│   └── danger_condition.png
│
└── Tinkercad_Link.txt
```


## Overview

The Smart Neonatal Incubator Monitoring and Temperature Control System is a biomedical embedded systems project designed to monitor and regulate incubator temperature for premature and newborn infants.

Premature babies often struggle to maintain their body temperature, making incubators essential for providing a controlled thermal environment. This project demonstrates how embedded systems can automate monitoring, cooling, and alert mechanisms to improve neonatal care.

The project was developed and simulated using **Arduino Uno** and **Tinkercad**.

---

## Problem Statement

Premature infants are unable to regulate body temperature effectively. Manual monitoring of incubator conditions may lead to delayed responses during abnormal temperature situations.

An automated monitoring system is therefore required to:

- Continuously monitor incubator temperature
- Provide automatic cooling
- Alert healthcare personnel during dangerous conditions
- Reduce manual intervention

---

## Introduction

Neonatal incubators are specialized medical devices used to provide a controlled environment for premature and newborn babies. Premature infants have underdeveloped temperature regulation mechanisms, making them highly vulnerable to temperature fluctuations.

The normal body temperature of a healthy newborn infant ranges from **36.5°C to 37°C**. Any deviation from this range can result in serious health complications.

This project provides an embedded-system-based solution to monitor incubator temperature and automatically activate cooling and alert systems when required.

Since Tinkercad has limitations in temperature sensor simulation, a **potentiometer** was used to emulate temperature variations. In a real-world implementation, the potentiometer can be replaced with sensors such as **LM35**, **TMP36**, or **DHT11**.

---

## Components Used

| S.No | Component | Purpose |
|-------|-----------|---------|
| 1 | Arduino Uno | Main controller |
| 2 | Potentiometer | Temperature simulation |
| 3 | 16×2 LCD Display | Status display |
| 4 | DC Motor | Cooling fan |
| 5 | Buzzer | Alert system |
| 6 | NPN Transistor (2N2222) | Motor driver |
| 7 | Resistors | Circuit protection |
| 8 | Jumper Wires | Connections |

---

## Circuit Connections

### Potentiometer

| Pin | Connection |
|------|-----------|
| Left | 5V |
| Middle | A0 |
| Right | GND |

### LCD Display

| LCD Pin | Arduino Pin |
|----------|------------|
| RS | D12 |
| E | D11 |
| D4 | D5 |
| D5 | D4 |
| D6 | D3 |
| D7 | D2 |
| VSS | GND |
| VDD | 5V |
| RW | GND |
| V0 | Contrast Potentiometer |
| LED+ | 5V |
| LED− | GND |

### Cooling Fan (DC Motor)

| Component | Connection |
|------------|-----------|
| Motor Positive | 5V |
| Motor Negative | Transistor Collector |
| Base | Arduino D8 through resistor |
| Emitter | GND |

### Buzzer

| Pin | Connection |
|------|-----------|
| Positive | Arduino D9 |
| Negative | GND |

---

## Working Principle

The potentiometer is connected to Arduino analog pin A0.

The Arduino continuously reads the analog value and interprets it as a simulated temperature. Based on predefined threshold values, the system performs automatic control actions.

### Operating Conditions

#### Normal Condition
- LCD displays **NORMAL**
- Fan OFF
- Buzzer OFF

#### High Temperature Condition
- LCD displays **FAN ON**
- Fan ON
- Buzzer OFF

#### Dangerous Temperature Condition
- LCD displays **DANGER**
- Fan ON
- Buzzer ON

---

## Potentiometer-Based Temperature Simulation

For simulation purposes, the potentiometer is used as a variable voltage divider to represent different temperature conditions.

### Simulated Temperature Ranges

| ADC Range | Simulated Temperature | Status |
|------------|----------------------|---------|
| 0 – 300 | 35°C | Normal |
| 301 – 700 | 38°C | High Temperature |
| 701 – 1023 | 40°C | Dangerous Temperature |

---

## ADC (Analog-to-Digital Converter)

Arduino Uno contains a **10-bit ADC**.

### ADC Specifications

- Input Voltage Range: 0V – 5V
- Resolution: 10-bit
- Output Range: 0 – 1023

### Example Conversions

| Voltage | ADC Value |
|----------|-----------|
| 0V | 0 |
| 2.5V | 512 |
| 5V | 1023 |

The Arduino uses the `analogRead()` function to convert the analog voltage into a digital value.

---

## Results

### Normal Condition
- ADC Range: 0 – 300
- Simulated Temperature: 35°C
- LCD Status: NORMAL
- Fan: OFF
- Buzzer: OFF

### High Temperature Condition
- ADC Range: 301 – 700
- Simulated Temperature: 38°C
- LCD Status: FAN ON
- Fan: ON
- Buzzer: OFF

### Dangerous Temperature Condition
- ADC Range: 701 – 1023
- Simulated Temperature: 40°C
- LCD Status: DANGER
- Fan: ON
- Buzzer: ON

---

## Challenges Faced

- Difficulty simulating temperature sensors in Tinkercad
- LCD contrast adjustment issues
- LCD backlight current errors
- Integration of multiple hardware components
- Calibration of ADC threshold values

To overcome these challenges, a potentiometer was used to simulate temperature variations during testing.

---

## Advantages

- Continuous temperature monitoring
- Automatic cooling mechanism
- Immediate danger alerts
- Reduced manual intervention
- Cost-effective implementation
- Suitable for neonatal healthcare applications

---

## Future Scope

- Replace potentiometer with LM35 or TMP36 temperature sensor
- Add humidity monitoring
- Integrate IoT-based remote monitoring
- Cloud data logging
- Mobile application support
- Real-time healthcare dashboard

---

## Applications

- Neonatal Intensive Care Units (NICUs)
- Infant Healthcare Monitoring
- Biomedical Embedded Systems
- Smart Healthcare Solutions
- Medical Device Prototyping

---

## Conclusion

The Smart Neonatal Incubator Monitoring and Temperature Control System demonstrates how embedded systems can be applied in biomedical engineering to improve infant healthcare. The system provides automated monitoring, cooling control, and emergency alerts.

Although a potentiometer was used for simulation purposes in Tinkercad, the project can be upgraded with real temperature sensors for practical healthcare applications.

---

## Author

**Hari Krishna**

Biomedical Engineering Student  
Embedded Systems Enthusiast  
Healthcare Technology Learner
