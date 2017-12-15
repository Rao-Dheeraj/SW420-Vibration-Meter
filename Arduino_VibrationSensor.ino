//Dheeraj Yadav TeaM Audacious 3.0

/* Vibration sensor connected to Arduino pins as follows:
 Arduino            Vibration Sensor
   D9                    DOut
   GND                   GND
   +5V                   VCC     
   
   D13                Indication LED   
*/
#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3 , 2);

int ledPin = 13;
int EP =9;

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(EP, INPUT); //set EP input for measurment
  Serial.begin(9600); //init serial 9600
  Serial.println("----------------------Vibration-Team Audacious3.0------------------------");


lcd.begin(16,2);
lcd.print("TeamAudacious3.0");
lcd.setCursor(0,1);
lcd.print("Vibration:");

digitalWrite(A4, HIGH);
digitalWrite(A3, HIGH);



}
void loop(){
  long a=0;
  for (int q=0;q<10;q++)
  {

    long measurement =TP_init();
  delay(50);
  Serial.print("measurment = ");
  Serial.println(measurement);
  if (measurement > 1000){
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW); 
  }
    
     
   a=a+measurement;
   delay(100);
  }
long average=a/10;
Serial.print("average = ");
Serial.println(average);  

lcd.setCursor(10,1);
lcd.print(average);

}


long TP_init(){
  delay(100);
  long measurement=pulseIn (EP, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement;
}
