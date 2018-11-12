#include <DS1302.h>

/*
 * Producer:小明明
 * 该程序用于修正DS1302类的RTC时钟模块
 * 如果时间日期跑偏了，可以来这里矫正一下
 * 制作时间：2018/4/26/ 19：51
 */
 
#include <stdio.h>
//加上你的时钟RTC的头文件（也就是驱动）
/*
 * 如何知道自己的时钟芯片信息呢？
 * 可以去www.alldatasheet.com去查找哦~
 * 比如DS1302的：
 * http://datasheets.maximintegrated.com/en/ds/DS1302.pdf
 * 附上一个通用库，可以自己移植~
 * 也在Github里面，可以直接克隆，找你的文件夹就有了！
 * https://github.com/msparks/arduino-ds1302
 */

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
  snprintf(buf, sizeof(buf), "%s %04d-%02d-%02d %02d:%02d:%02d",
           day.c_str(),
           t.yr, t.mon, t.date,
           t.hr, t.min, t.sec);
//这里是输出的格式：4位年/2位月/2位日
                // 2为时/2位分/2位秒
  // 输出字符串到串口我们才能看得到时间。
  Serial.println(buf);
}
}
void setup() {
  Serial.begin(9600);//设定串口输出波特率（看协议）
  //关闭芯片写保护
  rtc.writeProtect(false);
  rtc.halt(false);

  // 开始准备写入校准时间
  // 格式：年，月，日，时，分，秒，周几
  Time t(2018, 11, 5, 12, 50, 30, Time::kMonday);

  // 写入校准时间入RTC中
  rtc.time(t);
}
void loop() {
  printTime();//打印时间
  delay(1000);//每秒刷新一次

}
