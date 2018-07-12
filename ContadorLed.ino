int valorLDR = 0;

int valorDimmer = 0;

int contador = 0;

int UltimaIteracion = 0;

int valorCondicion = 0;

int  i = 0;


//Definición de constantes y de Pines

#define LDR 2
#define DIMMER A2
#define Candado 1

#define CambiaIntensidad 10


void setup(){
    pinMode(DIMMER, OUTPUT);
    pinMode(LDR, INPUT);
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

void loop(){
    while(digitalRead(LDR) == 1){
        EscrituraAnteriorDimmer = valorDimmer;

        valorCondicion = Rand(1,2);     //Establecer la función Random en el intervalo 1-2
        
        if(valorCondicion == 1)     //Sube Intensidad
            valorDimmer = EscrituraAnteriorDimmer + 10;
            SubeBajaIntensidad(EscrituraAnteriorDimmer, valorDimmer);

        if(valorCondicion == 2)     //Sube Intensidad
            valorDimmer = EscrituraAnteriorDimmer - 10;
            SubeBajaIntensidad(EscrituraAnteriorDimmer, valorDimmer);
    
        contador++;
    }
    
    if(digitalRead(LDR)== 0 && Candado != i){
        UltimaIteracion = contador;
        i++;
    }
}