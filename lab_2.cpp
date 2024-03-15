#define LED_RED		13
#define DC_MOTOR	12
#define TMP_SENSOR	A0

void setup()
{
  pinMode(LED_RED, OUTPUT);
  pinMode(DC_MOTOR, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  float tmp = analogRead(TMP_SENSOR) * 0.48828125 - 50;
  
  digitalWrite(DC_MOTOR, LOW);
  digitalWrite(LED_RED, LOW);
  
  if (tmp < 5) {
    digitalWrite(LED_RED, HIGH);
    delay(500);
    digitalWrite(LED_RED, LOW);
    delay(500);
  } else if (tmp > 25) {
    digitalWrite(LED_RED, HIGH);
    digitalWrite(DC_MOTOR, HIGH);
  }
}