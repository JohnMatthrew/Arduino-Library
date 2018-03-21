/*
Measuring Current Using ACS712
*/
#include<Wire.h>
double val1;
double val2;
const int analogIn = A1;
int mVperAmp = 66; // use 100 for 20A Module and 66 for 30A Module and 185 for 5A Module
int RawValue= 0;
int ACSoffset = 2500; 
double Voltage = 0;
double Amps = 0;

void setup() {
  pinMode(0,OUTPUT);//接入Analog A0 Pin
  Serial.begin(9600);
  Serial.println("Voltage:");
}

void loop() {
  Voltage_Read();
  Current_Read();
}
 void Voltage_Read()
 {
  double temp;
  val1=analogRead(1);
  temp=val1/4.092;
  val1=temp;
  val2=(val1/10);
  Serial.println(val2);
  Serial.print("V");
  delay(500);
 }
 void Current_Read()
 {
  RawValue = analogRead(analogIn);
Voltage = (RawValue / 1023.0) * 5000; // Gets you mV
Amps = ((Voltage - ACSoffset) / mVperAmp);
Serial.print("Raw Value = " ); // shows pre-scaled value 
Serial.print(RawValue); 
Serial.print("\t mV = "); // shows the voltage measured 
Serial.print(Voltage,3); // the '3' after voltage allows you to display 3 digits after decimal point
Serial.print("\t Amps = "); // shows the voltage measured 
Serial.println(Amps,3); // the '3' after voltage allows you to display 3 digits after decimal point
delay(500); 
 }

