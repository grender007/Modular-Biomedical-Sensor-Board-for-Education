# Modular-Biomedical-Sensor-Board-for-Education
Modular Biomedical Sensor Board for Education, designed for the Department of Biomedical Engineering (BME) of the University of Arizona (UofA). The device currently integrates five different sensor for physiological measurements:

* [Skin Impedance Sensor](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/Skin%20Impedance%20Sensor)

* [Temperature Sensor](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/Temperature%20Sensor)

* [ECG Sensor](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/ECG%20Sensor%20)

* [Pulse Ox Sensor](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/Pulse%20Ox%20Sensor)

* [Digital Stethoscope Sensor](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/Sound%20Sensor)

Each one of the folders include the Arduino Code (that also enables wireless communication) and the PCB files, with a list of the used parts.

# Project Description
This is a wireless device mainly supported by ESPNow. Each one of the sensors has its own PCB and its own ESP32-S3 (see Arduino Code in any of the sensor folders). The signals are sent to a sixth ESP32-S3, [the receiver](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/ESP32%20Receiver), that simultaneously communicates with the user's computer through the [GUI](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/GUI). The GUI displays the measurements in real time and allows the user to record and save the information.

# Sensor Modules
All the sensor modules are meant to be the same, being the only difference each sensor and the PCB that includes the required circuitry (But all the PCB have the same dimension and orientation). Each (sensor module)[https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/Housing%20Models/Module%20Casing] has different features. It includes an OLED screen that displays the current battery level and a button that allows the deep sleep mode of the ESP32-S3. The casing it is designed for the ESP32-S3 to be powered by a battery and to recharge with a magnetic plug.

