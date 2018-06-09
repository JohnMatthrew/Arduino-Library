/*
 * Producer:小明明
 * 如何使用锁存器类型的元件？如何节约Arduino内部的IO口？
 * 首先先来介绍一下74595一类的移位寄存器+锁存器
 * http://arduino.nxez.com/2016/12/20/74hc595-chip-principle-and-arduino-use-example.html
 *  ----------------------------
 * |  Arduino   |    74HC595    |
 *  ----------------------------
 * |  latchPin  |  锁存脚SH_CP  |
 * |  clockPin  |时钟信号脚ST_CP|
 * |  dataPin   |   送数据脚DS  |
 *  ----------------------------
 * 
  */
int latchPin = 5;
int clockPin = 4;
int dataPin = 2; //这里定义了那三个脚
void setup ()
{
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT); //让三个脚都是输出状态
}
void loop()
{
  for(int a=0; a<=256; a++)   //这个循环的意思是让a这个变量+1一直加到到256，每次循环都进行下面的活动
  {
    digitalWrite(latchPin,LOW); //将ST_CP口上面加低电平让芯片准备好接收数据
    shiftOut(dataPin,clockPin,MSBFIRST,a);
    //这个就是用MSBFIRST（数据高位优先）参数让0-7个针脚以高电平输出（同理现在是LSBFIRST 低位优先为低电平）是dataPin的参数，
     //clockPin的参数是变量a，前面我们说了这个变量会一次从1加到256，是个十进制数，
    // 输入到芯片后会产生8个二进制数，达到开关的作用
    // 8位数据分别有效为 2，4，8，16，32，64，128，256
    digitalWrite(latchPin,HIGH); //将ST_CP这个针脚恢复到高电平
    delay(1000); //暂停1秒钟让你看到效果
  }
}
