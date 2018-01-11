#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int sensorPin = A1;
int sensorValue = 0;

void setup() {
pinMode(sensorPin, INPUT);
// set up the LCD's number of columns and rows:
lcd.begin(16, 2);
// Print a message to the LCD.
lcd.print("Cal.aer:");
lcd.setCursor(0, 1);
lcd.print("Indice:");
}

void loop() {
// set the cursor to column 0, line 1
// (note: line 1 is the second row, since counting begins with 0):
lcd.setCursor(15, 1);
// running blink
lcd.print(" ");
delay(1000);
sensorValue = analogRead(sensorPin);
// clear print indice value
lcd.setCursor(8, 1);
lcd.print("     ");
lcd.setCursor(8, 1);
// print the sensor value
lcd.print(sensorValue);
lcd.setCursor(9, 0);
// print calitate aer
if (sensorValue < 40) lcd.print("F.Buna ");
if ((sensorValue >= 40) and (sensorValue < 70)) lcd.print("Buna   ");
if ((sensorValue >= 70) and (sensorValue < 100)) lcd.print("Medie  ");
if ((sensorValue >= 100) and (sensorValue < 300)) lcd.print("Viciat ");
if ((sensorValue >= 300) and (sensorValue < 500)) lcd.print("Toxic  ");
if (sensorValue >= 500) lcd.print("Pericol");
lcd.setCursor(15, 1);
// running blink
lcd.print("*");
delay(1000);
}
