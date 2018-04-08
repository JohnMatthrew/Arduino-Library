/*
  Measuring Current Using ACS712
*/
#include<Wire.h>
//全局变量设定(电压计)
double val0;
double val1;
double val2;
double val3;
double val4;
double val5;
double val6;
double val7;
//电平转换（电流计）
int mVperAmp = 66; //按需使用转换系数 100 给 20A 模块 ， 66 给 30A 模块 和 185 给 5A 模块
double RawValue0 = 0;
double RawValue1 = 0;
int ACSoffset = 2500;
double Voltage0 = 0;
double Voltage1 = 0;
double Amps0 = 0;
double Amps1 = 0;
//引脚定义
#define Voltage_Pin0 A2
#define Voltage_Pin1 A3
#define Voltage_Pin2 A4
#define Voltage_Pin3 A5
#define analogIn0 A0
#define analogIn1 A1

void setup() {
  pinMode(analogIn0, INPUT); //接入Analog A0 Pin
  pinMode(analogIn1, INPUT); //接入Analog A1 Pin
  Serial.begin(9600);
}

void loop() {
  Voltage_Read();
  Current_Read();
}
void Voltage_Read()
{
  //四路电压计
  double temp0;
  double temp1;
  double temp2;
  double temp3;
  val0 = analogRead(Voltage_Pin0);
  val2 = analogRead(Voltage_Pin1);
  val4 = analogRead(Voltage_Pin2);
  val6 = analogRead(Voltage_Pin3);
  temp0 = val0 / 4.092;
  temp1 = val2 / 4.092;
  temp2 = val4 / 4.092;
  temp3 = val6 / 4.092;
  val0 = temp0;
  val2 = temp1;
  val4 = temp2;
  val6 = temp3;
  val1 = (val0 / 10);
  val3 = (val2 / 10);
  val5 = (val4 / 10);
  val7 = (val6 / 10);
  Serial.println("Voltage0:");
  Serial.println(val1);
  Serial.print("V");
  Serial.println("Voltage1:");
  Serial.println(val3);
  Serial.print("V");
  Serial.println("Voltage2:");
  Serial.println(val5);
  Serial.print("V");
  Serial.println("Voltage3:");
  Serial.println(val7);
  Serial.print("V");
  delay(500);
}
void Current_Read()
{
  //双路电流计（量程30A）
  RawValue0 = analogRead(analogIn0);
  RawValue1 = analogRead(analogIn1);
  Voltage0 = (RawValue0 / 1023.0) * 5000; // 获取电平mV
  Voltage1 = (RawValue1 / 1023.0) * 5000; // 获取电平mV
  Amps0 = ((Voltage0 - ACSoffset) / mVperAmp);
  Amps0 = ((Voltage1 - ACSoffset) / mVperAmp);
  Serial.print("Raw Value = " ); // 显示测量的示数
  Serial.print(RawValue0);
  Serial.print(RawValue1);
  Serial.print("\t mV = "); // 显示电平
  Serial.print(Voltage0, 4); // 后面的“4”表示电平可以读取到显示的4位小数（10进制）
  Serial.print(Voltage1, 4); // 后面的“4”表示电平可以读取到显示的4位小数（10进制）
  Serial.print("\t Amps = "); // 最后测量计算转换结果
  Serial.println(Amps0, 4); // 后面的“4”表示电平可以读取到显示的4位小数（10进制）
  Serial.println(Amps1, 4); // 后面的“4”表示电平可以读取到显示的4位小数（10进制）
  delay(500);
}

