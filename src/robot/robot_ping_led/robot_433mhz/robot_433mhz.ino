#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile
RH_ASK driver;
// adjust these till the robot goes streight to compensate for motor differences
int power_forward_right = 180; /* half power on turns */
int power_forward_left = 180; /* half power on turns */

// motor pins.  Note that only pins 2,5,6, 9 and 10 can be used for pwm
int right_forward = 5;
int right_reverse = 3;
int left_forward = 6;
int left_reverse = 9;

// try this time to make a right turn just above 90 degrees
int delay_time_ninty_turn = 200;
// if we are under this distance, make a turn
int cm_for_turn = 10;
int delay_time_forward = 100;

void setup() {
  Serial.begin(9600);
  pinMode(right_forward, OUTPUT);
  pinMode(right_reverse, OUTPUT); 
  pinMode(left_forward, OUTPUT); 
  pinMode(left_reverse, OUTPUT);
  // turn all off
  digitalWrite(right_forward, LOW);
  digitalWrite(right_reverse, LOW);
  digitalWrite(left_forward, LOW);
  digitalWrite(left_reverse, LOW);
  if (!driver.init())
         Serial.println("init failed");
  // for debugging
  // Serial.println('Start');
  delay(1000);
}

void loop() {
   uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);

    if (driver.recv(buf, &buflen)) // Non-blocking
    {
	int i;

	// Message with a good checksum received, dump it.
	driver.printBuffer("Got:", buf, buflen);
    }

    if (buf[2] = 46){
      move_forward;
      }
    if (buf[2] = 42){
      move_backward;
      }
    if (buf[2] = 52){
      turn_right;
      }
    if (buf[2] = 41){
      turn_left;
      }
      
   //The hex equivlant of "L" is 4c, so "L" is replaced by "A" so you can compare hex numbers. 

}

void turn_right() {
  Serial.println("turning right");
  analogWrite(right_forward, LOW);
  analogWrite(right_reverse, power_forward_right);
  analogWrite(left_forward, power_forward_left);
  analogWrite(left_reverse, LOW);
  delay(delay_time_ninty_turn);
}

void move_forward() {
  Serial.println("moving forward");
  analogWrite(right_forward, power_forward_right);
  analogWrite(right_reverse, LOW);
  analogWrite(left_forward, power_forward_left);
  analogWrite(left_reverse, LOW);
}

void move_backward(){
  Serial.println("moving backward");
  analogWrite(right_reverse, power_forward_right);
  analogWrite(right_forward, LOW);
  analogWrite(left_reverse, power_forward_left);
  analogWrite(left_forward, LOW);
}

void turn_left(){
  Serial.println("turning left");
  analogWrite(right_forward, power_forward_right);
  analogWrite(right_reverse, LOW);
  analogWrite(left_forward, LOW);
  analogWrite(left_reverse, power_forward_left);
  delay(delay_time_ninty_turn);
} 
