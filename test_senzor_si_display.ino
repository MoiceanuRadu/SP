#include <LiquidCrystal.h>


LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int sensorPin = A1;
int sensorValue = 0;

void setup() {
pinMode(sensorPin, INPUT);
lcd.begin(16, 2);
lcd.print("Cal.aer:");
lcd.setCursor(0, 1);
lcd.print("Indice:");
}

void loop() {
lcd.setCursor(15, 1);
lcd.print(" ");
delay(1000);
sensorValue = analogRead(sensorPin);
lcd.setCursor(8, 1);
lcd.print("     ");
lcd.setCursor(8, 1);
lcd.print(sensorValue);
lcd.setCursor(9, 0);

if (sensorValue < 40) lcd.print("F.Buna ");
if ((sensorValue >= 40) and (sensorValue < 70)) lcd.print("Buna   ");
if ((sensorValue >= 70) and (sensorValue < 100)) lcd.print("Medie  ");
if ((sensorValue >= 100) and (sensorValue < 300)) lcd.print("Viciat ");
if ((sensorValue >= 300) and (sensorValue < 500)) lcd.print("Toxic  ");
if (sensorValue >= 500) lcd.print("Pericol");

lcd.setCursor(15, 1);
lcd.print("*");
delay(1000);
}
