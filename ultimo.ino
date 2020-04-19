boolean dato_anterior = 0;    
boolean dato_actual = 0; 
int Contador = 0; //<--Variable Digital
int avancemotor1 = 2;
int avancemotor2 = 3;
int retromotor1 = 4;
int retromotor2 = 5; 
int SenialEncoder = 6;
int BArranque = 11;
int BParo = 12;
int BDistancia = 10;
double Distancia = 0;//Varible digital

void setup() 
{
  Serial.begin(9600); ///Auxiliar para ver varibles internas o electricas  
  pinMode(SenialEncoder,INPUT);   //<-Renombrar
}

 int Pulso(int ContadorAux) //<--- funcion que cuenta los pulsos del encoder
 {
    dato_actual = digitalRead(SenialEncoder);
   if (dato_anterior != dato_actual)
   {
     delay(10);
     dato_actual = digitalRead(SenialEncoder);
   }
   if ( dato_anterior == 0 && dato_actual == 1) 
  {
         ContadorAux++;
         Serial.println(ContadorAux);
         delay(100);
  }
  
    dato_anterior = dato_actual;
    return ContadorAux;
 }  

void loop() 
{           
  while(Contador<15){ // se le da el  numro de vueltas (125
    digitalWrite (avancemotor1, HIGH);
    digitalWrite (avancemotor2, HIGH);
     Contador=Pulso(Contador);
  }
    digitalWrite (avancemotor1,LOW);
     digitalWrite (avancemotor2, LOW);
 delay (1000); 
 //Contador=0;
}
