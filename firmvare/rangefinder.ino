#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int trigPin = 7;
const int echoPin = 6;

void setup() {
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  float distance_mm = duration * 0.034 / 2;
  float distance_in = distance_mm * 0.03937;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance (mm):");
  lcd.setCursor(0, 1);
  lcd.print(distance_mm);

  delay(2000);

}
