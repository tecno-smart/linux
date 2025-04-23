#include <Servo.h> 
Servo s1;
int val = 0 ;
void setup()
{
    Serial.begin(9600); // sensor buart rate
    s1.attach(3);
    pinMode(2,INPUT);   
    pinMode(5,OUTPUT);  // led green pin
    pinMode(6,OUTPUT);  // led red pin
}
void loop() 
{
  val = digitalRead(2);  // IR sensor output pin connected
  Serial.println(val);   // see the value in serial mpnitor in Arduino IDE
  delay(1);
  
  if(val == 1 )
  {
    digitalWrite(5,HIGH);  // LED ON
    digitalWrite(6,LOW);   // LED OFF
    s1.write(90);
    delay(2000);
  
  }
  else
  {
    digitalWrite(5,LOW);   // LED OFF
    digitalWrite(6,HIGH);  // LED ON
    s1.write(0);
   
  }
  }