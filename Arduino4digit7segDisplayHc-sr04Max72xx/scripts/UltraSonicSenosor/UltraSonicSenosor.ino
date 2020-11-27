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
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600); /*starts serial monitor*/
}

void loop() {
  digitalWrite(trigPin, LOW);       
  delayMicroseconds(2);  /*waiting for sound to bounce back*/           
  digitalWrite(trigPin, HIGH);      
  delayMicroseconds(10); /*waiting a bit longer*/          
  digitalWrite(trigPin, LOW);       
  duration = pulseIn(echoPin, HIGH);  /*calculate the time the sound travelt*/
  distance = (duration * 0.0343) / 2; /*calculate distance*/
  dis_round = round(distance); /*rounds distance*/
  Serial.println(dis_round);/*distance to monitor*/
  delay(100);
}
