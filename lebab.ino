int myPins[] = {12, 11, 10, 9, 8, 7, 6, 5};
char indices[] = "12345678";
unsigned long timeNow = 0; // microsec
int duration = 5000; // microsec
long timeOn[] = {-duration, -duration, -duration, -duration, -duration, -duration, -duration, -duration};

void setup()
{
  Serial.begin(9600);
  for (int n = 0; n < 8; n++) {
    pinMode(myPins[n], OUTPUT);
  }
}

void loop()
{
  timeNow = micros();
  for (int n = 0; n < 8; n++) {
    if (timeNow  < (timeOn[n] + duration)) {
      digitalWrite(myPins[n], 1);
    } else {
      digitalWrite(myPins[n], 0);
    }
  }
  delayMicroseconds(5);
}

void serialEvent() {
  timeNow = micros();
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    Serial.println(inChar);
    for (int n = 0; n < 8; n++) {
      if (inChar == indices[n]) {
        timeOn[n] = timeNow;
        Serial.println(timeNow);
      }
    }
  }
}

