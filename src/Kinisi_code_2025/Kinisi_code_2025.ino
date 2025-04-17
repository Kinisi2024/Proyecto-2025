//librerias
#include <NewPing.h>
#include <Servo.h>
//ultrasonido
#define SONAR_NUM 3      // Number of sensors.
#define MAX_DISTANCE 310 // Maximum distance (in cm) to ping.
long cm_distancia;

NewPing sonar[SONAR_NUM] = {   // Sensor object array.
  NewPing(4, 5, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping.
  NewPing(6, 7, MAX_DISTANCE), //izquierdo i=1
  NewPing(8, 9, MAX_DISTANCE) //derecho i = 2
};

//servo
int servoPin = 11;
Servo servo1;

//motores
int in1 = 12;// motor1
int in2 = 2;
int in3 = 3; //motor2
int in4 = A0;

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  //motores
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  //servo
  servo1.attach(servoPin);
  radar_centro();
}

void loop() {

}

long distancia(int i){
  return sonar[i].ping_cm();
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

void radar_centro(){
//Centro
servo1.write(96);
delay(300);      
}

void radar_derecha(){
//Derecha
servo1.write(71);
delay(300);
}

void radar_izquierda(){
//Izquierda
servo1.write(121);
delay(300);
}