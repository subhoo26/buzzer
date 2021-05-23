const int button1=8;  //user1
const int button2=9;  //user2
const int button3=10;  //user3
const int button4=11;  //user4
const int button5=12;  //reset
int led1=2; //user1
int led2=3;  //user2
int led3=4;  //user3
int led4=5;  //user4
int led5=6;   //reset
int buzz=13;    //buzzer
int bs1;  //reference varible for user1
int bs2;  //reference variable for user2
int bs3;  //RV for user3
int bs4;  //RV for user4
int bs5;   //refernce variable for reset
unsigned char flag = 0;

void setup()
{
  pinMode(button1,INPUT_PULLUP);
  pinMode(button2,INPUT_PULLUP);
  pinMode(button3,INPUT_PULLUP);
  pinMode(button4,INPUT_PULLUP);
  pinMode(button5,INPUT_PULLUP);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(buzz,OUTPUT);
  Serial.begin(19200);
}

void loop()
{ 
  bs5=1;
  digitalWrite(led1,1);
  digitalWrite(led2,1);
  digitalWrite(led3,1);
  digitalWrite(led4,1);
  digitalWrite(led5,0);
  bs5=digitalRead(button5);
  
  if(bs5==0)        //reset switch on
  {
    flag=1;
    Serial.println("READY");
    digitalWrite(led5,0);
    digitalWrite(buzz,1);
    Serial.println("reset buzz on");
    delay(50);
    digitalWrite(buzz,0);
    Serial.println("reset buzz off");
   }
  
  if(flag==1)
  {
    bs1=digitalRead(button1);
    bs2=digitalRead(button2);
    bs3=digitalRead(button3);
    bs4=digitalRead(button4);
    
    if(bs1==0)      //condition for 1st button
    {
      flag=1;
      digitalWrite(led5,1);
      Serial.println("1 PRESSED");
      digitalWrite(buzz,1);
      Serial.println("buzzer on");
      digitalWrite(led1,0);
      digitalWrite(led2,1);
      digitalWrite(led3,1);
      digitalWrite(led4,1);
      delay(800);
      digitalWrite(buzz,0);
      Serial.println("buzzer off");
      while(digitalRead(button5));      //loop till button5 i.e. reset is 1
    }
    
    if(bs2==0)      //condition for second button
    {
      flag=1;
      digitalWrite(led5,1);
      Serial.println("2 PRESSED");
      digitalWrite(buzz,1);
      Serial.println("buzz on");
      digitalWrite(led1,1);
      digitalWrite(led2,0);
      digitalWrite(led3,1);
      digitalWrite(led4,1);
      delay(800);
      digitalWrite(buzz,0);
      Serial.println("buzz off");
      while(digitalRead(button5));
    }
    
    if(bs3==0)        //condition for third button
    {
      flag=1;
      digitalWrite(led5,1);
      Serial.println("3 PRESSED");
      digitalWrite(buzz,1);
      Serial.println("buzz on");
      digitalWrite(led1,1);
      digitalWrite(led2,1);
      digitalWrite(led3,0);
      digitalWrite(led4,1);
      delay(800);
      digitalWrite(buzz,0);
      Serial.println("buzz off");
      while(digitalRead(button5));
    }
    
    if(bs4==0)        //condition for forth button
    {
      flag=1;
      digitalWrite(led5,1);
      Serial.println("4 PRESSED");
      digitalWrite(buzz,1);
      Serial.println("buzz on");
      digitalWrite(led1,1);
      digitalWrite(led2,1);
      digitalWrite(led3,1);
      digitalWrite(led4,0);
      delay(800);
      digitalWrite(buzz,0);
      Serial.println("buzz off");
      while(digitalRead(button5));
    }
  }
}
