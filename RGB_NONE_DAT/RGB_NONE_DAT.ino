#define R 11
#define G 10
#define B 9
void setup() {
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);

}

void loop() {
  White();
  delay(1000);

}
void White()
{
  digitalWrite(R,255);
  digitalWrite(G,255);
  digitalWrite(B,255);  
}


