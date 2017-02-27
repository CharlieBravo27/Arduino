const int  buttonPin = 8;    // the pin that the pushbutton is attached to
const int RedledPin = 9;       // the pin that the LED is attached to
const int GreenledPin = 10;       // the pin that the LED is attached to
const int BlueledPin = 11;       // the pin that the LED is attached to

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(RedledPin, OUTPUT);
  pinMode(GreenledPin, OUTPUT);
  pinMode(BlueledPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("Button press count:  ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button
      // wend from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState = buttonState;


  // turns on the LED every four button pushes by
  // checking the modulo of the button push counter.
  // the modulo function gives you the remainder of
  // the division of two numbers:
  //if (buttonPushCounter % 4 == 0) {
  if (buttonPushCounter == 1) {
    digitalWrite(RedledPin, HIGH);
  } else {
    digitalWrite(RedledPin, LOW);
  }
  if (buttonPushCounter == 2) {
    digitalWrite(GreenledPin, HIGH);
  } else {
    digitalWrite(GreenledPin, LOW);
  }
    if (buttonPushCounter == 3) {
    digitalWrite(BlueledPin, HIGH);
  } else {
    digitalWrite(BlueledPin, LOW);
  }
// Reset count back to zero
if(buttonPushCounter > 3) buttonPushCounter =0;
}
