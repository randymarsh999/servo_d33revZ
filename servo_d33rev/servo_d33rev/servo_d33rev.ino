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
int myAngle;                 // будет хранить угол поворота
int pulseWidth;              // длительность импульса


//
int Relay = 7;          // Указываем, что вывод реле In1, подключен к реле цифровому выводу 7
int RelayPower = 12;      //питание реле 12



int RelayPolarPower = 6;     // Указываем, что вывод реле In1, подключен к реле цифровому выводу 10
int RelayPolarP = 8;     // Указываем, что вывод реле In1, подключен к реле цифровому выводу 10
int RelayPolarN = 10;        //Указываем, что вывод реле, подключен к реле цифровому выводу 5



//1-1 питание 
//2-3 сигнал 2
//3-2 сигнал 1
//4-5 земля

//угол поворота серво привода
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
	pinMode(KeyPin, OUTPUT);
	pinMode(Relay, OUTPUT);             // сконфигурировали выход для управления реле питания
	pinMode(RelayPower, OUTPUT);        // сконфигурировали выход для питания реле питания
	digitalWrite(RelayPower, HIGH);     // Запитали Реле
	pinMode(RelayPolarPower, OUTPUT);           // сконфигурировали выход для управления реле полярности
	digitalWrite(RelayPolarPower, HIGH);           // сконфигурировали выход для управления реле полярности
	Serial.begin(9600);
	pinMode(A0, INPUT);
	//установили скорость Com порта
}

void loop() {
	//float analogValue = analogRead(0); // Задаем переменную analogValue для считывания показаний 
	//float voltageValue = analogValue * Step; // Переводим в вольты (показание * шаг) 
	//delay(500); // Ждем пол секунды 


	String cmd="";

	//чтение строки данных из Com порта
	char inString[10];
	int i = 0;
	while (Serial.available()>0) {
		delay(1);
		inString[i] = Serial.read();
		if (inString[i] == '_') {
			cmd = inString;
			//Serial.println(inString);
		}
		i++;
	}

	if (cmd!="")
	{
		Serial.println(cmd);
	}



	//Измерение с вывода А5 и вывод данных в COM порт 
	outVal = analogRead(A5);
	delay(100); // Ждем 0.001
	char outstr[10];
	float f_val = (5.000 / 1024.000)*outVal;
	dtostrf(f_val, 7, 3, outstr);
	Serial.println(outstr);
	delay(1000);








	switch (val)
	{
		//управление сервоприводом
		//---------------------------------------------------------------------------------
	case '-': //уменьшение угла поворта
	{
		for (myAngle = 0; myAngle <= ang; myAngle++) {
			servoPulse(servoPin, myAngle);
		}
		return;
	}
	case '+': //приращение угла поворота
	{
		for (myAngle = 180; myAngle >= (180 - ang); myAngle--) {
			servoPulse(servoPin, myAngle);
		}
	}
	//конец фрагмента для управления сервоприводом
	//---------------------------------------------------------------------------------





	/*  //фрагмент кода для выключения всей сети
	if (Serial.available() > 0)
	{

	String inString;

	char inChar = Serial.read();
	inString += inChar;
	if (inChar == '\n') {
	Serial.print("String: ");
	Serial.println(inString);
	inString = "";
	}

	/*char str[20];
	int ang=1; //угол поворота
	int val;
	//int val=Serial.read();
	val=43;
	switch (val)
	{
	//управление сервоприводом
	//---------------------------------------------------------------------------------
	case '-': //уменьшение угла поворта
	{
	for (myAngle=0; myAngle<=ang; myAngle++) {
	servoPulse(servoPin, myAngle);
	}
	return;
	}
	case '+': //приращение угла поворота
	{
	for (myAngle=180; myAngle>=(180-ang); myAngle--) {
	servoPulse(servoPin, myAngle);
	}
	}
	//конец фрагмента для управления сервоприводом
	//---------------------------------------------------------------------------------
	}*/
	//}
}

