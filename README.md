# Modular-Biomedical-Sensor-Board-for-Education
Modular Biomedical Sensor Board for Education, designed for the Department of Biomedical Engineering (BME) of the University of Arizona (UofA). The device currently integrates five different sensor for physiological measurements:

* [Skin Impedance Sensor](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/Skin%20Impedance%20Sensor)

* [Temperature Sensor](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/Temperature%20Sensor)

* [ECG Sensor](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/ECG%20Sensor%20)

* [Pulse Ox Sensor](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/Pulse%20Ox%20Sensor)

* [Digital Stethoscope Sensor](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/Sound%20Sensor)

Each one of the folders include the Arduino Code (that also enables wireless communication), the PCB files, and the corresponding insert for the casing.

![alt exterior](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/blob/main/Housing%20Models/exterior.png)

# Project Point Design
This is a wireless device mainly supported by ESPNow. Each one of the sensors has its own PCB and its own ESP32-S3 (see Arduino Code in any of the sensor folders). The signals are sent to a sixth ESP32-S3, [the receiver](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/ESP32%20Receiver), that simultaneously communicates with the user's computer through the [GUI](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/GUI). The GUI displays the measurements in real time and allows the user to record and save the information.

When not in use, the sensors can be placed on the charging station, where the batteries can be recharged.

![alt Concept](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/blob/main/Concept%20Design.png)

# Sensor Modules
All the sensor modules are meant to be the same, being the only difference each sensor and the PCB that includes the required circuitry (But all the PCB have the same dimension and orientation). Each [sensor module](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/Housing%20Models/Module%20Casing) has different features. It includes an OLED screen that displays the current battery level and a button that allows the deep sleep mode of the ESP32-S3. The casing it is designed for the ESP32-S3 to be powered by a battery and to recharge with a magnetic plug.
All the modules can be placed on the [charging station](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/Housing%20Models/Charging%20Station) to recharge the batteries. The receiver includes its own [casing](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/Housing%20Models/Receiver%20Casing).

![alt interior1](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/blob/main/Housing%20Models/interior.png)

![alt interior2](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/blob/main/Housing%20Models/interior2.png)

# Assembly
The detailed asssembly process and the required parts for the device are shown in the Documents folder.

