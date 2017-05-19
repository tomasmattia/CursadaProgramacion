#include<LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int lcd_key= 0;
int adc_key_in=0;
#define btnRIGHT 0
#define btnUP 1
#define btnDOWN 2
#define btnLEFT 3
#define btnSELECT 4
#define btnNONE 5

void setup() {
  lcd.begin(16, 2);
}
void loop() {
  lcd.setCursor(9, 1);
  lcd.print(millis() / 1000);
  lcd.setCursor(0,0);
  lcd.print("Boton: ");
  lcd.setCursor(8, 0);
  lcd.print(lcd_key);
  lcd.setCursor(0, 1);
  
  lcd_key = read_LCD_buttons();
  if ( lcd_key == btnRIGHT)
    lcd.print("RIGHT ");
  else if ( lcd_key == btnLEFT )
    lcd.print("LEFT   ");
  else if ( lcd_key == btnUP)
    lcd.print("UP    ");
  else if ( lcd_key == btnDOWN)
    lcd.print("DOWN  ");
  else if ( lcd_key == btnSELECT)
    lcd.print("SELECT");
  else if ( lcd_key == btnNONE)
    lcd.print("NONE  ");
    }
int read_LCD_buttons()
{ adc_key_in = analogRead(0);

if (adc_key_in > 1023) return btnNONE; // Ningun boton pulsado
if (adc_key_in < 50) return btnRIGHT;
if (adc_key_in < 250) return btnUP;
if (adc_key_in < 300) return btnDOWN;
if (adc_key_in < 450) return btnLEFT;
if (adc_key_in < 650) return btnSELECT;
  return btnNONE;
}
