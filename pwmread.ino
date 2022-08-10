#include "PWM.hpp"
#include <Servo.h>

Servo myservo;

PWM my_pwm(2); // Setup pin 2 for PWM
int servostatus = 0;
void setup() {
     //Serial.begin(115200); // Serial for debug
  my_pwm.begin(true); // PWM on pin 2 reading PWM HIGH duration
  myservo.attach(9);
}

void loop() {
     // Serial.print("Value: ");
     // Serial.println(my_pwm.getValue());
  //delay(100);

  if (my_pwm.getValue() > 2000 && servostatus == 0) {
    for (int i = 88; i <= 140; i++) {
      myservo.write(i);
      // Serial.println(i);
      delay(8);
    }
    servostatus = 1;
  }

  if (my_pwm.getValue() < 2000 && servostatus == 1) {
    for (int i = 140; i >= 88; i--) {
      myservo.write(i);
      // Serial.println(i);
      delay(8);
      
    }
    servostatus = 0;

  }
}
