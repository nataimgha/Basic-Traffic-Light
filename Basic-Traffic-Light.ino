// assigning words to pin numbers for readability and coding ease

#define TRIG 7
#define ECHO 6
#define GREEN 13
#define YELLOW 12
#define RED 11
#define BUZZER 10
#define WALK 9
#define PBUTTON 8

void setup() {
  pinMode(GREEN, OUTPUT); // green
  pinMode(YELLOW, OUTPUT); // yellow
  pinMode(RED, OUTPUT); // red
  pinMode(BUZZER, OUTPUT); // buzzer
  pinMode(WALK, OUTPUT);  // white walk LED
  pinMode(PBUTTON, INPUT);   // button

  Serial.begin(9600); // starting serial monitor to monitor distance w
  pinMode(TRIG, OUTPUT); // US sensor sending high frequency sound
  pinMode(ECHO, INPUT); // US sensor receiving high frequency sound
}

void loop() {

  // pedestrian button
  if (digitalRead(PBUTTON) == HIGH) { // if button is pressed
    digitalWrite(BUZZER, HIGH); // make buzzer beep
    delay(100); // short delay before LOW to make quick beep
    digitalWrite(BUZZER, LOW);
    delay(1500);
    digitalWrite(WALK, HIGH);  // walk sign light
    delay(10000);
    digitalWrite(WALK, LOW); // walk sign off
    delay(2500);

  }

  // ultrasonic sensor for cars
  else {

    digitalWrite(RED, HIGH); // red on

    // ultrasonic pulse
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    // sending out sound wave and pulseIn measures how many 
    // microseconds it takes for sound to come back, storing in duration
    long duration = pulseIn(ECHO, HIGH);
    // calculating distance based on speed of sound.
    long distance = duration * 0.034 / 2;
    // printing distance to monitor 
    Serial.println(distance);
    delay(1000);
    // --- CAR DETECTED ---
    if (distance <= 8) {
      delay(4000);
      digitalWrite(RED, LOW); // turn red light off
      digitalWrite(GREEN, HIGH); // turn green light oon
      delay(8000);
      digitalWrite(GREEN, LOW);
      digitalWrite(YELLOW, HIGH); // yellow 
      delay(3500);
      digitalWrite(YELLOW, LOW);
      digitalWrite(RED, HIGH); // back to red
    }
  }
}
