/*电机驱动模块程序~
 * 程序Producer 小明明
 * 本块为我亲手写的程序说明，请按照我的方法使用程序！
 * 该程序用于驱动电机驱动TB6612芯片，本程序定义接线方式按下方接入！
 * 提醒：电机1接在A1和A2口上，如果有电机2，将他接在B1和B2口上！
 * ---------------------  ---------------------
 * |TB6612驱动芯片引脚  |  Arduino UNO的IO口  | 
 * ---------------------  ---------------------
 * |         VM         |     请接到外部供电  |
 * |         VCC        |          5V         |
 * |         GND        |          GND        |
 * |         A1         |       请接电机      |
 * |         A2         |       请接电机      |
 * |         B1         |       请接电机      |
 * |         B2         |       请接电机      |
 * |         GND        |          GND        |
 * |         PWMA       |           3~        |
 * |         AIN2       |           8         |
 * |         AIN1       |           9~        |
 * |         STBY       |           10~       |
 * |         BIN1       |           11~       |
 * |         BIN2       |           12        |
 * |         PWMB       |           5~        |
 * |         GND        |           GND       |
 * ---------------------  ---------------------
 *  A控制信号输入------PWMA                 VM ------电机驱动电压输入端（4.5V-15V）
   A电机输入端2 ------AIN2                VCC ------逻辑电平输入端（2.7V-5.5V）
   A电机输入端1 ------AIN1                GND ------ 接地
    正常工作/待机状态控制端------STBY          AO1 ------- A电机输出端1
   B电机输入端1------BIN1                 AO2 ------ A电机输出端2
   B电机输入端2------BIN2                 BO2 ------ B电机输出端2
   B控制信号输入端------PWMB               BO1 ------ B电机输出端1
         接地------GND                GND ------- 接地
 */

int STBY=10;//待机脚
//电机A
int PWMA = 3;
int AIN1 = 9;
int AIN2 = 8;
//电机B
int PWMB = 5;
int BIN1 = 11;
int BIN2 = 12;
void setup() {
  //设定输出脚的功能
  pinMode(STBY,OUTPUT);
  //电机
  pinMode(PWMA,OUTPUT);
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  //电机B
  pinMode(PWMB,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);

}

void loop() {
  //让电机转起来
   move(1,255,1);//电机A，全速转（速度范围0~255），（逆时针为1）左转
   move(2,255,1);//电机B，全速转（速度范围0~255），（逆时针为1）左转
   delay(1000);//转1秒
   stop();//停车
   delay(250);//停车0.25秒
   move(1,128,0);//电机A，半速转，（顺时针为0）右转
   move(2,128,0);//电机B，半速转，（顺时针为0）右转
   delay(1000);//转1秒
   stop();//停车
   delay(250);//停车0.25秒
}
 void move(int motor,int speed,int direction){
  //子函数move的定义
  //电机A为1，电机B为2
  //速度等级，0~255，0停车，255为满速
  //方向，0为顺时针，1为逆时针
  digitalWrite(STBY,HIGH);//挂出空档
  //下面用到布尔值的定义
  boolean Pin1=LOW;
  boolean Pin2=HIGH;
  if(direction == 1)
  {
    Pin1=HIGH;
    Pin2=LOW;
  }
  if(motor == 1)
  {
    digitalWrite(AIN1,Pin1);
    digitalWrite(AIN2,Pin2);
    analogWrite(PWMA,speed);
  }else{
    digitalWrite(BIN1,Pin1);
    digitalWrite(BIN2,Pin2);
    analogWrite(PWMB,speed);
  }
 }
 void stop()
 {
  digitalWrite(STBY,LOW);//挂空挡
 }

