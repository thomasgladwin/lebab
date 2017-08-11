int myPins[] = {12, 11, 10, 9, 8, 7, 6, 5};
char indices[] = "01234567";

char latestChar = "";

void setup()
{
  Serial.begin(9600);
  for (int n = 0; n < 8; n++) {
    pinMode(myPins[n], OUTPUT);
  }
}

void loop()
{
  for (int n = 0; n < 8; n++) {
    digitalWrite(myPins[n], 0);
    if (latestChar == indices[n]) {
      Serial.println(latestChar);
      latestChar = "";
      digitalWrite(myPins[n], 1);
    }
  }
  delay(5);
}

void serialEvent() {
  if (Serial.available()) {
    char inChar = (char)Serial.read();
    latestChar = inChar;
  }
}

