 // https://github.com/Arduino-IRremote/Arduino-IRremote  
 #include <IRremote.h> 
 #include "LiquidCrystal.h"
 LiquidCrystal lcd(8,7,6,5,4,3); 
 int val1=0; // Inializing the variable for storing the last status of Relay_pins  
 int val2=0;  
 int val3=0;  
 int val4=0;  
 int RECV_PIN = 12;  
 int Data ;  
 IRrecv irrecv(RECV_PIN);  
 decode_results results;  
 void setup()  
 {  
  Serial.begin(9600);  
  lcd.begin(16,2);
  
  // In case the interrupt driver crashes on setup, give a clue  
  // to the user what's going on.  
  Serial.println("Enabling IRin");  
  irrecv.enableIRIn(); // Start the receiver  
  Serial.println("Enabled IRin");  
  pinMode(11,OUTPUT); // LED 1   
  pinMode(10,OUTPUT); // LED 2   
  pinMode(9,OUTPUT);  // LED 3  
    lcd.setCursor(0,0);
   lcd.print(" Remote Control    ");
   lcd.setCursor(0,1);
   lcd.print("   Automation   ");
   delay(5000);
    lcd.clear();
   
 }  
 void loop() {  
  if (irrecv.decode(&results))   
  {   
   Data = results.value, HEX ;  
   Serial.println(Data);
   lcd.setCursor(0,0);
   lcd.print(Data);  
   irrecv.resume(); // Receive the next value  
   if(Data==18615)  
   {  
    val1=digitalRead(11);  
    if(val1==0)  
    {  
     digitalWrite(11,HIGH);  
     val1=1;  
     lcd.setCursor(7,0);
     lcd.print("Led 1 ON     ");
     delay(500);  
    }  
    else  
    {  
    digitalWrite(11,LOW);  
    val1=0;  
     lcd.setCursor(7,0);
     lcd.print("Led 1 OFF     ");
    delay(100);  
    }  
   }  
   if(Data==22695)  
   {  
    val2=digitalRead(10);  
    if(val2==0)  
    {  
     digitalWrite(10,HIGH);  
     val2=1;  
     lcd.setCursor(0,1);
     lcd.print("L 2 ON ");
     delay(500);  
    }  
    else  
    {  
    digitalWrite(10,LOW);  
    val2=0;  
     lcd.setCursor(0,1);
     lcd.print("L 2 OFF");
    delay(100);  
    }  
   }  
   if(Data==2295)  
   {  
    val3=digitalRead(9);  
    if(val3==0)  
    {  
     digitalWrite(9,HIGH);  
     val3=1;  
     lcd.setCursor(7,1);
     lcd.print("L 3 ON ");
     delay(500);  
    }  
    else  
    {  
    digitalWrite(9,LOW);  
    val3=0;  
     lcd.setCursor(7,1);
     lcd.print("L 3 OF");
    delay(100);  
    }  
   }
  }
   delay(100);
 }