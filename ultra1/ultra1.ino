int TRIG[]={1,8,9,10,11,12,13}, ECHO[]={1,2,3,4,5,6,7},dist;
int dura, sensores=1;
String cero="0";
void setup()
{
  for(int i=1;i<=sensores; i++){
    pinMode(TRIG[i], OUTPUT);
    pinMode(ECHO[i], INPUT);
    Serial.begin(9600);
  }
}
void loop()
{
  for(int i=1;i<=sensores; i++){
    digitalWrite(TRIG[i], HIGH);
    delayMicroseconds(1);
    digitalWrite(TRIG[i], LOW);
    delayMicroseconds(1); 
    if(i>9){
    cero="";
    }
    dura=pulseIn(ECHO[i], HIGH);
    dist=dura/58.2;
    String ceroo="0";
    if(dist>9){
      ceroo="";
    }
      Serial.print("US"+cero+String(i)+":"+ceroo);
    Serial.println(dist);
  }
}
