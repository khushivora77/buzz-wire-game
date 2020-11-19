// when circuit wire (D2) send LOW, turn RED LED and BUZZER ON
// green -- D5 
// red -- D8 
// buzzer -- D6 
// the game is played for 6 pts.

int c = 0;

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
Serial.begin(9600);
pinMode(2, INPUT_PULLUP);
pinMode(5,OUTPUT);
pinMode(8,OUTPUT);
pinMode(6,OUTPUT);
lcd.init();
lcd.backlight();
}

void loop() {
lcd.setCursor(0,0);
lcd.print("GAME START");
delay(1000);
lcd.clear();
Serial.println(digitalRead(2));
digitalWrite(5,HIGH);
while (c<7)
{
Serial.println(c);
if ((digitalRead(2)) == LOW )
{
lcd.print(c);
c++;
digitalWrite(5,LOW);
digitalWrite(8,HIGH);
digitalWrite(6,HIGH);
delay(1000);
lcd.clear();
}
if ((digitalRead(2)) == HIGH )
{
digitalWrite(5,HIGH);
digitalWrite(8,LOW);
digitalWrite(6,LOW);
}
}

lcd.print("GAME OVER");
delay(2000);
c=0;
lcd.clear();
}
