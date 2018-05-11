/*
 * 
 * 程序Producer:小明明
 * 示例程序，测量电压
 * 按照我的笔记和思路
 * 乖乖搭出电路，不要拿洞洞板
 * 不要作死接大电流，大电压
 *
 */
 
 //请在下方填入你自己弄好的电阻阻值
double R1 = 0.00;
double R2 = 0.00;


void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);//设定波特率

}

void loop() {
  double sensorValue = analogRead(A0);
  double voltage = (sensorValue * 5.00)/1023.00;
  voltage = voltage/(R2/(R1+R2));
  Serial.print("电压值");
  Serial.println(voltage);
  delay(500);

}
