/*
Arduino UNO与HC-SR04超声波模块测试
电平触发模式
*/

const int TrigPin = 12; 
const int EchoPin = 13; 
float cm; 
void setup() 
{ 
Serial.begin(9600); 
pinMode(TrigPin, OUTPUT); 
pinMode(EchoPin, INPUT); 
} 
void loop() 
{ 
digitalWrite(TrigPin, LOW); //低高低电平发一个短时间脉冲去TrigPin 
delayMicroseconds(2); 
digitalWrite(TrigPin, HIGH); 
delayMicroseconds(10); 
digitalWrite(TrigPin, LOW); 

cm = pulseIn(EchoPin, HIGH) / 58.0; //将回波时间换算成cm 
cm = (int(cm * 100.0)) / 100.0; //保留两位小数 
Serial.print("Distance:"); 
Serial.print(cm); 
Serial.print("cm"); 
Serial.println(); 
delay(1000); 
}

