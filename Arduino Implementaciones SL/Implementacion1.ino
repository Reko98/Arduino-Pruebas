//Datos de sensor LDR para determinación de Día-Noche
int valorLDR1 = 0;

//Datos de sensor LDR para iluminación de vehículos
int valorLDR2 = 0;  //????

//Datos de sensor PIR
int valorPIR = 0;

//Para un único valor de LED 220V
//Sustituir por Dimmer
int LED220 = 8;

//Pines Analógicos  para LDR1, LDR2 y PIR
#define LDR1 A0
#define LDR2 A2     //???
#define PIR A4

void setup()
{
    pinMode(LED220, OUTPUT);
    pinMode(PIR, INPUT);
    pinMode(LDR1, INPUT);
    pinMode(LDR2, INPUT);
    Serial.begin(9600);
}



void loop()
{
    valorLDR1 = analogRead(LDR1);
    valorLDR2 = analogRead(LDR2); //Para qué?
    valorPIR = digitalRead(PIR);


    if(valorLDR1 >= 423)                //Hay que modificar los valores de LDR1 en las condiciones según la intensidad de luz deseada
    {
        analogWrite(LED220, 0);
    }

    else if((valorLDR1 >= 323) & (valorLDR1 < 423))
    {
                                                                        //Dentro de cada condición hay que establecer un rango Máximo
                                                                        //que será el valor que tome LED220 cuando detecte movimiento
                                                                        //Y un valor mínimo, que será el valor predeterminado del LED cuando está en Reposo.    
        if(valorPIR == LOW){
            analogWrite(LED220, 50);
        }

        else analogWrite(LED220, 204);
    }
    
    else if((valorLDR1 >= 223) & (valorLDR1 < 323))
    {
        if(valorPIR == LOW){
            analogWrite(LED220, 50);
        }

        else analogWrite(LED220, 204);

    }

    else if((valorLDR1 >= 123) & (valorLDR1 < 223))
    {
        if(valorPIR == LOW){
            analogWrite(LED220, 50);
        }

        else analogWrite(LED220, 204);

    }
}

