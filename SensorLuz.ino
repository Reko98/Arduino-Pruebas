//Datos de sensor LDR
int LDRvalue = 0;

//Ejemplo varios LEDS
int LED1 = 12;
int LED2 = 11;
int LED3 = 10;
int LED4 = 9;
int LED5 = 8;

//Pin analógico para sensor LDR
int LDR = A0;

void setup()
{
//Valores de los Pins de LED como salidas
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
pinMode(LED4, OUTPUT);
pinMode(LED5, OUTPUT);

//Monitor Serie para visualizar valores de LDR
Serial.begin(9600);	
}

void loop()
{
//Serial servirá para comprobar que valores recibe el sensor LDR
LDRvalue = analogRead(LDR);
Serial.println(LDRvalue);

if(LDRvalue >= 523)
{
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
    digitalWrite(LED4,LOW);
    digitalWrite(LED5,LOW);
    
}

else if((LDRvalue >= 423) & (LDRvalue < 523))
{
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
    digitalWrite(LED4,LOW);
    digitalWrite(LED5,LOW);   
}

else if((LDRvalue >= 323) & (LDRvalue < 423))
{
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
}
else if((LDRvalue >= 223) & (LDRvalue < 323))
{
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
}
else if((LDRvalue >= 123) & (LDRvalue < 223))
{
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, LOW);
}
else
{
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
}
	
}
