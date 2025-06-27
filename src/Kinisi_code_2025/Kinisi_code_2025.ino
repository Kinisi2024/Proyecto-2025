//librerias
#include <NewPing.h>
#include <Servo.h>
//ultrasonido
#define SONAR_NUM 3 // Number of sensors.
#define MAX_DISTANCE 350 // Maximum distance (in cm) to ping.
long cm_distancia;
long cm_distanciaI;
long cm_distanciaD;
//4,5 Central
//6,7 Derecho
//8,9 Izquierdo
NewPing sonar[SONAR_NUM] = { NewPing(4, 5, MAX_DISTANCE),NewPing(6,7, MAX_DISTANCE),NewPing(8,9, MAX_DISTANCE) };

//servo
int servoPin = 11;
Servo servo1;

//motores
int in1 = 12;// motor1
int in2 = 2;
int in3 = 3; //motor2
int in4 = A0;
int PinBtn=10;

int centro = 65;

//esquinas y vueltas

int sentido=1;
int nro_esquinas=0;
int nro_vueltas;
int esquina;
int DistanciaInicial=0;
int DerechaInicial=0;
int IzquierdaInicial=0;
int DistanciaCruce=70;
void setup() {
//Para el boton
pinMode(PinBtn, INPUT_PULLUP);
while(digitalRead(PinBtn)==HIGH){
  delay(100);  
}
Serial.begin(9600); // Open serial monitor at 9600 baud to see ping results.
//motores
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
//servo
servo1.attach(servoPin);
//servo1.write(96);
radar_centro(centro);
DistanciaInicial=distancia(0);
delay(200);
cm_distancia = distancia(0);
delay(200);
while(cm_distancia>75){
  adelante();
  delay(500);
  detener();
  cm_distancia = distancia(0);
  delay(500);
 }
 if(distancia(1)<100){
  sentido = -1;
 }
 if(sentido==-1){
   centro = 69;
   DistanciaCruce=80;
 }
 atras();
 delay(600);
 detener();
}

void loop() {
 if(nro_esquinas<12){
  radar_centro(centro);
  adelante();
  delay(500);
  detener();
  cm_distancia = distancia(0);
  //cm_distanciaD = distancia(2);"
  //cm_distanciaI = distancia(1);"
  Serial.print("cm_distancia = ");
  Serial.println(cm_distancia);
  //Serial.print("cm_distanciaI = ");
  //Serial.println(cm_distanciaI);"
  //Serial.println(cm_distanciaD);"

  if (cm_distancia < DistanciaCruce){
   nro_esquinas++;
   if(sentido==1){
    detener();
    radar_derecha();
    adelante();
    delay(880);
    detener();
   }else{
    detener();
    radar_izquierda();
    adelante();
    delay(1351);
    radar_derecha();
    delay(100);
    detener();
   }
   
  }
 }else{
    detener();
 }
}

long distancia(int i){
  long dista=0;
  while(dista==0){
   dista=sonar[i].ping_cm();
  }
  return dista;
}

void adelante(){
//Adelante
//motor A
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
//motor B
//digitalWrite(in3, LOW);
//digitalWrite(in4, HIGH);
}

void atras(){
//Atras
//motor A
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
//motor B
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
}

void detener(){
//detener
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
//motor B
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
}

void radar_centro(int centro){
//Centro
servo1.write(centro);
//delay(100);
}

void radar_derecha(){
//Derecha
servo1.write(41);
//delay(100);
}

void radar_izquierda(){
//Izquierda
servo1.write(96);
//delay(100);
} 