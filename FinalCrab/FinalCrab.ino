//neoPixels
#include <Adafruit_NeoPixel.h>
//amt, pin
Adafruit_NeoPixel strip(60, 4);


#include <Servo.h>

Servo myServo;

static float angle = 0;


//boolean currentReading = false;
boolean currentState = false;
boolean prevState = false;
boolean currentState1 = false;
boolean prevState1 = false;
int buttonPin = 2;
int buttonPin1 = 3;

void setup() {
  Serial.begin(9600);
  strip.begin();
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin1, INPUT);
  myServo.attach(5);
  myServo.write(0);
}

void loop() {
  //   //update the preious reading
  prevState = currentState;
  prevState1 = currentState1;
  //update current reading
  currentState = debounce(buttonPin, prevState);
  currentState1 = debounce(buttonPin1, prevState1);


  //toggle if statement
  if (currentState == true && prevState == false) {
    angle = 0;
    myServo.write(angle);

    glow(strip.Color(255, 0, 0));
  }
  if (prevState1 == true && currentState1 == false) {
    angle = 60;
    myServo.write(angle);

    glow(strip.Color(255, 0, 255));
  }

  // // if(angle < 0){
  // // angle = 0;
  // // }

  // // else if (angle > 90){
  // // angle = 90;
  // // }
}

boolean debounce(int aButtonPin, boolean aPrevState) {
  boolean currentState = digitalRead(aButtonPin);


  if (currentState == HIGH && aPrevState == LOW) {
    delay(20);
  }

  return currentState;
}

void glow(uint32_t color) {
  strip.setBrightness(255);
  for (int i = 0; i < 60; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}