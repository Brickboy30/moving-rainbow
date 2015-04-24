
// adjust these till the robot goes straight to compensate for motor differences
int power_forward_right = 200; /* half power on turns */
int power_forward_left = 200; /* half power on turns */

// motor pins.  Note that only pins 2,5,6, 9 and 10 can be used for pwm
int right_forward = 5;
int right_reverse = 3;
int left_forward = 6;
int left_reverse = 9;

// try this time to make a right turn just above 90 degrees
int delay_time_ninty_turn = 400;
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

  // for debugging
  // Serial.println('Start');
  delay(1000);
}

void loop() {
move_forward();
delay(1000);
turn_right();
move_backward();
delay(2000);
turn_left();
move_forward();
delay(2000);

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
