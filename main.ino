                 //coded by neamatullah-JRC


#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial BT_Serial(2, 3); // RX, TX


Servo lefthand;
Servo righthand;
Servo head;

 
#define in1 8 //Motor1  L298 Pin in1 
#define in2 7 //Motor1  L298 Pin in1 
#define in3 6 //Motor2  L298 Pin in1 
#define in4 5 //Motor2  L298 Pin in1 


int bt_ir_data; // variable to receive data from the serial port and IRremote


void setup(){ // put your setup code here, to run once

pinMode(in1, OUTPUT); // declare as output for L298 Pin in1 
pinMode(in2, OUTPUT); // declare as output for L298 Pin in2 
pinMode(in3, OUTPUT); // declare as output for L298 Pin in3   
pinMode(in4, OUTPUT); // declare as output for L298 Pin in4 

lefthand.attach(9);
righthand.attach(10);
head.attach(11);

lefthand.write(90);
righthand.write(90);
head.write(90);

Serial.begin(9600);
BT_Serial.begin(9600); 
}


void loop(){  
if(BT_Serial.available() > 0){  //if some date is sent, reads it and saves in state     
bt_ir_data = BT_Serial.read(); 
Serial.println(bt_ir_data);     
      
}

 
  if(bt_ir_data == 1){forword(); }  // if the bt_data is '1' the DC motor will go forward
else if(bt_ir_data == 2){backword();}  // if the bt_data is '2' the motor will Reverse
else if(bt_ir_data == 3){turnLeft();}  // if the bt_data is '3' the motor will turn left
else if(bt_ir_data == 4){turnRight();} // if the bt_data is '4' the motor will turn right
else if(bt_ir_data == 5){Stop(); }     // if the bt_data '5' the motor will Stop

else if(bt_ir_data == 6){turnLeft();  delay(400);  bt_ir_data = 5;}
else if(bt_ir_data == 7){turnRight(); delay(400);  bt_ir_data = 5;}
/*
else if(bt_ir_data == 8) //both
{
  lefthand.write(90);
  righthand.write(90);
  delay(1000);
  lefthand.write(0);
  righthand.write(0);
}
else if(bt_ir_data == 9)//left
{
  lefthand.write(90);
  delay(1000);
  lefthand.write(0);
}
else if(bt_ir_data == 10)//right
{
  righthand.write(90);
  delay(1000);
  lefthand.write(0);
}
else if(bt_ir_data == 11)//look left
{
  head.write(0);
}
else if(bt_ir_data == 12)//look forward
{
  head.write(90);
}
else if(bt_ir_data == 13)//look right
{
  head.write(180);
}
  */



delay(10);
}



void forword(){  //forword

digitalWrite(in1, HIGH); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 

 
}

void backword(){ //backword

digitalWrite(in1, LOW);  //Right Motor forword Pin 
digitalWrite(in2, HIGH); //Right Motor backword Pin 
digitalWrite(in3, HIGH); //Left Motor backword Pin 
digitalWrite(in4, LOW);  //Left Motor forword Pin 
 
}

void turnRight(){ //turnRight

digitalWrite(in1, LOW);  //Right Motor forword Pin 
digitalWrite(in2, HIGH); //Right Motor backword Pin  
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 

  
}
void turnLeft(){ //turnRight

digitalWrite(in1, LOW);  //Right Motor forword Pin 
digitalWrite(in2, HIGH); //Right Motor backword Pin  
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 

}
void Stop(){ //stop

digitalWrite(in1, LOW); //Right Motor forword Pin 
digitalWrite(in2, LOW); //Right Motor backword Pin 
digitalWrite(in3, LOW); //Left Motor backword Pin 
digitalWrite(in4, LOW); //Left Motor forword Pin 
}
