//TRANSMITTER

// Emergencial car alarm by Lucas Zanella
// This is an emergencial alarm designed to be inserter in your car and to be monitored by a near computer.
// When your car detects a movement and sends to your computer, or your computers detects the absence of 
// signal coming from your car, you know something is going wrong.
// It uses two arduinos, each one connected to a transmitter (you can use a TX-only for your car, and a 
// RX-only for your home computer) and a PIR sensor. 
// I tested with 2 arduino pro mini, each one on a mini breadboard, connected to an xbee pro 900mhz for
// long range between my car in the street and my computer inside my house, and a PIR sensor from sparkfun.

//This code is based on the PIR sensor code and debouncing code from these sites:
//https://www.arduino.cc/en/Tutorial/Debounce
//https://learn.sparkfun.com/tutorials/pir-motion-sensor-hookup-guide


const int SENSOR = 4; // Sensor pin
const int LED = 5; // LED pin to debug movement

const int HEALTHY = 1; // Status to send every x milliseconds to tell everything's ok
const int MOVEMENT = 2; // Status to send when detected a movement

// Debouncing variables
int sensorState = HIGH;
int lastSensorState = LOW;
// the following variables are unsigned long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 40;    // the debounce time; increase if the output flickers

void setup() 
{
  Serial.begin(115200);
  // The PIR sensor's output signal is an open-collector, 
  // so a pull-up resistor is required:
  pinMode(SENSOR, INPUT_PULLUP);
  // Sets the led output pin (just for debugging movement)
  pinMode(LED, OUTPUT);
}

// Function that will alert that a motion ocurred
void alertMotion() {
  digitalWrite(LED, HIGH);
}

void loop() 
{
  // Reads the current state of the sensor
  int reading = digitalRead(SENSOR);

  // If the sensor's state changed, due to noise or actual movement:
  if (reading != lastSensorState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the sensor state has changed:
    if (reading != sensorState) {
      sensorState = reading;
    }
  }

  Serial.println(sensorState);
  digitalWrite(LED, sensorState);
  // save the reading.  Next time through the loop,
  // it'll be the lastSensorState:
  lastSensorState = reading;
}
