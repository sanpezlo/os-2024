#include <LiquidCrystal.h>

#define REGISTER_SELECT 12
#define ENABLE 11
#define DB4 5
#define DB5 4
#define DB6 3
#define DB7 2

#define LED_RED 13
#define DC_MOTOR 10
#define TMP_SENSOR A0

int seconds = 0;

LiquidCrystal lcd_1(REGISTER_SELECT, ENABLE, DB4, DB5, DB6, DB7);

void setup()
{
    pinMode(LED_RED, OUTPUT);
    pinMode(DC_MOTOR, OUTPUT);

    lcd_1.begin(16, 3);
    lcd_1.print("hello world!");

    Serial.begin(9600);
}

void loop()
{
    float tmp = analogRead(TMP_SENSOR) * 0.48828125 - 50;

    digitalWrite(DC_MOTOR, LOW);
    digitalWrite(LED_RED, LOW);

    lcd_1.setCursor(0, 1);
    lcd_1.print(seconds);
    lcd_1.print(" ");
    lcd_1.print(tmp);
    lcd_1.print("C   ");
    seconds += 1;

    if (tmp <= 10)
    {
        digitalWrite(LED_RED, HIGH);
        delay(500);
        digitalWrite(LED_RED, LOW);
        delay(500);
        return;
    }
    else if (tmp >= 26)
    {
        digitalWrite(LED_RED, HIGH);
        digitalWrite(DC_MOTOR, HIGH);
    }
    delay(1000);
}