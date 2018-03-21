int Data=0;
int DI = 12;
int RW = 11;
int DB[] = {3, 4, 5, 6, 7, 8, 9, 10};//使用数组来定义总线需要的管脚
int Enable = 2;
int a0,a1;
int pj1,pj2;
void LcdCommandWrite(int value) {
  // 定义所有引脚
  int i = 0;
  for (i = DB[0]; i <= DI; i++) //总线赋值
  {
    digitalWrite(i, value & 01); //因为1602液晶信号识别是D7-D0(不是D0-D7)，这里是用来反转信号。
    value >>= 1;
  }
  digitalWrite(Enable, LOW);
  delayMicroseconds(1);
  digitalWrite(Enable, HIGH);
  delayMicroseconds(1);// 延时1ms
  digitalWrite(Enable, LOW);
  delayMicroseconds(1);// 延时1ms
}
void LcdDataWrite(int value) {
  // 定义所有引脚
  int i = 0;
  digitalWrite(DI, HIGH);
  digitalWrite(RW, LOW);
  for (i = DB[0]; i <= DB[7]; i++) {
    digitalWrite(i, value & 01);
    value >>= 1;
  }
  digitalWrite(Enable, LOW);
  delayMicroseconds(1);
  digitalWrite(Enable, HIGH);
  delayMicroseconds(1);
  digitalWrite(Enable, LOW);
  delayMicroseconds(1);// 延时1ms
}

void setup (void) {
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  int i = 0;
  for (i = Enable; i <= DI; i++) {
    pinMode(i, OUTPUT);
  }
  delay(100);
  // 短暂的停顿后初始化LCD
  // 用于LCD控制需要
  LcdCommandWrite(0x38);// 设置为8-bit接口，2行显示，5x7文字大小                     
  delay(64);
  LcdCommandWrite(0x38);// 设置为8-bit接口，2行显示，5x7文字大小                        
  delay(50);
  LcdCommandWrite(0x38);// 设置为8-bit接口，2行显示，5x7文字大小                        
  delay(20);
  LcdCommandWrite(0x06);// 输入方式设定
// 自动增量，没有显示移位
  delay(20);
  LcdCommandWrite(0x0E);// 显示设置
  // 开启显示屏，光标显示，无闪烁
  delay(20);
LcdCommandWrite(0x01);// 屏幕清空，光标位置归零
delay(20);
LcdCommandWrite(0x80);// 显示设置
  // 开启显示屏，光标显示，无闪烁
delay(20);

Serial.begin(9600);

}
void loop (void) {
  a0=analogRead(A0);
  a1=analogRead(A1);
  Serial.print(a0);
  Serial.print(' ');
  Serial.println(a1);
  delay(0);
  if(Serial)
  if(Serial.read()>0)
{
  Data=Serial.read();
  Serial.print("OK");
  Serial.println(Data);
}

 LcdCommandWrite(0x01); // 屏幕清空，光标位置归零
  delay(100);
  LcdCommandWrite(0x80);
delay(100);
  // 写入信息
  LcdDataWrite('T');
  LcdDataWrite('e');
  LcdDataWrite('m');
  LcdDataWrite('p');
  LcdDataWrite('e');
  LcdDataWrite('r');
  LcdDataWrite('a');
  LcdDataWrite('t');
  LcdDataWrite('u');
  LcdDataWrite('r');
  LcdDataWrite('e');
  LcdDataWrite(' ');
  LcdDataWrite('a');
  LcdDataWrite('n');
  LcdDataWrite('d');
  delay(500);
  LcdCommandWrite(0xc0);// 定义光标位置为第二行第二个位置
  delay(1000);
  LcdDataWrite('H');
  LcdDataWrite('u');
  LcdDataWrite('m');
  LcdDataWrite('i');
  LcdDataWrite('d');
  LcdDataWrite(' ');
  LcdDataWrite('w');
  LcdDataWrite('i');
  LcdDataWrite('l');
  LcdDataWrite('l');
  delay(1000);
LcdCommandWrite(0x01);// 屏幕清空，光标位置归零  
  delay(1000);
  LcdDataWrite('S');
  LcdDataWrite('h');
  LcdDataWrite('o');
  LcdDataWrite('w');
  LcdDataWrite(' ');
  LcdDataWrite('i');
  LcdDataWrite('n');
  LcdDataWrite(' ');
  LcdDataWrite('h');
  LcdDataWrite('e');
  LcdDataWrite('r');
  LcdDataWrite('e');
  LcdDataWrite(' ');
  delay(1000);
  LcdCommandWrite(0x02); //设置模式为新文字替换老文字，无新文字的地方显示不变。
  delay(1000);
    LcdDataWrite('T');
  LcdDataWrite('e');
  LcdDataWrite('m');
  LcdDataWrite('p');
  LcdDataWrite(' ');
  LcdDataWrite('a');
  LcdDataWrite('n');
  LcdDataWrite('d');
  LcdDataWrite(' ');
  LcdDataWrite('H');
  LcdDataWrite('u');
  LcdDataWrite('m');
  LcdDataWrite('i');
  LcdDataWrite('d');
  LcdDataWrite(':');
  delay(1000);
  LcdCommandWrite(0xc0);// 定义光标位置为第二行第二个位置
  delay(1000);
  LcdDataWrite(Data); 
  delay(1000);
  LcdCommandWrite(0x80); //定义光标位置为第一行第六个位置
delay(500);
 
}
