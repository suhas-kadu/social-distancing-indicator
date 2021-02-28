
int greenPin = 5;
int bluePin = 6;
int redPin = 7;
int echo = 8;
int trig = 9;
long duration = 0;
int distance = 0;

void setup()
{
	// put your setup code here, to run once:
	pinMode(echo, INPUT);			// setting trigger pin to output
	pinMode(trig, OUTPUT);			// setting echo pin to input
	pinMode(greenPin, OUTPUT);		// setting green pin of RGB to output
	pinMode(bluePin, OUTPUT);		// setting blue pin of RGB to output
	pinMode(redPin, OUTPUT);		// setting red pin of RGB to output
	Serial.begin(4800);				// giving the baud rate for serial port

}

void loop()
{
   // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  // generating a 10 microseconds pulse
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  
  duration = pulseIn(echo, HIGH);						// measuring the duration of pulse from ECHO pin
  distance  = (duration*0.034)/2) + 4; 					// speed of sound in cm/microseconds
  Serial.print("Distance: ");
  Serial.println(distance);	
  
  
  if(distance > 0 && distance <= 180){					// if some one does'nt maintains social distance					
  Serial.println("Alert: Social distance not maintained!");
   	// if social distance is not maintained red color is set to RGB LED
    analogWrite(redPin, 138);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    
    
  } else if(distance > 180 && distance <= 300){	 		// if social distance is maintained
  Serial.println("Safe: Social distance maintained!");  
 	// if social distance is maintained green color is set to RGB LED
  	analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
  } else {												// if no one is around us
  Serial.println("Safe");
    // 	if person is out of range no color is et to RGB LED
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
}