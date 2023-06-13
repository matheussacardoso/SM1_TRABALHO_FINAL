// C++ code
#include <Servo.h>
// Servo Sg90servo;
Servo myServo;
// variable to store the servo position
int angle = 0;

int celsius = 0;
int sensor = 0;
int potenciometro = 0;

void setup()
{
  Serial.begin(9600);
  myServo.attach(7);
  pinMode(A2,INPUT);
}

void loop()
{

  //sensor de temperatura
  sensor = analogRead(A2);
  celsius = celsius = map(((analogRead(A2) - 20) * 3.04), 0, 1023, -40, 125);
  potenciometro = analogRead(A3);
  
  // scales it to use it with the servo (value between 0 and 180)
  int angle = map(potenciometro, 0, 1023, 0, 180);
  
  //print fahreit e celsius
  Serial.print("Sensor: ");
  Serial.print(sensor);
  Serial.print(", Celsius: ");
  Serial.println(celsius);
  delay(1000);
  
  // print angulo e potenciometro
  Serial.print("Valor analogico do potenciometro: ");
  Serial.print(potenciometro);
  Serial.print(", Angulo do motor: ");
  Serial.println(angle);
  delay(2000);
  
  //controlado pelo sensor
  if(celsius > 25){
    Serial.print("Mais de 25 graus");
    // goes from 0 degrees to 90 degrees in steps of 1 degree
    for(angle = 0; angle< 90; angle++){
      // altera sua angulacao
      // tell servo to go to position in variable 'angle’
      myServo.write(angle);
      // waits 100ms for the servo to reach the position
      // velocidade
      delay(50);
  	}
    for (angle = 90; angle <180; angle++){
      myServo.write(angle);
      delay(10);
    }
  }
  
  else if(potenciometro < 500){
    Serial.print("Menos de 500");
    for(angle = 0; angle< 180; angle++){
      myServo.write(angle);
      delay(200);
  	}
  }
  
  else if(potenciometro > 500){
    Serial.print("Mais de 500");
    for(angle = 0; angle< 180; angle++){
      myServo.write(angle);
      delay(50);
  	}
  }
  
  else{
  	myServo.write(angle);
  	delay(200);
  }
  
}