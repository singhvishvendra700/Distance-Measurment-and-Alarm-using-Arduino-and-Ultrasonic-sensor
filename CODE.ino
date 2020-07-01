
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int pingPin=7;
void setup() 
{
  lcd.begin(16, 2);
  lcd.clear();
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
 
  long duration,cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  
  duration = pulseIn(pingPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  
  if( (cm >=0) && (cm <20))
  {
    digitalWrite(9, HIGH);
    delay(200);
    digitalWrite(9, LOW);
  }
  if( (cm >= 20) && (cm < 40))
  {
    digitalWrite(9, HIGH);
    delay(100);
    digitalWrite(9, LOW);
  }
  if( cm >= 40 )
  {
    tone(8, 500,1000);
  }
  lcd.setCursor(0,1);
  lcd.print("Distance: ");
  lcd.print(cm);
  lcd.println(" cm");
  delay(500);
}
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
 
