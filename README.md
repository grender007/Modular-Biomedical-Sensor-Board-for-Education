# Modular-Biomedical-Sensor-Board-for-Education
Modular Biomedical Sensor Board for Education, designed for the Department of Biomedical Engineering (BME) of the University of Arizona (UofA). The device currently integrates five different sensor for physiological measurements:

--> [Skin Impedance Sensor](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/Skin%20Impedance%20Sensor)

--> [Temperature Sensor](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/Temperature%20Sensor)

--> [ECG Sensor](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/ECG%20Sensor%20)

--> [Pulse Ox Sensor](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/Pulse%20Ox%20Sensor)

--> [Digital Stethoscope Sensor](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/Sound%20Sensor)

# Project Description
This is a wireless device mainly supported by ESPNow. Each one of the sensors has its own PCB and its own ESP32-S3 (see Arduino Code in any of the sensor folders). The signals are sent to a sixth ESP32-S3, [the receiver](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/ESP32%20Receiver), that simultaneously communicates with the user's computer through the [GUI](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/tree/main/GUI). The GUI displays the measurements in real time and allows the user to record and save the information.

# Housing


