#include <Servo.h>  
 int valpot = 0; // переменная для хранения значения потенциометра  
 int angleServo = 0; // переменная для хранения угла поворота сервы  
   
 int serv1 = 9; // ПИНЫ ПОДКЛЮЧЕНИЯ СЕРВО 
 int serv2 = 10;  
 int serv3 = 11;  
 int serv4 = 6;  
 int serv5 = 5;  
 int serv6 = 3;
 
int serv1_pos = 0; // ПАМЯТЬ ПОЗИЦИИ СЕРВО 
int serv2_pos = 0; // При включении Ардуино все сервопривода принимают нулевую позицию
int serv3_pos = 0; // Из-за этого робота крючит, эту начальную позицую можно здесь поменять на любое 0-180
int serv4_pos = 0; 
int serv5_pos = 0; 
int serv6_pos = 0; 
 
 
 
 int x_joy1 = 0; // A0 - сюда подключаем Х первого джойстика
 int y_joy1 = 1; // A1 - сюда подключаем Y первого джойстика
 
 int x_joy2 = 2; // A2 - сюда подключаем Х второго джойстика
 int y_joy2 = 3; // A3 сюда подключаем Y второго джойстика
 
 int x_joy3 = 4;  // A4 - сюда подключаем Х третьего джойстика
 int y_joy3 = 5; // A5 - сюда подключаем Y третьего джойстика

int button = 2; // Просто пин 2; это кнопка, по которой робот делает запрограммированные движения. На ее место можно подключить кнопку  одного из джостика, но мне кажется, что будет приколней, если сделать отдельную кнопку 
  
Servo servo1;  
Servo servo2;  
Servo servo3;  
Servo servo4;  
Servo servo5;  
Servo servo6;  
  
  
  
void setup() {  
  Serial.begin(9600);  
 
  servo1.attach(serv1);  
  servo2.attach(serv2);  
  servo3.attach(serv3);  
  servo4.attach(serv4);  
  servo4.attach(serv5);  
  servo4.attach(serv6);  
  
  pinMode(button, INPUT);
}  
   
void loop() {  
   
  readAndWrite(x_joy1, serv1);  
  readAndWrite(y_joy1, serv2);  
  
  readAndWrite(x_joy2, serv3);  
  readAndWrite(y_joy2, serv4); 
   
  readAndWrite(x_joy3, serv5);  
  readAndWrite(y_joy3, serv6);  

  if (digitalRead(button)) { // Если нажали кнопка
    autoMode(); // Запускаем запрограммированные движения
    }
 
   
  delay(50);  
    
  }  
  
int readAndWrite (int pot, int serv) {  
  valpot = analogRead(pot);  
  // масштабируем значение к интервалу 0-180  
  angleServo=map(valpot,0,1023,0,180);  
  int servo_step = 0; 
 
  if (angleServo>= 140){servo_step = 5;} 
  else if (angleServo<=40) {servo_step = -5;} 
 
  if (serv == 9 && serv1_pos+servo_step<=180 && serv1_pos+servo_step >= 0) {serv1_pos += servo_step; Serial.print("Текущая коодината 1 серво: "); Serial.println(serv1_pos);}  
  else if (serv == 10 && serv2_pos+servo_step<=180 && serv2_pos+servo_step >= 0) {serv2_pos += servo_step; Serial.print("Текущая коодината 2 серво: "); Serial.println(serv2_pos);}  
  else if (serv == 11 && serv3_pos+servo_step<=180 && serv3_pos+servo_step >= 0) {serv3_pos += servo_step; Serial.print("Текущая коодината 3 серво: "); Serial.println(serv3_pos);}  
  else if (serv == 6 && serv4_pos+servo_step<=180 && serv4_pos+servo_step >= 0) {serv4_pos += servo_step; Serial.print("Текущая коодината 4 серво: "); Serial.println(serv4_pos);}  
  else if (serv == 5 && serv5_pos+servo_step<=180 && serv5_pos+servo_step >= 0) {serv5_pos += servo_step; Serial.print("Текущая коодината 5 серво: "); Serial.println(serv5_pos);}  
  else if (serv == 3 && serv6_pos+servo_step<=180 && serv6_pos+servo_step >= 0) {serv6_pos += servo_step; Serial.print("Текущая коодината 6 серво: "); Serial.println(serv6_pos);}  
  
 
  servo1.write(serv1_pos); 
  servo2.write(serv2_pos); 
  servo3.write(serv3_pos); 
  servo4.write(serv4_pos); 
    
  return angleServo;    
  }

int autoMode() { ////////////// ЭТУ ХРЕНЬ ДОДЕЛАТЬ, ВПИСАТЬ КООРДИНАТЫ ПО КОТОРЫМ ДОЛЖЕН ДВИНАТЬСЯ РОБОТ!!!!


  /* ЭТО ПЕРВАЯ ПОЗИЦИЯ */
  servo1.write(0); // В скобки вписать КООРДИНАТУ ПЕРВОГО серво
  servo2.write(0); // В скобки вписать КООРДИНАТУ ВТОРОГО серво
  servo3.write(0); // В скобки вписать КООРДИНАТУ ТРЕТЬЕГО серво
  servo4.write(0); // В скобки вписать КООРДИНАТУ ЧЕТВЕРТОГО серво
  servo5.write(0); // В скобки вписать КООРДИНАТУ ПЯТОГО серво
  servo6.write(0); // В скобки вписать КООРДИНАТУ ШЕСТОГО серво

  delay(1000); // Секундная задержка
  
  /* ЭТО ВТОРАЯ ПОЗИЦИЯ */
  servo1.write(0); // В скобки вписать КООРДИНАТУ ПЕРВОГО серво
  servo2.write(0); // В скобки вписать КООРДИНАТУ ВТОРОГО серво
  servo3.write(0); // В скобки вписать КООРДИНАТУ ТРЕТЬЕГО серво
  servo4.write(0); // В скобки вписать КООРДИНАТУ ЧЕТВЕРТОГО серво
  servo5.write(0); // В скобки вписать КООРДИНАТУ ПЯТОГО серво
  servo6.write(0); // В скобки вписать КООРДИНАТУ ШЕСТОГО серво

  
  /* И ТАК ПРОДОЛЖАТЬ СКОЛЬКО НУЖНО ПОЗИЦИЙ 
    ЗАДЕРЖКУ МОЖНО МЕНЯТЬ, НО НЕ СТАВЬТЕ СИЛЬНО МАЛЕНЬКУЮ */
  
  }
