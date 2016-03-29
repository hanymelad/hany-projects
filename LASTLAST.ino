#include <SoftwareSerial.h>
#include<Servo.h>

SoftwareSerial mySerial(10, 11); // RX, TX

int motor1_forward=2;
int motor2_forward=3;

int motor3_forward=7;
int motor4_forward=8;

int motor1_back=4;
int motor2_back=3;

int motor3_back=12;
int motor4_back=13;


char data;                                // to save data 
Servo myservo;                          // grip servo
Servo servo2;                           // wire servo


void setup()  
{
  
myservo.attach(6);                                            // servo connected pin 9
servo2.attach(9);
pinMode(motor1_forward,OUTPUT); // digital output lik swith 
pinMode(motor2_forward,OUTPUT); // digital out put lik swith
pinMode(motor3_forward,OUTPUT);// digital out put lik swith
pinMode(motor4_forward,OUTPUT); // digital out put lik swith

pinMode(motor1_back,OUTPUT);
pinMode(motor2_back,OUTPUT);
pinMode(motor3_back,OUTPUT);
pinMode(motor4_back,OUTPUT);

                                          // Open serial communications and wait for port to open:      

     Serial.begin(9600);
     Serial.println("Goodnight moon!"); // print in serial monitor  
     mySerial.begin(9600); // comuincat with phone
     mySerial.println("Hello, world?"); // print in phone screen
}
void loop() // run over and over
{
 data= mySerial.read();      // save serial data from phone to variable data
  if (mySerial.available())
    Serial.write(mySerial.read()); // print in serial monitor 
                                  // datA from phone
  if (Serial.available()) 
  mySerial.write(Serial.read()); // print on phone what serial read 
                                  // mean  send einformation back 
  
  if (data=='f') //  motor move forward
  
    {
   
  digitalWrite(motor1_forward,HIGH);
  digitalWrite(motor2_forward,HIGH);
  digitalWrite(motor3_forward,HIGH);
  digitalWrite(motor4_forward,HIGH);

  digitalWrite(motor1_back,LOW);
  digitalWrite(motor2_back,LOW);
  digitalWrite(motor3_back,LOW);
  digitalWrite(motor4_back,LOW);
  
  Serial.println(" motor move forward");
  
  }
 else if(data=='b') // motor move back
  {
  digitalWrite(motor1_forward,LOW);
  digitalWrite(motor2_forward,LOW);
  digitalWrite(motor3_forward,LOW);
  digitalWrite(motor4_forward,LOW);

  digitalWrite(motor1_back,HIGH);
  digitalWrite(motor2_back,HIGH);
  digitalWrite(motor3_back,HIGH);
  digitalWrite(motor4_back,HIGH);
    
  Serial.println("motor move back");
  
  }
  else if(data=='r') // motor move rigt
  {
  digitalWrite(motor1_forward,LOW);
  digitalWrite(motor2_forward,LOW);
  digitalWrite(motor3_forward,HIGH);
  digitalWrite(motor4_forward,HIGH);

  digitalWrite(motor1_back,LOW);
  digitalWrite(motor2_back,LOW);
  digitalWrite(motor3_back,LOW);
  digitalWrite(motor4_back,LOW);
  Serial.println(" motor move rigt");
  
  }
  else if(data=='l') // motor move left 
  {
  digitalWrite(motor1_forward,HIGH);
  digitalWrite(motor2_forward,HIGH);
  digitalWrite(motor3_forward,LOW);
  digitalWrite(motor4_forward,LOW);

  digitalWrite(motor1_back,LOW);
  digitalWrite(motor2_back,LOW);
  digitalWrite(motor3_back,LOW);
  digitalWrite(motor4_back,LOW);
  Serial.println("motor move left");
  
  }
   else if(data=='s') // motor stop 
  {
  digitalWrite(motor1_forward,LOW);
  digitalWrite(motor2_forward,LOW);
  digitalWrite(motor3_forward,LOW);
  digitalWrite(motor4_forward,LOW);

  digitalWrite(motor1_back,LOW);
  digitalWrite(motor2_back,LOW);
  digitalWrite(motor3_back,LOW);
  digitalWrite(motor4_back,LOW);
  Serial.println("motor stop ");
  
  }
   
  else if(data=='q') //   GRIP servo write 0 postion
  {
    myservo.write(0);
    Serial.println(" servo at 0 postion");
  }
   else if(data=='w') // GRIPservo write 90 postion
  {
    myservo.write(90);
    Serial.println(" servo at 90 postion");
  }
       else if(data=='e') //  GRIP servo write 180 postion
  {
    myservo.write(180);
    Serial.println(" servo at 180 postion");
  }
  else if(data=='o') //  WIRE servo write LAST postion
  {
    
    servo2.write(0);
    delay(500);servo2.write(5);
    delay(500);servo2.write(10);
    delay(500);servo2.write(15);
    delay(500);servo2.write(20);
    delay(500);servo2.write(30);
    delay(500);servo2.write(35);
    delay(500);servo2.write(40);
     delay(500);servo2.write(45);
    delay(500);servo2.write(50);
    delay(500);servo2.write(55);
    delay(500);servo2.write(60);
    delay(500);servo2.write(65);
    delay(500);servo2.write(70);
    delay(500);servo2.write(75);
    delay(500);servo2.write(80);
    
    Serial.println("  WIRE servo2 at LAST postion");
  }
   else if(data=='k') // servo write 90 postion
  {
    servo2.write(80);
    delay(500);servo2.write(75);
    delay(500);servo2.write(70);
    delay(500);servo2.write(65);
    delay(500);servo2.write(60);
    delay(500);servo2.write(55);
    delay(500);servo2.write(50);
    delay(500);servo2.write(45);
     delay(500);servo2.write(40);
    delay(500);servo2.write(35);
    delay(500);servo2.write(30);
    delay(500);servo2.write(25);
    delay(500);servo2.write(20);
    delay(500);servo2.write(15);
    delay(500);servo2.write(10);
    delay(500);servo2.write(0);
    
    Serial.println("  WIRE servo2 at FRIST postion");
  }
      
 
  // o first postion      k  last postion
  // x extra           y adtional 
   }
  
   


 
 
