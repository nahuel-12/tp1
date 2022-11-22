#define  pause 12
#define  reset 13
int contador=0;
int contador_bin=0;
int long t1,t2;
int dif_tiempo;
boolean contar=false;
boolean pin;
void setup() {
  //Serial.begin(9600);
  confg_sal();//funcion de configuracion de salidas
  pinMode(pause,INPUT_PULLUP);// seteo pin de pause como entrada
  pinMode(reset,INPUT_PULLUP);
  t1=millis();//cargo el tiempo de inicio de muestra
}

void loop() {
 if (contar==true){
 //******************************************
 //pregunta para saber si paso 1 seg 
   t2=millis();//cargo el tiempo actual
   if ((t2-t1)>=1000){
     t1=t2;//actualizo inicio de muestra
     mostrar();//rutina que muestra el valor
   }
//******************************************
//******************************************
 }
//rutina de reset *************
if (digitalRead(reset)==LOW){
  resetear();
}
//fin rutina de reset **********

//rutina de pausa *************
if (digitalRead(pause)==LOW){
    while (digitalRead(pause)==LOW){// suprimir rebote y disparo flanco
      delay(20);
      }
  pausar();
}
//fin rutina de pausa **********
 
}





void confg_sal(){
for (int i=1;i<=10;i++){
    pinMode (i,OUTPUT);
  }
}

void mostrar(){
 for (int i=10;i>=1;i--){ 
  contador_bin= contador >>  (i-1);
  pin=contador_bin & 1;
  digitalWrite(i,pin);
 // Serial.print(pin);
 }

 //Serial.println("");
 //  Serial.println(contador);
  
  contador++;
}

void resetear(){
   t1=millis();//cargo el tiempo de inicio de muestra
   contador=0;
   mostrar();
}

void pausar(){
 contar=!(contar);
 if (contar==false){//cambio a falso o sea se detiene
  dif_tiempo=1000-(t2-t1);//guardo el tiempo que faltaba para el segundo
 }
 else{
  t1=millis();
  while ((millis()-t1)<dif_tiempo){
    
  }
  mostrar();
  t1=millis();
 }
}
