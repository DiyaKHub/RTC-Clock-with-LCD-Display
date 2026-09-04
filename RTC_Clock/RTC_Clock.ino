# include <Wire.h>;
# include <DS3231.h>;
#include <LiquidCrystal_I2C.h>

DS3231 clock; 
RTCDateTime dateTime;
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  Serial.begin(9600);
  clock.begin(); 

  clock.setDateTime(__DATE__, __TIME__); 

  lcd.init();
  lcd.backlight();
}

void loop() {
  dateTime = clock.getDateTime();

  /* Serial.print(dateTime.year);
  Serial.print(" - ");
  Serial.print(dateTime.month);
  Serial.print(" - ");
  Serial.print(dateTime.day);
  Serial.println();

  delay (1000); */

  lcd.setCursor(0,0); 

  lcd.print("DATE: ");
  lcd.print(dateTime.day);
  lcd.print("-");
  lcd.print(dateTime.month);
  lcd.print("-");
  lcd.print(dateTime.year);

  lcd.setCursor (0,1);

  lcd.print ("TIME: ");
  lcd.print(dateTime.hour);
  lcd.print(":");
  lcd.print(dateTime.minute);
  lcd.print(":");
  lcd.print(dateTime.second);

  delay (1000); // Helps the LCD clear before printing the next value

}
