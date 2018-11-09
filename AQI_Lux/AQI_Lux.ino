/*
   室内空气质量+光线光强测定程序
   Producer:小明明
   本套装备包含设备：
   1、Sharp GP2Y1010AU（PM2.5粉尘传感探头）
   2、气体检测探头MQ135
   3、光强计探头GY-8511
   接口附录:
    ——————————————————————
   |  sharp GP2Y1010AU |     Arduino  UNO      |
    ——————————————————————
   |        LED        |          D5           |
   |        V0         |          A0           |
    ——————————————————————
   |       MQ135       |     Arduino  UNO      |
    ——————————————————————
   |        D0         |          D6           |
   |        A0         |          A2           |
    ——————————————————————
   |       MP8511      |      Arduino  UNO     |
    ——————————————————————
   |     供电3.3V！    |          3.3V         |
   |         A0        |           A2          |
   |        Aref       |           A3          |
    ——————————————————————
   之后下面为程序正文：
*/
//定义硬件的引脚
#define UVOUT A1//光强计输出
#define REF_3V3 A3//参考电压
#include "MQ135.h"
#define Gaspin A2
#define dustpin A0
#define ledpower 5
float dustVal=0;
MQ135 gasSensor = MQ135(Gaspin);
void setup() {
  Serial.begin(9600);
  pinMode(UVOUT, INPUT);
  pinMode(REF_3V3, INPUT);
  pinMode(ledpower,OUTPUT);
  pinMode(dustpin,INPUT);
}

void loop() {
  dust();
  UV_lux();
  Gas();
}
void dust()
{
  digitalWrite(ledpower,LOW);
  delayMicroseconds(280);
  dustVal=analogRead(dustpin);
  delayMicroseconds(40);
  digitalWrite(ledpower,HIGH);
  delayMicroseconds(9680);
  delay(1000);
  if(dustVal>36.455)
  {
    Serial.print("Dust");
    Serial.println(float(dustVal/1024)-0.0356*120000*0.035);
  }
}
void Gas()
{
  float gas = gasSensor.getRZero();
  float ppm = gasSensor.getPPM();
    Serial.println(gas);
    Serial.println(ppm);
  delay(1000);
}
/*
  //MQ135主函数
  void GAS()
  {
  float volt;
  volt = getVoltage(gasSensor);
  Serial.println(volt);
  delay(1000);
  }
  //定义getVoltage子函数
  float getVoltage(int pin)
  {
  return(analogRead(pin)*0.004882814);
  }
*/
//UV光强计主函数
void UV_lux()
{
  int uvLevel = averageAnalogRead(UVOUT);
  int refLevel = averageAnalogRead(REF_3V3);
  //Use the 3.3V power pin as a reference to get a very accurate output value from sensor
  float outputVoltage = 3.3 / refLevel * uvLevel;
  float uvIntensity = mapfloat(outputVoltage, 0.99, 2.9, 0.0, 15.0);
  Serial.print("MP8511 output:");
  Serial.println(uvLevel);
  Serial.print(" MP8511 voltage:");
  Serial.println(outputVoltage);
  Serial.print(" UV Intensity (mW/cm^2): ");
  Serial.println(uvIntensity);
  delay(1000);
}

//光强计取平均值
int averageAnalogRead(int pinToRead)
{
  byte numberOfReadings = 8;
  unsigned int runningValue = 0;

  for (int x = 0 ; x < numberOfReadings ; x++)
    runningValue += analogRead(pinToRead);
  runningValue /= numberOfReadings;
  return (runningValue);
}
//floats 类型定义
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
