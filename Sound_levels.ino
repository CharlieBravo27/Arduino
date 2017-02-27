/*
Turns on the LED according to sound level recorded by the sound sensor (HR11080 from geeetech).

*/


int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int sensorPin = A0;   // select the input pin for the sensor
int sensorval = 0;    // variable to store the value coming from the sensor

const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;


// the setup routine runs once when you press reset:
void setup() {
// initialize the digital pin as an output.
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
pinMode(led5, OUTPUT);
Serial.begin(9600); // initialize serial communication with computer
}

// the loop routine runs over and over again forever:
void loop() {

   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level
 
   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;
 
   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(0);
      if (sample < 1024)  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
   }
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
   double volts = (peakToPeak * 5.0) / 1024;  // convert to volts

//sensorval = analogRead(sensorPin); // read the value from the sensor
//Serial.println(sensorval); // send it to the computer (as ASCII digits)

digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
digitalWrite(led5, LOW);
delay(1);
if (volts > 0.02) {digitalWrite(led1, HIGH); }
if (volts > 0.03) {digitalWrite(led2, HIGH); }
if (volts > 0.04) {digitalWrite(led3, HIGH); }
if (volts > 0.05) {digitalWrite(led4, HIGH); }
if (volts > 0.06) {digitalWrite(led5, HIGH); }
//delay(1);

Serial.println(volts);
}
