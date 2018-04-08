#include <Servo.h>
Servo myservo;
Servo myservo1;
Servo myservo2;
Servo myservo3;
int pos = 0;
#define V 90
#define P 180
void setup() {
  myservo.attach(3);//一号D3
  myservo1.attach(5);//二号D5
  myservo2.attach(6);//三号D7
  myservo3.attach(9);//四号D9
}

void loop() {
  for (pos = V; pos <= P; pos += 1)
  {
    myservo.write(pos);
    myservo1.write(pos);
    myservo2.write(pos);
    myservo3.write(pos);
    delay(15);
  }
  for (pos = P; pos >= V; pos -= 1)
  {
    myservo.write(pos);
    myservo1.write(pos);
    myservo2.write(pos);
    myservo3.write(pos);
    delay(15);
  }
}
