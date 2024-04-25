/**
 * @brief We configure the audio codec ES8388 with the help of AudioTools I2SCodecStream.
 * Then, we filtered the stream of bits using a second order IIR with FilteredStream.
 * Finally, we send the stream of bits to a secondary ESP32-S3 using ESP-NOWStream.
 * @author Daniel Campana
 */

#include "AudioTools.h" // install https://github.com/pschatzmann/arduino-audio-tools
#include "AudioLibs/I2SCodecStream.h"
#include "Communication/ESPNowStream.h"

// I2C
#define SDAPIN               3 // I2C Data,  Adafruit ESP32 S3 3, Sparkfun Thing Plus C 23
#define SCLPIN               4 // I2C Clock, Adafruit ESP32 S3 4, Sparkfun Thing Plus C 22
#define I2CSPEED        100000 // Clock Rate
#define ES8388ADDR        0x10 // Address of ES8388 I2C port

// I2S, your configuration for the ES8388 board
#define MCLKPIN             14 // Master Clock
#define BCLKPIN             36 // Bit Clock
#define WSPIN                8 // Word select
#define DOPIN               37 // This is connected to DI on ES8388 (MISO)
#define DIPIN               35 // This is connected to DO on ES8388 (MOSI)

AudioInfo                     audio_info(8000, 1, 16);                // sampling rate, # channels (mono), bit depth

DriverPins                    my_pins;                                 // board pins
AudioBoard                    audio_board(AudioDriverES8388, my_pins); // audio board
I2SCodecStream                i2s_out_stream(audio_board);             // i2s coded
TwoWire                       myWire = TwoWire(0);                     // universal I2C interface

// Set up filtered stream and copy it to ESP-NOW. The coefficients of the filter may vary (depending on sampling rate)
uint16_t channels = 1;
FilteredStream<int16_t, float> inFiltered(i2s_out_stream, channels);
// Current specifications of the filter: fc_high = 100, fc_low = 1150, fs = 8000. See MATLAB code for variations of this filter
const float b_coefficients[] = { 0.1158, 0.0000,-0.2317, 0.0000, 0.1158};
const float a_coefficients[] = { 1.0000,-2.6850, 2.6850,-1.2530, 0.2559};

ESPNowStream now;
StreamCopy copier_now(now, inFiltered);  // copies i2s_out_stream into i2s
const char *peers[] = {"DC:54:75:C0:92:28"}; //Receiver 

 CsvOutput<int16_t> Serial_out(Serial);                                 // ASCII output stream 
 StreamCopy copier_output(Serial_out, inFiltered); 

void setup() {
  // Setup logging
  Serial.begin(115200);
  AudioLogger::instance().begin(Serial, AudioLogger::Warning);
  LOGLEVEL_AUDIODRIVER = AudioDriverWarning;
  delay(2000);

  Serial.println("Setup starting...");

  Serial.println("I2C pin ...");
  my_pins.addI2C(PinFunction::CODEC, SCLPIN, SDAPIN, ES8388ADDR, I2CSPEED, myWire);
  Serial.println("I2S pin ...");
  my_pins.addI2S(PinFunction::CODEC, MCLKPIN, BCLKPIN, WSPIN, DOPIN, DIPIN);

  Serial.println("Pins begin ..."); 
  my_pins.begin();

  Serial.println("Board begin ..."); 
  // audio_board.begin();
  CodecConfig cfg;
      //No output to codec
      cfg.output_device = DAC_OUTPUT_NONE;
      //Mic input from adc channel 1
      cfg.input_device = ADC_INPUT_LINE1;  
      //IS2 format
      cfg.i2s.fmt = I2S_NORMAL;
      //Bits per sample (16 bits)                     
      cfg.i2s.bits = BIT_LENGTH_16BITS;
      //Sample Rate (44.1 kHz)
    //cfg.i2s.rate = RATE_44K;
      cfg.i2s.rate = RATE_8K;
   audio_board.begin(cfg);
  //Additional ADC configuration ---> Everything else is in default mode (See datasheet)
      //set to mono mix in ADC channel 1 (lin1/Mic pin) --> 00001000 == 0x08 in ADCControl 3
   es8388_write_reg(ES8388_ADCCONTROL3, 0x08);

  Serial.println("I2S begin ..."); 
  auto i2s_config = i2s_out_stream.defaultConfig(RXTX_MODE); //RXTX for douplex //RX for sink //TX for source
  i2s_config.copyFrom(audio_info);
  i2s_out_stream.begin(i2s_config); // this should apply I2C and I2S configuration

  // Setup CSV
    Serial.println("CSV begin...");
    Serial_out.begin(audio_info);

  // Setup filter
  inFiltered.setFilter(0, new IIR<float>(b_coefficients, a_coefficients));

  // Setup ESP_NOW
  auto now_cfg = now.defaultConfig();
  now_cfg.mac_address = "DC:54:75:C0:92:2C";
  now.begin(now_cfg);
  now.addPeers(peers);

  Serial.println("Setup completed ...");
}

// Arduino loop - copy sound to out
void loop() { 
  copier_output.copy();
  //copier_now.copy();
}