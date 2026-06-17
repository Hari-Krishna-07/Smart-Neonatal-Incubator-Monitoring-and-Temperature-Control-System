#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

int potPin = A0;
int fanPin = 8;
int buzzerPin = 9;

void setup()
{
  lcd.begin(16,2);

  pinMode(fanPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(potPin);

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("ADC:");
  lcd.print(sensorValue);

  if(sensorValue < 300)
  {
    digitalWrite(fanPin, LOW);
    digitalWrite(buzzerPin, LOW);

    lcd.setCursor(0,1);
    lcd.print("NORMAL");
  }
  else if(sensorValue < 700)
  {
    digitalWrite(fanPin, HIGH);
    digitalWrite(buzzerPin, LOW);

    lcd.setCursor(0,1);
    lcd.print("FAN ON");
  }
  else
  {
    digitalWrite(fanPin, HIGH);
    digitalWrite(buzzerPin, HIGH);

    lcd.setCursor(0,1);
    lcd.print("DANGER!");
  }

  Serial.print("Pot Value: ");
  Serial.println(sensorValue);

  delay(500);
}
