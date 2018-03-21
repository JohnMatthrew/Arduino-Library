/*
 * -------------------------------
 * |Producer 小明明              |
 * |蜂鸣器小玩法程序             |
 * |如何让蜂鸣器唱歌，变调?      |
 * --------------------------------
 */
int  tonepin=6;//设置控制蜂鸣器的数字6脚
    void setup()
    {
      pinMode(tonepin,OUTPUT);//设置数字IO脚模式，OUTPUT为输出
    }
    void loop()
    {
      unsigned char i,j;
      while(1)
      {
        for(i=10;i<=53;i++)//输出一个频率的声音
        {
          digitalWrite(tonepin,HIGH);//发声音
          delay(100);//延时1ms
          digitalWrite(tonepin,LOW);//不发声音
          delay(2000);//延时ms
        }
        for(i=30;i<=70;i++)//输出另一个频率的声音,这里的100与前面的80一样，用来控制频率，可以自己调节
        {
          digitalWrite(tonepin,HIGH);
          delay(200);
          digitalWrite(tonepin,LOW);
          delay(2000);
          for(i=50;i<=56;i++)//输出另一个频率的声音,这里的100与前面的80一样，用来控制频率，可以自己调节
        {
          digitalWrite(tonepin,HIGH);
          delay(30);
          digitalWrite(tonepin,LOW);
          delay(2000);
        }
      }
    }
    }
