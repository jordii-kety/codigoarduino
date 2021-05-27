#include <Servo.h>

const int trigPin = 9;  //Declaramos todas las constantes que vamos a necesitar
const int echoPin = 8;  //Declaramos todas las constantes que vamos a necesitar

long duration;  //Variable largas para almacenamiento de números
int distance;   //Variable de distancia 

Servo myServo;  //Variable
void setup()   //Damos las instrucciones al microcontrolador de arduino
{
myServo.attach(7);  //Conecta la variable con el pin asignado

pinMode(trigPin, OUTPUT); // Establece el trigPin como una salida

pinMode(echoPin, INPUT); // Establece el echoPin como una entrada

Serial.begin(9600); //Variable que utilizamos para reproducir sonidos en el buzzer
}

void loop() {   //Damos las instrucciones al microcontrolador de arduino
distance = calculateDistance();

myServo.write(0);   //Escribe un valor en el servo, controlando el eje en consecuencia

if ( distance < 10) // Regula la distancia del sensor para que detecte cualquier cosa y se mueva el sevomotor

{ myServo.attach(7);  //Conecta la variable con el pin asignado

myServo.write(130);   //Escribe un valor en el servo, controlando el eje en consecuencia

delay(1500); // Regula el giro del servomotor



}
else{
myServo.detach();   //Desconecta la variable servo de su pin
}
Serial.println(distance);   //Imprime datos en el puerto serie como texto 
}
int calculateDistance(){

digitalWrite(trigPin, LOW); // Para generar un pulso limpio a LOW 4us

delayMicroseconds(2);   //Pausa el programa durante el tiempo en microsegundos

digitalWrite(trigPin, HIGH);  // Generamos trigger (disparo) de 10us

delayMicroseconds(10); //Pausa el programa durante el tiempo

digitalWrite(trigPin, LOW); // Para generar un pulso limpio

duration = pulseIn(echoPin, HIGH);  // Medimos el tiempo entre pulsos, en microsegundos

distance= duration*0.034/2; // Convertimos a distancia, en cm
return distance;
}
