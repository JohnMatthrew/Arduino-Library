int redPin = 6;
int greenPin = 5;
int bluePin = 3;

void setup(){
     pinMode(redPin, OUTPUT);
     pinMode(greenPin, OUTPUT);
     pinMode(bluePin, OUTPUT);
}

void loop(){
      //R:0-255 G:0-255 B:0-255
      colorRGB(random(0,255),random(0,255),random(0,255));  
      delay(5500);
}

void colorRGB(int red, int green, int blue){
      analogWrite(redPin,constrain(red,0,255));
      analogWrite(greenPin,constrain(green,0,255));
      analogWrite(bluePin,constrain(blue,0,255));
}
