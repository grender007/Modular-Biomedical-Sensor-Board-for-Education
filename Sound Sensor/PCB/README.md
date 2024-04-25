These are the EAGLE files for the Sound Sensor PCB. 

The circuit is relatively simple. The microphone send an analog signal (that was already amplified in the built it circuitry of the MAX9844) to a analog filter stage. This is a second order LPF. Then the filtered signal is sent to the audio CODEC, where it is digitized and later sent to the ESP32 microcontroller.

![alt The circuit](https://github.com/grender007/Modular-Biomedical-Sensor-Board-for-Education/blob/main/Sound%20Sensor/PCB/SoundSensorTop.png)

See the Documents folder for assembly process.
