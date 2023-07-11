#include <Arduino_LSM6DSOX.h>

#define BUTTON_PIN0 6
#define BUTTON_PIN1 7
#define BUTTON_PIN2 8

#define JoyXPIN 0
#define JoyYPIN 1

float Ax, Ay, Az;

int joyX;
int joyY;

void setup() {
  Serial.begin(9600);
  IMU.begin();
  pinMode(BUTTON_PIN0, INPUT_PULLUP);
  pinMode(BUTTON_PIN1, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
}

void loop() {

 if (IMU.accelerationAvailable()) {

    IMU.readAcceleration(Ax, Ay, Az);
    Serial.print(Ax);
    Serial.print(",");
    Serial.print(Ay);
    Serial.print(",");
    Serial.print(Az);
    Serial.print(",");

  }

  joyX = analogRead(JoyXPIN);
  joyY = analogRead(JoyYPIN);

  // Serial.println(joyX);
  // Serial.println(joyY);

    if (joyX >= 700) {
      Serial.print(1);
      Serial.print(",");
    } else if (joyX <= 300) {
      Serial.print(-1);
      Serial.print(",");
    } else {
      Serial.print(0);
      Serial.print(",");
    }

    if (joyY >= 700) {
      Serial.print(-1);
      Serial.print(",");
    } else if (joyY <= 300) {
      Serial.print(1);
      Serial.print(",");
    } else {
      Serial.print(0);
      Serial.print(",");
    }
  

  Serial.print(digitalRead(BUTTON_PIN0));
  Serial.print(",");
  Serial.print(digitalRead(BUTTON_PIN1));
  Serial.print(",");
  Serial.println(digitalRead(BUTTON_PIN2));


  delay(10);
}