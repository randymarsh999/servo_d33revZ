/*
 Name:		servo_d33rev.ino
 Created:	06.06.2018 15:02:22
 Author:	root
*/

int servoPin = 9;            // порт подключения сервы
int KeyPin = 8;
int temp = 1;
int outVal = 0;

//переменные для угла поворота
int myAngle;                 // rotate angle
int pulseWidth;              // длительность импульса

//Rotate angle for servo motor
float Step = 5.0F / 1024; // Вычисляем шаг Uопорн / на градацию 

void servoPulse(int servoPin, int myAngle)
{
	pulseWidth = (myAngle * 11) + 500;  // конвертируем угол в микросекунды
	digitalWrite(servoPin, HIGH);       // устанавливаем серве высокий уровень
	delayMicroseconds(pulseWidth);      // ждём
	digitalWrite(servoPin, LOW);        // устанавливаем низкий уровень
	delay(20);
}

//точка входа в программу основные настройки
void setup()
{
	// put your setup code here, to run once:
	pinMode(servoPin, OUTPUT);          // конфигурируем пин сервы, как выход
	Serial.begin(9600);	//set speed Com port
	pinMode(A5, INPUT);	//set port A5 as input
}

void loop() {
	//String cmd="";
	//String cmdA = "";
	////чтение строки данных из Com порта
	//char inString[15];
	//int i = 0;
	//while (Serial.available()>0) {
	//	delay(1);
	//	inString[i] = Serial.read();
	//	if (inString[i] == '_') {
	//		cmd = inString;
	//		//Serial.println(inString);
	//	}
	//	i++;
	//}
	//if (cmd!="")
	//{
	//	Serial.println(cmd);
	//}
	//cmdA = cmd.substring(1, 3);

	//Измерение с вывода А5 и вывод данных в COM порт 
	
	
	outVal = analogRead(A5);
	delay(100); // wait 0.100
	char outstr[10];
	float f_val = (5.000 / 1024.000)*outVal;
	dtostrf(f_val, 7, 3, outstr);
	Serial.println(outstr);
	delay(500);

	int val= Serial.read(); //reading command from COM port
	int ang = 1; //rotate angle
	switch (val)
	{
	// fragment for controlling the servo drive
	//---------------------------------------------------------------------------------
	case '-': //decrease angle
	{
		for (myAngle = 0; myAngle <= ang; myAngle++) {
			servoPulse(servoPin, myAngle);
		}
		return;
	}
	case '+': //increase angle
	{
		for (myAngle = 180; myAngle >= (180 - ang); myAngle--) {
			servoPulse(servoPin, myAngle);
		}
	}
	}
	//end of the fragment for controlling the servo drive
	//---------------------------------------------------------------------------------
}

