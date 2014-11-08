// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo, instead of myservo, it can be any name 
 
int analogInPin = A0;  // analog pin used to connect the potentiometer
int sensorValue = 0;   // variable to read the value from the analog pin 
int outputValue = 0;        // value output to the PWM (analog out)

 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  // initialize serial communications
  Serial.begin(9600);
} 
 
void loop() 
{ 
 // read the analog in value:
  sensorValue = analogRead(analogInPin);            
  // map it to the range of the servo angle:
  outputValue = map(sensorValue, 0, 1023, 0, 179); 
 // make sure that the outputValue does not go out from the servo turning range (0-179) 
  outputValue = constrain(outputValue, 0, 179); 
  // turn the servo motor to the angle from the sensor input
  myservo.write(outputValue);                  // sets the servo position according to the scaled value
  
  // print the results to the serial monitor:
  Serial.print("sensor = " );                       
  Serial.print(sensorValue);      
  Serial.print("\t servo = ");      
  Serial.println(outputValue);   
  
  delay(15);                           // waits for the servo to get there 
} 
