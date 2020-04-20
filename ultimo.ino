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

void setup() //<-Aqui inicia la funcion SETUP-------------------------------------
{
  Serial.begin(9600); ///Auxiliar para ver varibles internas o electricas  
  pinMode(SenialEncoder,INPUT);   //<-Renombrar

  pinMode(BArranque,INPUT);
  pinMode(BParo,INPUT);
  pinMode(BDistancia,INPUT);

  pinMode(avancemotor1,OUTPUT);
  pinMode(avancemotor2,OUTPUT);
  pinMode(retromotor1,OUTPUT);
  pinMode(retromotor2,OUTPUT);
}//<--Aqui acaba la funcion SETUP--------------------------
/****************************************************************************************/
/* las variavles se declaran como entradas y salidas en la funcion "SETUP" por que      */
/* son las primeras instruciones que se ejecutan cuando el arduino es alimentado        */ 
/****************************************************************************************/

 int Pulso(int ContadorAux) //<--- Inicio de la Funcion "PULSO" que es la que cuenta los pulsos en el  encoder
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
    /***********************************************************************************************************/
    /* Si declaras las salidas y entradas aqui, el compilador no te dara errores pero internamente             */
    /* se estran redeclarando continuamente por lo que llevara al programa a bugerase o dañar la memoria       */
    /* del arduino, mas aparte es una mala practica declarar "ENTRADAS Y SALIDAS GLOBALES EN FUNCION QUE ESTAN */
    /* EN CONSTANTE INTERACION"                                                                                */ 
    /***********************************************************************************************************/
 } //<-----Fin de la funcion "PULSO"

void loop() 
{           
  while(Contador<15){ // se le da el  numro de vueltas (125).....
    digitalWrite (avancemotor1, HIGH);
    digitalWrite (avancemotor2, HIGH);
    Contador=Pulso(Contador);
  }
    digitalWrite (avancemotor1,LOW);
    digitalWrite (avancemotor2, LOW);
    delay (1000); 
 //Contador=0;
}
