
int echo = 8;
int trig = 9;
long duration = 0;
int distance = 0;

void setup()
{
 // put your setup code here, to run once:
	pinMode(echo, INPUT);		// setting trigger pin to output
	pinMode(trig, OUTPUT);	// setting echo pin to input
	Serial.begin(4800);		// giving the baud rate for serial port

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
  
  
  duration = pulseIn(echo, HIGH);	// measuring the duration of pulse from ECHO pin
  distance  = (duration*0.034)/2) + 4; 	// speed of sound in cm/microseconds
  Serial.print("Distance: ");
  Serial.println(distance);		
}