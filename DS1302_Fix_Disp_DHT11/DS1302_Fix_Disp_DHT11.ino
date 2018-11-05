#include <DS1302.h>
#include <stdio.h>
//加上你的时钟RTC的头文件（也就是驱动）
#include "U8glib.h"
//u8g显示驱动
#include "DHT.h"
/*
   DS1302时钟显示程序
   Producer：小明明
   该程序用于修正DS1302类的RTC时钟模块，之后显示到外置显示屏上~
   拓展功能：DHT11温湿度显示在12864上
   同样适用于时间日期跑偏的情况，可以进来矫正一下
   制作时间：2018/11/5/ 12：55
   如何知道自己的时钟芯片信息呢？
   可以去www.alldatasheet.com去查找哦~
   比如DS1302的：
   http://datasheets.maximintegrated.com/en/ds/DS1302.pdf
   附上一个通用库，可以自己移植~
   也在Github里面，可以直接克隆，找你的文件夹就有了！
   https://github.com/msparks/arduino-ds1302
*/
#define DHTPIN 13// 接入13脚
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
//我用的是ST7920主控的显示屏12864
U8GLIB_ST7920_128X64_4X u8g(10, 11, 12); // SPI Com: SCK = en = 10, MOSI = rw = 11, CS = di = 12
//格式统一并打印
namespace {
const int kCePin   = 7;  // 芯片使能脚 CE
const int kIoPin   = 8;  // 输入口 I/O
const int kSclkPin = 9;  // 串行时钟口 SCLK
// 调库使用按照上面配置I/O口
DS1302 rtc(kCePin, kIoPin, kSclkPin);
//下面是规整星期信息输出。
String dayAsString(const Time::Day day) {
  switch (day) {
    case Time::kSunday: return "Sunday";
    case Time::kMonday: return "Monday";
    case Time::kTuesday: return "Tuesday";
    case Time::kWednesday: return "Wednesday";
    case Time::kThursday: return "Thursday";
    case Time::kFriday: return "Friday";
    case Time::kSaturday: return "Saturday";
  }
  return "(unknown day)";
}
void printTime() {
  // 从RTC读取时间
  Time t = rtc.time();
  // 命名星期几
  const String day = dayAsString(t.day);
  // 临时变量用于规整时间日期格式
  char buf[50];
  char buf1[50];
  snprintf(buf, sizeof(buf), "%s %04d-%02d-%02d",
           day.c_str(),
           t.yr, t.mon, t.date);
  snprintf(buf1, sizeof(buf1), "%02d:%02d:%02d",
           t.hr, t.min, t.sec);
  //这里是输出的格式：4位年/2位月/2位日
  // 2为时/2位分/2位秒
  // 输出字符串到串口我们才能看得到时间。
  Serial.println(buf);
  Serial.println(buf1);
  u8g.setFont(u8g_font_6x13);
  u8g.drawStr( 0, 10, buf);
  u8g.drawStr( 0, 22, buf1);
}
}
void setup() {
  //旋转屏幕180
  u8g.setRot180();
  Serial.begin(9600);//设定串口输出波特率（看协议）
  //上面一条用于串口打印
  //关闭芯片写保护(写入时间才用到)
  //rtc.writeProtect(false);
  //rtc.halt(false);
  // 开始准备写入校准时间
  // 格式：年，月，日，时，分，秒，周几
  //Time t(2018, 11, 5, 12, 50, 30, Time::kMonday);
  // 写入校准时间入RTC中
  //rtc.time(t);
  dht.begin();//初始化DHT11
}

void loop() {
  printTime();//打印时间
  temp_humid();//温湿度

  u8g.firstPage();
  do {
    printTime();
    temp_humid();
  } while (u8g.nextPage());
}
void temp_humid()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read !");
    return;
  }
  /*Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" *C ");
  */
  u8g.setFont(u8g_font_6x13);
  u8g.drawStr( 0, 32, "Humid:");
  u8g.drawStr( 0, 42, "Temp:");
  u8g.setPrintPos(40, 32);
  u8g.print(h);
  u8g.setPrintPos(40, 42);
  u8g.print(t);
  u8g.drawStr( 70, 32, "%");
  u8g.drawStr( 70, 42, "*C");
}

