/*
 * ----------------------------------------------
 * | Producer 小明明                            |
 * |电磁继电器驱动程序，最多可以12路控制继电器  |
 * |只需要普通数字口即可，PWM口也可以充当驱动口 |
 * |高低电平即可，未经过A口测试，可尝试用Analog |
 * ----------------------------------------------
 */
#define Pin_0 2
#define Pin_1 3
#define Pin_2 4
#define Pin_3 5
#define Pin_4 6
#define Pin_5 7
#define Pin_6 8
#define Pin_7 9
#define Pin_8 10
#define Pin_9 11
#define Pin_10 12
/*
 * #define Pin_11 0
 * #define Pin_12 A1
 * #define Pin_13 A2
 * #define Pin_14 A3
 * #define Pin_15 A4
 * #define Pin_16 A5
 */
void setup() {
  pinMode(Pin_0,OUTPUT);
  pinMode(Pin_1,OUTPUT);
  pinMode(Pin_2,OUTPUT);
  pinMode(Pin_3,OUTPUT);
  pinMode(Pin_4,OUTPUT);
  pinMode(Pin_5,OUTPUT);
  pinMode(Pin_6,OUTPUT);
  pinMode(Pin_7,OUTPUT);
  pinMode(Pin_8,OUTPUT);
  pinMode(Pin_9,OUTPUT);
  pinMode(Pin_10,OUTPUT);
  //pinMode(Pin_11,OUTPUT);
  //pinMode(Pin_12,OUTPUT);
  //pinMode(Pin_13,OUTPUT);
  //pinMode(Pin_14,OUTPUT);
  //pinMode(Pin_15,OUTPUT);
  //pinMode(Pin_16,OUTPUT);
}

void loop() {
  //你需要什么条件，我给你断开电源？
  digitalWrite(Pin_0,HIGH);
  digitalWrite(Pin_1,HIGH);
  digitalWrite(Pin_2,HIGH);
  digitalWrite(Pin_3,HIGH);
  digitalWrite(Pin_4,HIGH);
  digitalWrite(Pin_5,HIGH);
  digitalWrite(Pin_6,HIGH);
  digitalWrite(Pin_7,HIGH);
  digitalWrite(Pin_8,HIGH);
  digitalWrite(Pin_9,HIGH);
  digitalWrite(Pin_10,HIGH);
  //digitalWrite(Pin_11,HIGH);
  //digitalWrite(Pin_12,HIGH);
  //digitalWrite(Pin_13,HIGH);
  //digitalWrite(Pin_14,HIGH);
  //digitalWrite(Pin_15,HIGH);
  //digitalWrite(Pin_16,HIGH);
  delay(1000);
  digitalWrite(Pin_0,LOW);
  digitalWrite(Pin_1,LOW);
  digitalWrite(Pin_2,LOW);
  digitalWrite(Pin_3,LOW);
  digitalWrite(Pin_4,LOW);
  digitalWrite(Pin_5,LOW);
  digitalWrite(Pin_6,LOW);
  digitalWrite(Pin_7,LOW);
  digitalWrite(Pin_8,LOW);
  digitalWrite(Pin_9,LOW);
  digitalWrite(Pin_10,LOW);
  //digitalWrite(Pin_11,LOW);
  //digitalWrite(Pin_12,LOW);
  //digitalWrite(Pin_13,LOW);
  //digitalWrite(Pin_14,LOW);
  //digitalWrite(Pin_15,LOW);
  //digitalWrite(Pin_16,LOW);
  delay(1000);
}
