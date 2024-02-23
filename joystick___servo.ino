#include <Servo.h>  
 int valpot = 0; // переменная для хранения значения потенциометра  
 int angleServo = 0; // переменная для хранения угла поворота сервы  
   
 int serv1 = 9; // ПИНЫ ПОДКЛЮЧЕНИЯ СЕРВО 
 int serv2 = 10;  
 int serv3 = 11;  
 int serv4 = 6;  
 
int serv1_pos = 0; // ПАМЯТЬ ПОЗИЦИИ СЕРВО 
int serv2_pos = 0; 
int serv3_pos = 0; 
int serv4_pos = 0; 
 
 
 
 int x_joy1 = 0; 
 int y_joy1 = 1; 
 
 int x_joy2 = 2; // ВСТАВИТЬ ПИНЫ 
 int y_joy2 = 3; //ВСТАВИТЬ ПИНЫ 
 
  
Servo servo1;  
Servo servo2;  
Servo servo3;  
Servo servo4;  
  
  
  
void setup() {  
  Serial.begin(9600);  
 
  servo1.attach(serv1);  
  servo2.attach(serv2);  
  servo3.attach(serv3);  
  servo4.attach(serv4);  
}  
   
void loop() {  
   
  readAndWrite(x_joy1, serv1);  
  readAndWrite(y_joy1, serv2);  
  readAndWrite(x_joy2, serv3);  
  readAndWrite(y_joy2, serv4);  
 
   
  delay(50);  
   
    
    
  }  
 
 
 
  
 
int readAndWrite (int pot, int serv) {  
  valpot = analogRead(pot);  
  // масштабируем значение к интервалу 0-180  
  angleServo=map(valpot,0,1023,0,180);  
  int servo_step = 0; 
  //Serial.println(angleServo); 
  if (angleServo>= 140){servo_step = 5;} 
  else if (angleServo<=40) {servo_step = -5;} 
 
  //Serial.print(pot); 
  //Serial.print(": "); 
  //Serial.println(angleServo); 
 
  //Serial.print(serv1_pos); 
  //Serial.print(", "); 
  if (serv == 9 && serv1_pos+servo_step<=180 && serv1_pos+servo_step >= 0) {serv1_pos += servo_step;}  
  else if (serv == 10 && serv2_pos+servo_step<=180 && serv2_pos+servo_step >= 0) {serv2_pos += servo_step;}  
  else if (serv == 11 && serv3_pos+servo_step<=180 && serv3_pos+servo_step >= 0) {serv3_pos += servo_step;}  
  else if (serv == 6 && serv4_pos+servo_step<=180 && serv4_pos+servo_step >= 0) {serv4_pos += servo_step; Serial.println(serv4_pos);}  
  //Serial.println(serv1_pos); 
 
  servo1.write(serv1_pos); 
  servo2.write(serv2_pos); 
  servo3.write(serv3_pos); 
  servo4.write(serv4_pos); 
    
  return angleServo;    
  }
