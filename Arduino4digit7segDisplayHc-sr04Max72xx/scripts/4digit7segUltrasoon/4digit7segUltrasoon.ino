#include "LedControl.h" /*library for the display*/

/*
 MAX72XX pinout
 pin 12 to DataIn 
 pin 11 to CLK 
 pin 10 to LOAD */
LedControl lc=LedControl(12,10,11,1); /*define pins for display*/

/*display variables*/
unsigned long delaytime=250; /*delay*/
int digit3; /*Text for digit4*/
int digit2; /*Text for digit3*/
int digit1; /*Text for digit2*/
int digit0; /*Text for digit1*/

/*ultrsoonSensor variables
 ultrasoon pinout
 Vcc  --> 5V
 Trig --> 9
 Echo --> 8
 GND  --> GND
 */
const int trigPin = 9;   // trigger pin
const int echoPin = 8;   // echo in
 
float duration; /*Time it takes for the sound to get back to the device*/  
float distance; /*to calculate distance we use (duration * 0.0343) / 2*/
int dis_round; /*round the distance number on the cm*/

void setup() {
  /*dislplay*/
  lc.shutdown(0,false); /*Wake-up call*/
  lc.setIntensity(0,8); /*Brightness*/
  lc.clearDisplay(0); /*Clear display*/
  /*ultrasoon*/
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void distanceToObject() { /*function to calculate the distance*/
  digitalWrite(trigPin, LOW);       
  delayMicroseconds(2);  /*waiting for sound to bounce back*/           
  digitalWrite(trigPin, HIGH);      
  delayMicroseconds(10); /*waiting a bit longer*/          
  digitalWrite(trigPin, LOW);       
  duration = pulseIn(echoPin, HIGH);  /*calculate the time the sound travelt*/
  distance = (duration * 0.0343) / 2; /*calculate distance*/
  dis_round = round(distance); /*rounds distance*/
  Serial.println(dis_round);
}

void distanceToScreen(){ /*to diplay to screen*/
  /*breaks-up the number into induvidual numbers*/
  digit3 = (dis_round%10);
  digit2 = ((dis_round/10)%10);
  digit1 = ((dis_round/100)%10);
  digit0 = (dis_round/1000);
  /*displays distance*/
  lc.setChar(0,0, digit0, false);
  lc.setChar(0,1, digit1, false);
  lc.setChar(0,2, digit2, false);
  lc.setChar(0,3, digit3, false);
  /*to diplay to screen*/
  if(dis_round > 1191){
    lc.setChar(0,0, 'a', false);
    lc.setChar(0,1, 'a', false);
    lc.setChar(0,2, 'a', false);
    lc.setChar(0,3, 'a', false);
  }
}

void loop() {       
  distanceToObject(); /*calls the ultrsoon sensor*/
  distanceToScreen(); /*calls the display*/
  delay(100); /*refresh rate of the display/system*/   
}
