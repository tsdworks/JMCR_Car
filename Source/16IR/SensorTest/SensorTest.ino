void setup()
{
	pinMode(2, OUTPUT);
	for (int i = 3; i <= 10; i++)
		pinMode(i, INPUT);
	Serial.begin(115200);
}

void loop()
{
	digitalWrite(2, 0);
	delay(2);
	for (int i = 10 ; i >= 3; i--)
		Serial.print(digitalRead(i));
	digitalWrite(2, 1);
	delay(2);
	for (int i = 10 ; i >= 3; i--)
		Serial.print(digitalRead(i));
	Serial.print("\n");
	delay(1000);
}
