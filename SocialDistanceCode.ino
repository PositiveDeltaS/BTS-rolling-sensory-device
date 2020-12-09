/* BTS Roll sensory device
 *  By: Kelsey Troeger Aliyah Nordstrom Luke Walker
 *  
 *  Based on code from:
 *  Aubrey Walton
 *  University of West Florida 2020
 *  Based on coding from Mohd Sohail
 *  And
 *  "8 Bit Electronic Music Using a Vibrations From Piezo Buzzer" Instructable by JeanC117
 */

int trigPin = 4;
int echoPin = 3;
int buzzPin = 2;
int motorPin = 5;
int LEDpin = 13;

char notes[] = { 'E', 'd', 'B', 'A', 'a', 'F', 'H'};
//int freq[] = {165, 277, 247, 220, 208, 185, 329};
int freq[] = {330, 554, 494, 440, 415, 370, 659};
const int numNotes = 7;

void setup()
{
pinMode(trigPin, OUTPUT); //Negative side of Buzzer
pinMode(echoPin, INPUT); //Echopin on distance sensor
pinMode(buzzPin, OUTPUT); //Postive side of Buzzer
pinMode (LEDpin, OUTPUT); //LED on pin 13

Serial.begin(9600);
}

int songthatneverends(char note)
{
  for (int i=0; i<numNotes; ++i)
  {
    if(note == notes[i]) 
    {
      Serial.println(notes[i]);
      Serial.println(freq[i]);
      return freq[i];
    }
  }
  Serial.println("returning default");
  return 0;
}
void playsong()
{
 //Cause ah, ah, I'm in the stars tonight
tone(buzzPin, songthatneverends('E'), 150);
delay(300);
tone(buzzPin, songthatneverends('d'), 150);
delay(400);
tone(buzzPin, songthatneverends('B'), 150);
delay(400);
tone(buzzPin, songthatneverends('A'), 150);
delay(400);
tone(buzzPin, songthatneverends('a'), 200);
delay(200);
tone(buzzPin, songthatneverends('H'), 100);
delay(150);
tone(buzzPin, songthatneverends('F'), 200);
delay(200);
tone(buzzPin, songthatneverends('E'), 100);
delay(150);
tone(buzzPin, songthatneverends('E'), 200);
delay(600);

//So watch me bring the fire set the night alight
tone(buzzPin, songthatneverends('E'), 200);
delay(300);
tone(buzzPin, songthatneverends('E'), 200);
delay(300);
tone(buzzPin, songthatneverends('E'), 200);
delay(300);
tone(buzzPin, songthatneverends('d'), 150);
delay(400);
tone(buzzPin, songthatneverends('B'), 150);
delay(400);
tone(buzzPin, songthatneverends('A'), 150);
delay(400);
tone(buzzPin, songthatneverends('a'), 200);
delay(200);
tone(buzzPin, songthatneverends('H'), 100);
delay(150);
tone(buzzPin, songthatneverends('F'), 200);
delay(250);
tone(buzzPin, songthatneverends('E'), 100);
delay(150);
tone(buzzPin, songthatneverends('E'), 200);
 
}
void loop()
{

int duration, distance;

digitalWrite(trigPin, HIGH); //buzzer turns on
delay(1); //wait
digitalWrite(trigPin, LOW); //buzzer turns off

duration = pulseIn(echoPin, HIGH); //distance sensor on

distance = (duration/2) / 29.1; // ensure distance variable is set to 6 feet

if (distance <= 100 && distance >= 0) { 

playsong();
delay(10000);
digitalWrite(LEDpin, HIGH); // if distance is greater than 6 feet, LED turns on
} else {

digitalWrite(buzzPin, LOW); //if distance is less than 6 feet, buzzer turns off
digitalWrite(LEDpin, LOW); // if distance is less than 6 feet, LED turns off
}

delay(60);


}
