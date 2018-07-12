/*                                                  A TENER EN CUENTA

Dentro de cada condición hay que establecer un rango Máximo
que será el valor que tome ValorDimmer cuando detecte movimiento
Y un valor mínimo, que será el valor predeterminado del Dimmer cuando está en Reposo.   

La lectura digital de los sensores LDR NO DAN VALORES HIGH-LOW, sino que devuelve los valores binarios 0 y 1:
0: Oscuridad total
1: Un mínimo de luz ---> El mínimo ápice de luz activa este valor

Se han declarado los valores que pueden tomar el sensor LDR1 que detecta el Día/Noche como constantes con define,
De esta forma, no es necesario modificar todo el código si queremos cambiar el rango de iluminación con el que se activará el DIMMER.
Para los valores que puede tomar el dimmer, se han declarado también constantes, por el mismo motivo que en los valores del sensor LDR1.
Ambos, LDR1 Y DIMMER tienen 5 niveles de valores:
-Min    --> Mínimo
-MinMed --> Mínimo-Medio
-Med    --> Medio
-MaxMed --> Máximo-Medio
-Max    --> Máximo

El máximo de luz sería 1023, el dimmer comenzará a funcionar por lo menos cuando la cantidad de luz sea la mitad, aprox 523.
El máximo del dimmer creo recordar que era 250, si no es así, sólo hay que cambiar los valores de Iluminacion que puede tomar DIMMER.

No he conseguido encontrar una función de intervalo de tiempo para que la intensidad de la luz suba/baje progresivamente.
Asi que... He utilizado bucles For...

*/

//Datos de sensor LDR para determinación de Día-Noche
int valorLDR1 = 0;

//Datos de sensor LDR para iluminación de vehículos
int valorLDR2 = 0;  

//Datos de sensor PIR
int valorPIR = 0;

//Valores DIMMER
int ValorDimmer = 0;

//Pines analógicos para DIMMER Y LDR1
#define LDR1 A2 //Sensor de iluminación de día/noche
#define DIMMER A4

//Pines  digitáles para  LDR2 y PIR
#define LDR2 4  //Sensor de iluminación de vehículo
#define PIR  6

                        //DECLARACIÓN DE VALORES QUE PUEDEN TOMAR EL SENSOR LDR1 Y EL DIMMER //


//Valores Para condición de cantidad de luz recibida por LDR1 es decir, el sensor encargado de determinar el día y la noche
#define ValorMaxLuz 523     // 100% de 523 
#define ValorMaxMedLuz 393  // 70% de 523
#define ValorMedLuz  262    // 50% de 523
#define ValorMinMedLuz 130  // 25% de 523
#define ValorMinLuz 0       // 0% de 523 

//Valores que puede tomar DIMMER es decir, la cantidad de energía que va a recibir, Valores calculados según el porcentaje de 250
#define IluminacionApagado 0
#define IluminacionMin 25            // 0%
#define IluminacionMinMed 63        // 25%  
#define IluminacionMed 125          // 50%
#define IluminacionMaxMed 188       // 75%
#define IluminacionMax 250          // 100%


void setup()
{
    pinMode(DIMMER, OUTPUT);
    pinMode(PIR, INPUT);
    pinMode(LDR1, INPUT);
    pinMode(LDR2, INPUT);
    
}

void SubeBajaIntensidad(int AnteriorDimmer, int NuevoDimmer){
    if(AnteriorDimmer == NuevoDimmer){
        analogWrite(DIMMER, AnteriorDimmer);
    }

    else if(AnteriorDimmer > NuevoDimmer){
        for(int i = AnteriorDimmer; i >= NuevoDimmer; i--){
            analogWrite(DIMMER, i);
        }
    }

    else if(AnteriorDimmer < NuevoDimmer){
        for(int i = AnteriorDimmer; i <= NuevoDimmer; i++){
            analogWrite(DIMMER, i);
        }
    }
}



void loop()
{
    valorLDR1 = analogRead(LDR1);
    valorLDR2 = digitalRead(LDR2);     
    valorPIR = digitalRead(PIR);
    int EscrituraAnteriorDimmer = ValorDimmer;


    if(valorLDR1 >= ValorMaxLuz)                
    {
        ValorDimmer = IluminacionApagado;
        
    }

    else if((valorLDR1 >= ValorMaxMedLuz) && (valorLDR1 < ValorMaxLuz))
    {
        
        if(valorPIR == HIGH && valorLDR2 == 0){
            ValorDimmer = IluminacionMinMed;
        } 

        else if(valorPIR == HIGH && valorLDR2 == 1){
            ValorDimmer = IluminacionMin;
        }                                                              
        else if(valorPIR == LOW && valorLDR2 == 1){
            ValorDimmer = IluminacionMin;        
        }

        else ValorDimmer = IluminacionMin;        
    }
    

    else if((valorLDR1 >= ValorMedLuz) && (valorLDR1 < ValorMaxMedLuz))
    {
       if(valorPIR == HIGH && valorLDR2 == 0){
            ValorDimmer = IluminacionMed;
        } 

        else if(valorPIR == HIGH && valorLDR2 == 1){
            ValorDimmer = IluminacionMinMed;
        }                                                              
        else if(valorPIR == LOW && valorLDR2 == 1){
            ValorDimmer = IluminacionMinMed;        
        }

        else ValorDimmer = IluminacionMinMed;
    }

    else if((valorLDR1 >= ValorMinMedLuz) & (valorLDR1 < ValorMedLuz))
    {
       if(valorPIR == HIGH && valorLDR2 == 0){
            ValorDimmer = IluminacionMaxMed;
        } 

        else if(valorPIR == HIGH && valorLDR2 == 1){
            ValorDimmer = IluminacionMed;
        }                                                              
        else if(valorPIR == LOW && valorLDR2 == 1){
            ValorDimmer = IluminacionMed;        
        }

        else ValorDimmer = IluminacionMed;
    }

    else if((valorLDR1 >= ValorMinLuz) & (valorLDR1 < ValorMinMedLuz))
    {
       if(valorPIR == HIGH && valorLDR2 == 0){
            ValorDimmer = IluminacionMax;
        } 

        else if(valorPIR == HIGH && valorLDR2 == 1){
            ValorDimmer = IluminacionMaxMed;
        }                                                              
        else if(valorPIR == LOW && valorLDR2 == 1){
            ValorDimmer = IluminacionMaxMed;        
        }

        else ValorDimmer = IluminacionMaxMed;

    }

    SubeBajaIntensidad(EscrituraAnteriorDimmer, ValorDimmer);

}

