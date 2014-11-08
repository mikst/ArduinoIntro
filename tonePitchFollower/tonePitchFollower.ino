/*
  Pitch follower
 
 Plays a pitch that changes based on a changing analog input
 
 circuit:
 * 8-ohm speaker on digital pin 9
 * photoresistor on analog 0 to 5V
 * 4.7K resistor on analog 0 to ground
 
 created 21 Jan 2010
 modified 31 May 2012
 by Tom Igoe, with suggestion from Michael Flynn

This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/Tone2
 
 */
int analogInPin = A0;  // analog pin used to connect the potentiometer
int sensorValue = 0;   // variable to read the value from the analog pin 
int outputValue = 0;        // value output to the PWM (analog out)


void setup() {
  // initialize serial communications (for debugging only):
  Serial.begin(9600);
}

void loop() {
 // read the analog in value:
  sensorValue = analogRead(analogInPin); 

  // map the analog input range
  // to the output pitch range (120 - 1500Hz)
  // change the minimum and maximum input numbers below
  // depending on the range your sensor's giving:
   // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 120, 1500); 
 // make sure that the outputValue does not go out from the analogWrite range (0-255) 
  outputValue = constrain(outputValue,120,1500); 

  // play the pitch on the pin 9:
  tone(9, outputValue, 10);
  
  // print the results to the serial monitor:
  Serial.print("sensor = " );                       
  Serial.print(sensorValue);      
  Serial.print("\t Tone = ");      
  Serial.println(outputValue);   
  
  delay(1);        // delay in between reads for stability
}






