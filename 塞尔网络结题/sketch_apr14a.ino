int A=3;//电机1
int PUL_1=7; //define Pulse pin
int DIR_1=6; //define Direction pin

int B=4;//电机2
int PUL_2=9; //define Pulse pin
int DIR_2=8; //define Direction pin

int C=5;//电机3
int PUL_3=11; //define Pulse pin
int DIR_3=10; //define Direction pin

char x;
int a_qu,a_shen,b_qu,b_shen,c_qu,c_shen;

void DaMuZhi_Shen()//大拇指伸
{
 for (int i=0; i<6400; i++)
  {
    digitalWrite(DIR_1,LOW);
    digitalWrite(PUL_1,HIGH);
    delayMicroseconds(100);
    digitalWrite(PUL_1,LOW);
    delayMicroseconds(100);
    a_shen=analogRead(A0);
    Serial.print("DaMuZhi shen")
    Serial.println(a_shen);
   } 
}

void DaMuZhi_Qu()//大拇指曲
{
 for (int i=0; i<6400; i++) 
  {
    digitalWrite(DIR_1,HIGH);
    digitalWrite(PUL_1,HIGH);
    delayMicroseconds(100);
    digitalWrite(PUL_1,LOW);
    delayMicroseconds(100);
    a_qu=analogRead(A0);
    Serial.print("DaMuZhi qu")
    Serial.println(a_qu);
   }
}

void ShiZhi_Shen()//食指伸
{
 for (int i=0; i<6400; i++)
  {
    digitalWrite(DIR_2,LOW);
    digitalWrite(PUL_2,HIGH);
    delayMicroseconds(100);
    digitalWrite(PUL_2,LOW);
    delayMicroseconds(100);
    b_shen=analogRead(A1);
    Serial.print("ShiZhi shen")
    Serial.println(b_shen);
   } 
}

void ShiZhi_Qu()//食指曲
{
 for (int i=0; i<6400; i++) 
  {
    digitalWrite(DIR_2,HIGH);
    digitalWrite(PUL_2,HIGH);
    delayMicroseconds(100);
    digitalWrite(PUL_2,LOW);
    delayMicroseconds(100);
    b_qu=analogRead(A1);
    Serial.print("ShiZhi qu")
    Serial.println(b_qu);
   }
}

void ZhongZhi_Shen()//中指伸
{
 for (int i=0; i<6400; i++)
  {
    digitalWrite(DIR_3,LOW);
    digitalWrite(PUL_3,HIGH);
    delayMicroseconds(100);
    digitalWrite(PUL_3,LOW);
    delayMicroseconds(100);
    c_shen=analogRead(A2);
    Serial.print("ZhongZhi shen")
    Serial.println(c_shen);
   } 
}

void ZhongZhi_Qu()//中指曲
{
 for (int i=0; i<6400; i++) 
  {
    digitalWrite(DIR_3,HIGH);
    digitalWrite(PUL_3,HIGH);
    delayMicroseconds(100);
    digitalWrite(PUL_3,LOW);
    delayMicroseconds(100);
    c_qu=analogRead(A2);
    Serial.print("ZhongZhi qu")
    Serial.println(c_qu);
   }
}

void setup() 
{
 Serial.begin(9600);
 pinMode (PUL_1, OUTPUT);
 pinMode (DIR_1, OUTPUT);
 pinMode (A, OUTPUT);
 
 pinMode (PUL_2, OUTPUT);
 pinMode (DIR_2, OUTPUT);
 pinMode (B, OUTPUT);
 
 pinMode (PUL_3, OUTPUT);
 pinMode (DIR_3, OUTPUT);
 pinMode (C, OUTPUT);
 }

void loop() 
{
 if(Serial.available())
 {
   x=Serial.read();
   switch(x){
    case('a')://大拇指曲指令
     digitalWrite(A,HIGH);
     delay(100);
     DaMuZhi_Qu();
     delay(600);
     digitalWrite(A,LOW);
     break;
     
    case('b')://大拇指伸指令
     digitalWrite(A,HIGH);
     delay(100);
     DaMuZhi_Shen();
     delay(600);
     digitalWrite(A,LOW);
     break;
     
    case('c')://食指曲指令
     digitalWrite(B,HIGH);
     delay(100);
     ShiZhi_Qu();
     delay(600);
     digitalWrite(B,LOW);
     break;
     
    case('d')://食指伸指令
     digitalWrite(B,HIGH);
     delay(100);
     ShiZhi_Shen();
     delay(600);
     digitalWrite(B,LOW);
     break;
     
    case('e')://中指曲指令
     digitalWrite(C,HIGH);
     delay(100);
     ZhongZhi_Qu();
     delay(600);
     digitalWrite(C,LOW);
     break;
     
    case('f')://中指伸指令
     digitalWrite(C,HIGH);
     delay(100);
     ZhongZhi_Shen();
     delay(600);
     digitalWrite(C,LOW);
     break;

    case('g')//全部手指曲指令
     digitalWrite(A,HIGH);//电机1
     delay(100);
     DaMuZhi_Qu();
     delay(600);
     digitalWrite(A,LOW);
     
     digitalWrite(B,HIGH);//电机2
     delay(100);
     ShiZhi_Qu();
     delay(600);
     digitalWrite(B,LOW);
     
     digitalWrite(C,HIGH);//电机3
     delay(100);
     ZhongZhi_Qu();
     delay(600);
     digitalWrite(C,LOW);
     break;

    case('h')//全部手指伸指令
     digitalWrite(A,HIGH);//电机1
     delay(100);
     DaMuZhi_Shen();
     delay(600);
     digitalWrite(A,LOW);
     
     digitalWrite(B,HIGH);//电机2
     delay(100);
     ShiZhi_Shen();
     delay(600);
     digitalWrite(B,LOW);
     
     digitalWrite(C,HIGH);//电机3
     delay(100);
     ZhongZhi_Shen();
     delay(600);
     digitalWrite(C,LOW);
     break;
     
    default:
     break;
   }
 }
}
