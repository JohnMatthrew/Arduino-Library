/*
 * MAX7219 8*8矩阵显示屏
 * Producer:小明明
 * 具体用途：
 * 1、可以多级相连送入数据
 * 2、可自定义内部的图案，取字模软件顺带附入。
 * 3、自行开发更多功能
 * 接线如下：
 * 本例程按照随意定义方式（可更改连接顺序）
 * D12------------------DIN
 * D11------------------CLK
 * D10------------------CS
 * 5V-------------------VCC
 * GND------------------GND
 */
#include "LedControl.h"
//下方可更改接线，依次DIN/CLK/CS
LedControl lc=LedControl(12,11,10,1);
//全局延时
unsigned long delaytime=1000;
void setup() {
  // 唤醒MAX7219
  lc.shutdown(0,false);
  //亮度设置
  lc.setIntensity(0,6);
  //清除屏幕
  lc.clearDisplay(0);

}

void loop() {
  // put your main code here, to run repeatedly:

}
