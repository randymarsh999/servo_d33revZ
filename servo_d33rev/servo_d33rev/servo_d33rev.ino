/*
 Name:		servo_d33rev.ino
 Created:	06.06.2018 15:02:22
 Author:	root
*/

int servoPin = 9;            // ���� ����������� �����
int KeyPin = 8;
int temp = 1;
int outVal = 0;



//���������� ��� ���� ��������
int myAngle;                 // ����� ������� ���� ��������
int pulseWidth;              // ������������ ��������


//
int Relay = 7;          // ���������, ��� ����� ���� In1, ��������� � ���� ��������� ������ 7
int RelayPower = 12;      //������� ���� 12



int RelayPolarPower = 6;     // ���������, ��� ����� ���� In1, ��������� � ���� ��������� ������ 10
int RelayPolarP = 8;     // ���������, ��� ����� ���� In1, ��������� � ���� ��������� ������ 10
int RelayPolarN = 10;        //���������, ��� ����� ����, ��������� � ���� ��������� ������ 5



//1-1 ������� 
//2-3 ������ 2
//3-2 ������ 1
//4-5 �����

//���� �������� ����� �������
float Step = 5.0F / 1024; // ��������� ��� U����� / �� �������� 

void servoPulse(int servoPin, int myAngle)
{
	pulseWidth = (myAngle * 11) + 500;  // ������������ ���� � ������������
	digitalWrite(servoPin, HIGH);       // ������������� ����� ������� �������
	delayMicroseconds(pulseWidth);      // ���
	digitalWrite(servoPin, LOW);        // ������������� ������ �������
	delay(20);

}

//����� ����� � ��������� �������� ���������
void setup()
{
	// put your setup code here, to run once:
	pinMode(servoPin, OUTPUT);          // ������������� ��� �����, ��� �����
	pinMode(KeyPin, OUTPUT);
	pinMode(Relay, OUTPUT);             // ���������������� ����� ��� ���������� ���� �������
	pinMode(RelayPower, OUTPUT);        // ���������������� ����� ��� ������� ���� �������
	digitalWrite(RelayPower, HIGH);     // �������� ����
	pinMode(RelayPolarPower, OUTPUT);           // ���������������� ����� ��� ���������� ���� ����������
	digitalWrite(RelayPolarPower, HIGH);           // ���������������� ����� ��� ���������� ���� ����������
	Serial.begin(9600);
	pinMode(A0, INPUT);
	//���������� �������� Com �����
}

void loop() {
	//float analogValue = analogRead(0); // ������ ���������� analogValue ��� ���������� ��������� 
	//float voltageValue = analogValue * Step; // ��������� � ������ (��������� * ���) 
	//delay(500); // ���� ��� ������� 


	String cmd="";

	//������ ������ ������ �� Com �����
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



	//��������� � ������ �5 � ����� ������ � COM ���� 
	outVal = analogRead(A5);
	delay(100); // ���� 0.001
	char outstr[10];
	float f_val = (5.000 / 1024.000)*outVal;
	dtostrf(f_val, 7, 3, outstr);
	Serial.println(outstr);
	delay(1000);








	switch (val)
	{
		//���������� �������������
		//---------------------------------------------------------------------------------
	case '-': //���������� ���� �������
	{
		for (myAngle = 0; myAngle <= ang; myAngle++) {
			servoPulse(servoPin, myAngle);
		}
		return;
	}
	case '+': //���������� ���� ��������
	{
		for (myAngle = 180; myAngle >= (180 - ang); myAngle--) {
			servoPulse(servoPin, myAngle);
		}
	}
	//����� ��������� ��� ���������� �������������
	//---------------------------------------------------------------------------------





	/*  //�������� ���� ��� ���������� ���� ����
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
	int ang=1; //���� ��������
	int val;
	//int val=Serial.read();
	val=43;
	switch (val)
	{
	//���������� �������������
	//---------------------------------------------------------------------------------
	case '-': //���������� ���� �������
	{
	for (myAngle=0; myAngle<=ang; myAngle++) {
	servoPulse(servoPin, myAngle);
	}
	return;
	}
	case '+': //���������� ���� ��������
	{
	for (myAngle=180; myAngle>=(180-ang); myAngle--) {
	servoPulse(servoPin, myAngle);
	}
	}
	//����� ��������� ��� ���������� �������������
	//---------------------------------------------------------------------------------
	}*/
	//}
}

