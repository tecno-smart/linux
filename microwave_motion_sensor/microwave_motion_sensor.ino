int val = 0 ;
void setup()
{
Serial.begin(9600);     // sensor buart rate
pinMode(2,INPUT);       // RCWL MicroWave sensor output pin connected to D2
pinMode(7,OUTPUT);      //  led pin
pinMode(10,OUTPUT);     //  Relay PIN

digitalWrite(10,HIGH);  // Relay Normaly OFF

}
void loop() 
{
val = digitalRead(2); // RCWL MicroWave output pin connected
Serial.println(val);  // see the value in serial monitor in Arduino IDE
delay(100);
 
if(val == 1 )
{
digitalWrite(7,HIGH);   // LED ON
digitalWrite(10,LOW);   // Relay ON 

}
else
{
digitalWrite(7,LOW);    // LED OFF
digitalWrite(10,HIGH);  // Relay OFF 
}
}