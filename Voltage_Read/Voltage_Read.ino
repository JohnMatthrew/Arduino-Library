/*
  Measuring Current Using ACS712
*/
#include<Wire.h>
//全局变量设定(电压计)
double      val0 ;
double      val1 ;
double      val2 ;
double      val3 ;
double      val4 ;
double      val5 ;
double      val6 ;
double      val7 ;
double      val8 ;
double      val9 ;
double      val10 ;
double      val11 ;
double      val12 ;
double      val13 ;
double      val14 ;
double      val15 ;
double      val16 ;
double      val17 ;
double      val18 ;
double      val19 ;
double      val20 ;
double      val21 ;
double      val22 ;
double      val23 ;

//电平转换（电流计）
int     mVperAmp  = 66  ; //按需使用转换系数 100 给 20A 模块 ， 66 给 30A 模块 和 185 给 5A 模块
double  RawValue0 = 0   ;
double  RawValue1 = 0   ;
int     ACSoffset = 2500;
double  Voltage0  = 0   ;
double  Voltage1  = 0   ;
double  Amps0     = 0   ;
double  Amps1     = 0   ;
//引脚定义
#define Voltage_Pin0 A0
#define Voltage_Pin1 A1
#define Voltage_Pin2 A6
#define Voltage_Pin3 A7
#define analogIn0 A2
#define analogIn1 A3

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
   val0 = analogRead(Voltage_Pin0);
  val1 = analogRead(Voltage_Pin1);
  val2 = analogRead(Voltage_Pin2);
  val3 = analogRead(Voltage_Pin3);
   val4 = analogRead(Voltage_Pin0);
  val5 = analogRead(Voltage_Pin1);
  val6 = analogRead(Voltage_Pin2);
  val7 = analogRead(Voltage_Pin3);
   val8 = analogRead(Voltage_Pin0);
  val9 = analogRead(Voltage_Pin1);
  val10 = analogRead(Voltage_Pin2);
  val11 = analogRead(Voltage_Pin3);
   val12 = analogRead(Voltage_Pin0);
  val13 = analogRead(Voltage_Pin1);
  val14 = analogRead(Voltage_Pin2);
  val15 = analogRead(Voltage_Pin3);
   val16 = analogRead(Voltage_Pin0);
  val17 = analogRead(Voltage_Pin1);
  val18 = analogRead(Voltage_Pin2);
  val19 = analogRead(Voltage_Pin3);
  val20 = ((val0 +val4+val8+val12+val16)/ 233.2155);
  val21 = ((val1+val5+val9+val13+val17) / 233.2155);
  val22 = ((val2 +val6+val10+val14+val18)/ 233.2155);
  val23 = ((val3 +val7+val11+val15+val19)/ 233.2155);

  Serial.println("Voltage0:");
  Serial.println(val20);
  Serial.print("V");
  Serial.println("Voltage1:");
  Serial.println(val21);
  Serial.print("V");
  Serial.println("Voltage2:");
  Serial.println(val22);
  Serial.print("V");
  Serial.println("Voltage3:");
  Serial.println(val23);
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

