#define in1 6
#define in2 7
#define in3 9
#define in4 8
#define en1 5
#define en2 10

 int M1_Speed = 80; // speed of motor 1 
 int M2_Speed = 80; // speed of motor 2
 int LeftRotationSpeed = 80; // Left Rotation Speed
 int RightRotationSpeed = 80; // Right Rotation Speed
 
void setup() {
 pinMode(in1,OUTPUT);
 pinMode(in2,OUTPUT);
 pinMode(in3,OUTPUT);
 pinMode(in4,OUTPUT);
  
  pinMode(en1,OUTPUT);

  pinMode(en2,OUTPUT);
 
   pinMode(A0, INPUT); // initialize Left sensor as an input
   pinMode(A1, INPUT); // initialize Right sensor as an input
}

void loop() {
  // put your main code here, to run repeatedly:
 int LEFT_SENSOR = digitalRead(A0);
 int RIGHT_SENSOR = digitalRead(A1);
  if(RIGHT_SENSOR==0  && LEFT_SENSOR==0) {
  forward(); //FORWARD
 }
 
 else if(RIGHT_SENSOR==0 && LEFT_SENSOR==1) {
   right();
   delay(500); //Move Right
  }
 
  else if(RIGHT_SENSOR==1 && LEFT_SENSOR==0) {
   left(); 
   delay(500);//Move Left
 }
 
  else if(RIGHT_SENSOR==1 && LEFT_SENSOR==1) {
   Stop(); //STOP
 }


}
 
void forward()
{
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
       
        analogWrite(en1, M1_Speed);
        analogWrite(en2, M2_Speed);
}
  
void backward()
{
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
       
        analogWrite(en1, M1_Speed);
        analogWrite(en2, M2_Speed);
}
  
void right()
{
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
       
        analogWrite(en2, LeftRotationSpeed);
        analogWrite(en1, RightRotationSpeed);
}
  
void left()
{
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
       
        analogWrite(en2, LeftRotationSpeed);
        analogWrite(en1, RightRotationSpeed);
}
  
void Stop()
{
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
}
