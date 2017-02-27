int redLED = 9;      // LED connected to digital pin 9
int greenLED = 10;
int blueLED = 11;


void setup()

{

  pinMode(redLED, OUTPUT);   // sets the pin as output
  pinMode(greenLED, OUTPUT);   // sets the pin as output
  pinMode(blueLED, OUTPUT);   // sets the pin as output

}



void loop()

{

  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 10) {
    // sets the value (range from 0 to 255):
    analogWrite(redLED, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(50);
  }
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 10) {
    // sets the value (range from 0 to 255):
    analogWrite(greenLED, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(50);
  }
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 10) {
    // sets the value (range from 0 to 255):
    analogWrite(blueLED, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(50);
  }
}

  
