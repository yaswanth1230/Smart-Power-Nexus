#define IR_SENSOR D2
#define RELAY D1
unsigned long chargingTime = 60000;
bool charging = false;
void setup()
{
pinMode(IR_SENSOR, INPUT);
pinMode(RELAY, OUTPUT);
digitalWrite(RELAY, HIGH);
Serial.begin(9600);
}
void loop()
{
int sensorState = digitalRead(IR_SENSOR);
if(sensorState == LOW && charging == false)
{
Serial.println("Coin Detected");
charging = true;
digitalWrite(RELAY, LOW);
Serial.println("Charging ON");
delay(chargingTime);
digitalWrite(RELAY, HIGH);
Serial.println("Charging OFF");
charging = false;
delay(2000);
}
}