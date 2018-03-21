int B = 3;
int G = 5;
int R = 6;
void setup() {
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);
}
void loop() {
  for(double r=0.125;r<=1.0;r+=0.125)
  for(double g=0.125;g<=1.0;g+=0.125)
  for(double b=0.125;b<=1.0;b+=0.125)
  {
    double k1=g/r;
    double k2=b/r;
    for(double n=1.0;n<=255.0;n+=1.0)
    {
    
    }
  }
}
