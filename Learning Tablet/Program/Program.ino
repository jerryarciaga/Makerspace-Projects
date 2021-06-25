#include "SD.h"
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm X;

int Duck_B_LED     = 22; int Duck_Y_LED    = 23;
int Turtles_G_LED  = 24; int Turtles_B_LED = 25; 
int Fish_B_LED     = 26; int Fish_W_LED    = 27;
int Frog_G_LED     = 28; int Frog_Y_LED    = 29;
int End_R_LED      = 30; int End_B_LED     = 31;
int Start_LED      = 32; int One_LED       = 33;
int Two_LED        = 34; int Three_LED     = 35;
int Four_LED       = 36; int Five_LED      = 37;
int Six_LED        = 38; int Seven_LED     = 39;
int Eight_LED      = 40; int Nine_LED      = 41;
int Ten_LED        = 42; 
                         int Duck_Button   = 43; 
int Turtles_Button = 44; int Fish_Button   = 45;
int Frog_Button    = 3;  int Start_Button  = 47;
int End_Button     = 48; int One_Button    = 49;
int Two_Button     = 2;  int Three_Button  = 4;
int Four_Button    = 6;  int Five_Button   = 5;
int Six_Button     = A0; int Seven_Button  = A1;
int Eight_Button   = A2; int Nine_Button   = A3;
int Ten_Button     = A4;

int None_Pin       = 7;

//SD Card and Speaker 
// CS to 53 | SpeakerPin to 46



void setup() {
 pinMode(Duck_B_LED, OUTPUT);     pinMode(Duck_Y_LED, OUTPUT);
 pinMode(Turtles_G_LED, OUTPUT);  pinMode(Turtles_B_LED, OUTPUT);
 pinMode(Fish_B_LED, OUTPUT);     pinMode(Fish_W_LED, OUTPUT);
 pinMode(Frog_G_LED, OUTPUT);     pinMode(Frog_Y_LED, OUTPUT);
 pinMode(End_R_LED, OUTPUT);      pinMode(End_B_LED, OUTPUT);
 pinMode(Start_LED, OUTPUT);      pinMode(One_LED, OUTPUT);
 pinMode(Two_LED, OUTPUT);        pinMode(Three_LED, OUTPUT);
 pinMode(Four_LED, OUTPUT);       pinMode(Five_LED, OUTPUT);
 pinMode(Six_LED, OUTPUT);        pinMode(Seven_LED, OUTPUT);
 pinMode(Eight_LED, OUTPUT);      pinMode(Nine_LED, OUTPUT);
 pinMode(Ten_LED, OUTPUT);        pinMode(Duck_Button, INPUT);
 pinMode(Turtles_Button, INPUT);  pinMode(Fish_Button, INPUT);
 pinMode(Frog_Button, INPUT);     pinMode(Start_Button, INPUT);
 pinMode(End_Button, INPUT);      pinMode(One_Button, INPUT);
 pinMode(Two_Button, INPUT);      pinMode(Three_Button, INPUT);
 pinMode(Four_Button, INPUT);     pinMode(Five_Button, INPUT);
 pinMode(Six_Button, INPUT);      pinMode(Seven_Button, INPUT);
 pinMode(Eight_Button, INPUT);    pinMode(Nine_Button, INPUT);
 pinMode(Ten_Button, INPUT);      

 X.speakerPin = 46; 
 X.setVolume(5);

   Serial.begin(9600);
  if(!SD.begin(53)){
    Serial.println("ERROR WITH SD CARD");
    return;
  }
 
} 
bool None = false;
bool Start = false; 
bool One = false;
bool Two = false;
bool Three = false;
bool Four = false;
bool Five = false;
bool Six = false;
bool Seven = false;
bool Eight = false;
bool Nine = false;
bool Ten = false;
bool End = false;
int Timing = 0;
int I = 1;

void loop() {
  
  switch (Read_Keyboard()){
    case 0: // Start 15 Seconds
      Startup_Sequence();
      delay(1500);
      Reset();
      Start = true;
      break;
      
    case 1: // Duck
    if(Start == false) break;
      digitalWrite(Duck_B_LED, HIGH); digitalWrite(Duck_Y_LED, HIGH); 
      X.play("Duck.wav"); // Audio length: 7 Seconds
      delay(8000);
      digitalWrite(Duck_B_LED, LOW);  digitalWrite(Duck_Y_LED, LOW);
      break;
      
    case 2: // Turtles
    if(Start == false) break;
      digitalWrite(Turtles_G_LED, HIGH); digitalWrite(Turtles_B_LED, HIGH); 
      X.play("Turtles.wav"); // Audio length: 8 Seconds
      delay(9000);
      digitalWrite(Turtles_G_LED, LOW);  digitalWrite(Turtles_B_LED, LOW);
      break;
      
    case 3: // Fish
    if(Start == false) break;
      digitalWrite(Fish_B_LED, HIGH); digitalWrite(Fish_W_LED, HIGH); 
      X.play("Fish.wav"); // Audio lenght: 14 Seconds
      delay(15000);
      digitalWrite(Fish_B_LED, LOW);  digitalWrite(Fish_W_LED, LOW);
      break;
      
    case 4: // Frog
    if(Start == false) break;
      digitalWrite(Frog_G_LED, HIGH); digitalWrite(Frog_Y_LED, HIGH); 
      X.play("Frog.wav"); // Audio length: 12 Seconds    
      delay(13000);
      break;
            digitalWrite(Frog_G_LED, LOW);  digitalWrite(Frog_Y_LED, LOW);

    case 5: // One
    if(Start == false) break;
    if(Verify_Sequence() != One_LED){Sequence_Wrong(); break;}
      X.play("N1.wav"); // Audio length: 17 Seconds
      Sequence_One();
      LEDs_Off();
      One = true;
      break;
      
    case 6: // Two
    if(Start == false) break;
    if(Verify_Sequence() != Two_LED ){Sequence_Wrong(); break;}
      X.play("N2.wav"); // Audio length: 17 Seconds    
      Sequence_One();
      LEDs_Off();
      Two = true;
      break;
      
    case 7: // Three
    if(Start == false) break;
    if(Verify_Sequence() != Three_LED){Sequence_Wrong(); break;}
      X.play("N3.wav"); // Audio length: 12 Seconds 
      Sequence_Two();   
      LEDs_Off();
      Three = true;
      break;
      
    case 8: // Four
    if(Start == false) break;
    if(Verify_Sequence() != Four_LED){Sequence_Wrong(); break;}
      X.play("N4.wav"); // Audio length: 12 Seconds    
      Sequence_Two();   
      LEDs_Off();
      Four = true;
      break;
      
    case 9: // Five
    if(Start == false) break;
    if(Verify_Sequence() != Five_LED){Sequence_Wrong(); break;}
      X.play("N5.wav"); // Audio length: 12 Seconds    
      Sequence_Three();
      LEDs_Off();
      Five = true;
      break;
      
    case 10: // Six
    if(Start == false) break;
    if(Verify_Sequence() != Six_LED){Sequence_Wrong(); break;}
      X.play("N6.wav"); // Audio length: 12 Seconds    
      Sequence_Three();
      LEDs_Off();
      Six = true;    
      break;
      
    case 11: // Seven
    if(Start == false) break;
    if(Verify_Sequence() != Seven_LED){Sequence_Wrong(); break;}
      X.play("N7.wav"); // Audio length: 12 Seconds    
      Sequence_Three();
      LEDs_Off();
      Seven = true;
      break;
      
    case 12: // Eight
    if(Start == false) break;
    if(Verify_Sequence() != Eight_LED){Sequence_Wrong(); break;}
      X.play("N8.wav"); // Audio length: 6 Seconds    
      Sequence_Four();
      LEDs_Off();
      Eight = true;
      break;
      
    case 13: // Nine
    if(Start == false) break;
    if(Verify_Sequence() != Nine_LED){Sequence_Wrong(); break;}
      X.play("N9.wav"); // Audio length: 12 Seconds    
      Sequence_Three();
      LEDs_Off();
      Nine = true;
      break;
      
    case 14: // Ten
    if(Start == false) break;
    if(Verify_Sequence() != Ten_LED){Sequence_Wrong(); break;}
      X.play("N10.wav"); // Audio length: 17 Seconds    
      Sequence_One();
      LEDs_Off();
      Ten = true;    
      break;
      
    case 15: // End
      if(Start == false) break;
      digitalWrite(End_R_LED, HIGH);   digitalWrite(End_B_LED, HIGH);
      LEDs_Off();
      Reset();
      X.play("End.wav"); // Audio length: 8 Seconds    
      LEDs_Off();
      End = true;
      break;
      
  default: 
      digitalWrite(Verify_Sequence(), HIGH);
    break;
  }




}
/////////////////////////////////////////////          FUNCTIONS          ////////////////////////////////////////////////////////////////
int Read_Keyboard(){
   if(digitalRead(Start_Button))   {return 0;}
   if(digitalRead(Duck_Button))    {return 1;}
   if(digitalRead(Turtles_Button)) {return 2;}
   if(digitalRead(Fish_Button))    {return 3;}
   if(digitalRead(Frog_Button))    {return 4;}
   if(digitalRead(One_Button))     {return 5;}
   if(digitalRead(Two_Button))     {return 6;}
   if(digitalRead(Three_Button))   {return 7;}
   if(digitalRead(Four_Button))    {return 8;}
   if(digitalRead(Five_Button))    {return 9;}
   if(digitalRead(Six_Button))     {return 10;}
   if(digitalRead(Seven_Button))   {return 11;}
   if(digitalRead(Eight_Button))   {return 12;}
   if(digitalRead(Nine_Button))    {return 13;}
   if(digitalRead(Ten_Button))     {return 14;}
   if(digitalRead(End_Button))     {return 15;}
 return 16;
}

int Verify_Sequence(){
  if (Start == true && One == false)  {return One_LED;}
  if (One == true && Two == false)    {return Two_LED;}
  if (Two == true && Three == false)  {return Three_LED;}
  if (Three == true && Four == false) {return Four_LED;}
  if (Four == true && Five == false)  {return Five_LED;}
  if (Five == true && Six == false)   {return Six_LED;}
  if (Six == true && Seven == false)  {return Seven_LED;}
  if (Seven == true && Eight == false){return Eight_LED;}
  if (Eight == true && Nine == false) {return Nine_LED;}
  if (Nine == true && Ten == false)   {return Ten_LED;}
  if (Ten == true)                    {return End_R_LED;}
  return None_Pin;
}

void Reset(){
 Start = false; 
 One   = false;
 Two   = false;
 Three = false;
 Four  = false;
 Five  = false;
 Six   = false;
 Seven = false;
 Eight = false;
 Nine  = false;
 Ten   = false;
 End   = false;
}

void LEDs_Off(){
  digitalWrite(One_LED, LOW);
  digitalWrite(Two_LED, LOW);
  digitalWrite(Three_LED, LOW);
  digitalWrite(Four_LED, LOW);
  digitalWrite(Five_LED, LOW);
  digitalWrite(Six_LED, LOW);
  digitalWrite(Seven_LED, LOW);
  digitalWrite(Eight_LED, LOW);
  digitalWrite(Nine_LED, LOW);
  digitalWrite(Ten_LED, LOW);
  digitalWrite(End_R_LED, LOW);   
  digitalWrite(End_B_LED, LOW);
}
/////////////////////////////////////////////          SEQUENCES          ////////////////////////////////////////////////////////////////

void Startup_Sequence(){  /////////////////// START SEQUENCE ///////////////////////////
  X.play("Start.wav");
  digitalWrite (Start_LED, HIGH); delay(400); digitalWrite (Start_LED, LOW);
  
  for (int i=22; i<43; i++){
    digitalWrite (i, HIGH);
    delay(50);
    digitalWrite (i, LOW);
  }

  for (int i=0; i<4; i++){
    digitalWrite(Duck_B_LED, HIGH); digitalWrite(Turtles_G_LED, HIGH); digitalWrite(Frog_G_LED, HIGH); digitalWrite(Fish_B_LED, HIGH); delay(200);
    digitalWrite(Duck_B_LED, LOW);  digitalWrite(Turtles_G_LED, LOW);  digitalWrite(Frog_G_LED, LOW);  digitalWrite(Fish_B_LED, LOW);
    digitalWrite(Duck_Y_LED, HIGH); digitalWrite(Turtles_B_LED, HIGH); digitalWrite(Frog_Y_LED, HIGH); digitalWrite(Fish_W_LED, HIGH); delay(200);
    digitalWrite(Duck_Y_LED, LOW);  digitalWrite(Turtles_B_LED, LOW);  digitalWrite(Frog_Y_LED, LOW);  digitalWrite(Fish_W_LED, LOW);
  }

  for (int i=0; i<5; i++){
    digitalWrite(One_LED, HIGH); digitalWrite(Two_LED, HIGH);   digitalWrite(Three_LED, HIGH); digitalWrite(Four_LED, HIGH); digitalWrite(Five_LED, HIGH); delay(200);
    digitalWrite(One_LED, LOW);  digitalWrite(Two_LED, LOW);    digitalWrite(Three_LED, LOW);  digitalWrite(Four_LED, LOW);  digitalWrite(Five_LED, LOW);
    digitalWrite(Six_LED, HIGH); digitalWrite(Seven_LED, HIGH); digitalWrite(Eight_LED, HIGH); digitalWrite(Nine_LED, HIGH); digitalWrite(Ten_LED, HIGH);  delay(200);
    digitalWrite(Six_LED, LOW);  digitalWrite(Seven_LED, LOW);  digitalWrite(Eight_LED, LOW);  digitalWrite(Nine_LED, LOW);  digitalWrite(Ten_LED, LOW);
  }

  for (int i=0; i<4; i++){
    digitalWrite(Duck_B_LED, HIGH); digitalWrite(Turtles_G_LED, HIGH); digitalWrite(Frog_G_LED, HIGH); digitalWrite(Fish_B_LED, HIGH); delay(200);
    digitalWrite(Duck_B_LED, LOW);  digitalWrite(Turtles_G_LED, LOW);  digitalWrite(Frog_G_LED, LOW);  digitalWrite(Fish_B_LED, LOW);
    digitalWrite(Duck_Y_LED, HIGH); digitalWrite(Turtles_B_LED, HIGH); digitalWrite(Frog_Y_LED, HIGH); digitalWrite(Fish_W_LED, HIGH); delay(200);
    digitalWrite(Duck_Y_LED, LOW);  digitalWrite(Turtles_B_LED, LOW);  digitalWrite(Frog_Y_LED, LOW);  digitalWrite(Fish_W_LED, LOW);
  }

  for (int i=0; i<5; i++){
    digitalWrite(One_LED, HIGH); digitalWrite(Two_LED, HIGH);   digitalWrite(Three_LED, HIGH); digitalWrite(Four_LED, HIGH); digitalWrite(Five_LED, HIGH); delay(200);
    digitalWrite(One_LED, LOW);  digitalWrite(Two_LED, LOW);    digitalWrite(Three_LED, LOW);  digitalWrite(Four_LED, LOW);  digitalWrite(Five_LED, LOW);
    digitalWrite(Six_LED, HIGH); digitalWrite(Seven_LED, HIGH); digitalWrite(Eight_LED, HIGH); digitalWrite(Nine_LED, HIGH); digitalWrite(Ten_LED, HIGH);  delay(200);
    digitalWrite(Six_LED, LOW);  digitalWrite(Seven_LED, LOW);  digitalWrite(Eight_LED, LOW);  digitalWrite(Nine_LED, LOW);  digitalWrite(Ten_LED, LOW);
  }

  for (int i=0; i<1; i++){
    digitalWrite(Duck_B_LED, HIGH); digitalWrite(Turtles_G_LED, HIGH); digitalWrite(Frog_G_LED, HIGH); digitalWrite(Fish_B_LED, HIGH); delay(200);
    digitalWrite(Duck_B_LED, LOW);  digitalWrite(Turtles_G_LED, LOW);  digitalWrite(Frog_G_LED, LOW);  digitalWrite(Fish_B_LED, LOW);
    digitalWrite(Duck_Y_LED, HIGH); digitalWrite(Turtles_B_LED, HIGH); digitalWrite(Frog_Y_LED, HIGH); digitalWrite(Fish_W_LED, HIGH); delay(200);
    digitalWrite(Duck_Y_LED, LOW);  digitalWrite(Turtles_B_LED, LOW);  digitalWrite(Frog_Y_LED, LOW);  digitalWrite(Fish_W_LED, LOW);
  }

    delay(750);
      
  for (int i=0; i<3; i++){
    digitalWrite(One_LED, HIGH); digitalWrite(Two_LED, HIGH);   digitalWrite(Three_LED, HIGH); digitalWrite(Four_LED, HIGH); digitalWrite(Five_LED, HIGH);
    digitalWrite(Six_LED, HIGH); digitalWrite(Seven_LED, HIGH); digitalWrite(Eight_LED, HIGH); digitalWrite(Nine_LED, HIGH); digitalWrite(Ten_LED, HIGH);  delay(200);
    digitalWrite(One_LED, LOW);  digitalWrite(Two_LED, LOW);    digitalWrite(Three_LED, LOW);  digitalWrite(Four_LED, LOW);  digitalWrite(Five_LED, LOW);
    digitalWrite(Six_LED, LOW);  digitalWrite(Seven_LED, LOW);  digitalWrite(Eight_LED, LOW);  digitalWrite(Nine_LED, LOW);  digitalWrite(Ten_LED, LOW);   delay(200);
  }

    delay(2000);

  for (int i=0; i<3; i++){
    digitalWrite(Duck_B_LED, HIGH); digitalWrite(Turtles_G_LED, HIGH); digitalWrite(Frog_G_LED, HIGH); digitalWrite(Fish_B_LED, HIGH);
    digitalWrite(Duck_Y_LED, HIGH); digitalWrite(Turtles_B_LED, HIGH); digitalWrite(Frog_Y_LED, HIGH); digitalWrite(Fish_W_LED, HIGH); delay(200);
    digitalWrite(Duck_B_LED, LOW);  digitalWrite(Turtles_G_LED, LOW);  digitalWrite(Frog_G_LED, LOW);  digitalWrite(Fish_B_LED, LOW);
    digitalWrite(Duck_Y_LED, LOW);  digitalWrite(Turtles_B_LED, LOW);  digitalWrite(Frog_Y_LED, LOW);  digitalWrite(Fish_W_LED, LOW);  delay(300);
  }
  
}

void Sequence_One(){    /////////////////// 17 SEC SEQUENCE ///////////////////////////
  int T = 200; int T2 = 100;
  LEDs_Off();
  for (int i=0; i<2; i++){
     digitalWrite(Duck_B_LED,HIGH);    delay(T);    digitalWrite(Duck_B_LED,LOW);    delay(T2);    digitalWrite(Duck_Y_LED,HIGH);    delay(T);    digitalWrite(Duck_Y_LED,LOW);    delay(T2);
     digitalWrite(One_LED,HIGH);       delay(T);    digitalWrite(One_LED,LOW);       delay(T2);    digitalWrite(Two_LED,HIGH);       delay(T);    digitalWrite(Two_LED,LOW);       delay(T2);
     digitalWrite(Three_LED,HIGH);     delay(T);    digitalWrite(Three_LED,LOW);     delay(T2);    digitalWrite(Four_LED,HIGH);      delay(T);    digitalWrite(Four_LED,LOW);      delay(T2);
     digitalWrite(Five_LED,HIGH);      delay(T);    digitalWrite(Five_LED,LOW);      delay(T2);    digitalWrite(Turtles_B_LED,HIGH); delay(T);    digitalWrite(Turtles_B_LED,LOW); delay(T2);
     digitalWrite(Turtles_G_LED,HIGH); delay(T);    digitalWrite(Turtles_G_LED,LOW); delay(T2);    digitalWrite(Ten_LED,HIGH);       delay(T);    digitalWrite(Ten_LED,LOW);       delay(T2);
     digitalWrite(Nine_LED,HIGH);      delay(T);    digitalWrite(Nine_LED,LOW);      delay(T2);    digitalWrite(Eight_LED,HIGH);     delay(T);    digitalWrite(Eight_LED,LOW);     delay(T2);
     digitalWrite(Seven_LED,HIGH);     delay(T);    digitalWrite(Seven_LED,LOW);     delay(T2);    digitalWrite(Six_LED,HIGH);       delay(T);    digitalWrite(Six_LED,LOW);       delay(T2);
     digitalWrite(Fish_B_LED,HIGH);    delay(T);    digitalWrite(Fish_B_LED,LOW);    delay(T2);    digitalWrite(Fish_W_LED,HIGH);    delay(T);    digitalWrite(Fish_W_LED,LOW);    delay(T2);
     digitalWrite(Start_LED,HIGH);     delay(T);    digitalWrite(Start_LED,LOW);     delay(T2);    
     digitalWrite(End_R_LED,HIGH);     delay(T);    digitalWrite(End_R_LED,LOW);     delay(T2);    digitalWrite(End_B_LED,HIGH);     delay(T);    digitalWrite(End_B_LED,LOW);     delay(T2);
     digitalWrite(Frog_G_LED,HIGH);    delay(T);    digitalWrite(Frog_G_LED,LOW);    delay(T2);    digitalWrite(Frog_Y_LED,HIGH);    delay(T);    digitalWrite(Frog_Y_LED,LOW);    delay(T2);
  }

     digitalWrite(Duck_B_LED,HIGH);    delay(T);    digitalWrite(Duck_B_LED,LOW);    delay(T2);    digitalWrite(Duck_Y_LED,HIGH);    delay(T);    digitalWrite(Duck_Y_LED,LOW);    delay(T2);
     digitalWrite(One_LED,HIGH);       delay(T);    digitalWrite(One_LED,LOW);       delay(T2);    digitalWrite(Two_LED,HIGH);       delay(T);    digitalWrite(Two_LED,LOW);       delay(T2);
     digitalWrite(Three_LED,HIGH);     delay(T);    digitalWrite(Three_LED,LOW);     delay(T2);    digitalWrite(Four_LED,HIGH);      delay(T);    digitalWrite(Four_LED,LOW);      delay(T2);
     digitalWrite(Five_LED,HIGH);      delay(T);    digitalWrite(Five_LED,LOW);      delay(T2);    digitalWrite(Turtles_B_LED,HIGH); delay(T);    digitalWrite(Turtles_B_LED,LOW); delay(T2);
     digitalWrite(Turtles_G_LED,HIGH); delay(T);    digitalWrite(Turtles_G_LED,LOW); delay(T2);    digitalWrite(Ten_LED,HIGH);       delay(T);    digitalWrite(Ten_LED,LOW);       delay(T2);
     digitalWrite(Nine_LED,HIGH);      delay(T);    digitalWrite(Nine_LED,LOW);      delay(T2);    digitalWrite(Eight_LED,HIGH);     delay(T);    digitalWrite(Eight_LED,LOW);     delay(T2);
}

void Sequence_Two(){       /////////////////// 12 SEC SEQUENCE ///////////////////////////
  int T = 200; int T2 = 100;
  LEDs_Off();
     digitalWrite(Frog_Y_LED,HIGH);    delay(T);    digitalWrite(Frog_Y_LED,LOW);    delay(T2);    digitalWrite(Frog_G_LED,HIGH);    delay(T);    digitalWrite(Frog_G_LED,LOW);    delay(T2);
     digitalWrite(End_B_LED,HIGH);     delay(T);    digitalWrite(End_B_LED,LOW);     delay(T2);    digitalWrite(End_R_LED,HIGH);     delay(T);    digitalWrite(End_R_LED,LOW);     delay(T2);
     digitalWrite(Start_LED,HIGH);     delay(T);    digitalWrite(Start_LED,LOW);     delay(T2);
     digitalWrite(Fish_W_LED,HIGH);    delay(T);    digitalWrite(Fish_W_LED,LOW);    delay(T2);    digitalWrite(Fish_B_LED,HIGH);    delay(T);    digitalWrite(Fish_B_LED,LOW);    delay(T2);
     digitalWrite(Six_LED,HIGH);       delay(T);    digitalWrite(Six_LED,LOW);       delay(T2);    digitalWrite(Seven_LED,HIGH);     delay(T);    digitalWrite(Seven_LED,LOW);     delay(T2);
     digitalWrite(Eight_LED,HIGH);     delay(T);    digitalWrite(Eight_LED,LOW);     delay(T2);    digitalWrite(Nine_LED,HIGH);      delay(T);    digitalWrite(Nine_LED,LOW);      delay(T2);
     digitalWrite(Ten_LED,HIGH);       delay(T);    digitalWrite(Ten_LED,LOW);       delay(T2);    digitalWrite(Turtles_B_LED,HIGH); delay(T);    digitalWrite(Turtles_B_LED,LOW); delay(T2);
     digitalWrite(Turtles_G_LED,HIGH); delay(T);    digitalWrite(Turtles_G_LED,LOW); delay(T2);    digitalWrite(Five_LED,HIGH);      delay(T);    digitalWrite(Five_LED,LOW);      delay(T2);
     digitalWrite(Four_LED,HIGH);      delay(T);    digitalWrite(Four_LED,LOW);      delay(T2);    digitalWrite(Three_LED,HIGH);     delay(T);    digitalWrite(Three_LED,LOW);     delay(T2);
     digitalWrite(Two_LED,HIGH);       delay(T);    digitalWrite(Two_LED,LOW);       delay(T2);    digitalWrite(One_LED,HIGH);       delay(T);    digitalWrite(One_LED,LOW);       delay(T2);
     digitalWrite(Duck_Y_LED,HIGH);    delay(T);    digitalWrite(Duck_Y_LED,LOW);    delay(T2);    digitalWrite(Duck_B_LED,HIGH);    delay(T);    digitalWrite(Duck_B_LED,LOW);    delay(T2);
     digitalWrite(Frog_Y_LED,HIGH);    delay(T);    digitalWrite(Frog_Y_LED,LOW);    delay(T2);    digitalWrite(Frog_G_LED,HIGH);    delay(T);    digitalWrite(Frog_G_LED,LOW);    delay(T2);
     digitalWrite(End_B_LED,HIGH);     delay(T);    digitalWrite(End_B_LED,LOW);     delay(T2);    digitalWrite(End_R_LED,HIGH);     delay(T);    digitalWrite(End_R_LED,LOW);     delay(T2);
     digitalWrite(Start_LED,HIGH);     delay(T);    digitalWrite(Start_LED,LOW);     delay(T2);
     digitalWrite(Fish_W_LED,HIGH);    delay(T);    digitalWrite(Fish_W_LED,LOW);    delay(T2);    digitalWrite(Fish_B_LED,HIGH);    delay(T);    digitalWrite(Fish_B_LED,LOW);    delay(T2);
     digitalWrite(Six_LED,HIGH);       delay(T);    digitalWrite(Six_LED,LOW);       delay(T2);    digitalWrite(Seven_LED,HIGH);     delay(T);    digitalWrite(Seven_LED,LOW);     delay(T2);
     digitalWrite(Eight_LED,HIGH);     delay(T);    digitalWrite(Eight_LED,LOW);     delay(T2);    digitalWrite(Nine_LED,HIGH);      delay(T);    digitalWrite(Nine_LED,LOW);      delay(T2);
     digitalWrite(Ten_LED,HIGH);       delay(T);    digitalWrite(Ten_LED,LOW);       delay(T2);    digitalWrite(Turtles_B_LED,HIGH); delay(T);    digitalWrite(Turtles_B_LED,LOW); delay(T2);
     digitalWrite(Turtles_G_LED,HIGH); delay(T);    digitalWrite(Turtles_G_LED,LOW); delay(T2);    digitalWrite(Five_LED,HIGH);      delay(T);    digitalWrite(Five_LED,LOW);      delay(T2);
     digitalWrite(Four_LED,HIGH);      delay(T);    digitalWrite(Four_LED,LOW);      delay(T2);    digitalWrite(Three_LED,HIGH);     delay(T);    digitalWrite(Three_LED,LOW);     delay(T2);
}

void Sequence_Three(){       /////////////////// 12 SEC SEQUENCE ///////////////////////////
  int T = 200; int T2 = 100;
  LEDs_Off();

     digitalWrite(Frog_Y_LED,HIGH);    delay(T);    digitalWrite(Frog_Y_LED,LOW);    delay(T2);    digitalWrite(Turtles_G_LED,HIGH);   delay(T);    digitalWrite(Turtles_G_LED,LOW);    delay(T2); 
     digitalWrite(Five_LED,HIGH);      delay(T);    digitalWrite(Five_LED,LOW);      delay(T2);    digitalWrite(Ten_LED,HIGH);         delay(T);    digitalWrite(Ten_LED,LOW);          delay(T2); 
     digitalWrite(Four_LED,HIGH);      delay(T);    digitalWrite(Four_LED,LOW);      delay(T2);    digitalWrite(Nine_LED,HIGH);        delay(T);    digitalWrite(Nine_LED,LOW);         delay(T2);  
     digitalWrite(Three_LED,HIGH);     delay(T);    digitalWrite(Three_LED,LOW);     delay(T2);    digitalWrite(Eight_LED,HIGH);       delay(T);    digitalWrite(Eight_LED,LOW);        delay(T2);  
     digitalWrite(Two_LED,HIGH);       delay(T);    digitalWrite(Two_LED,LOW);       delay(T2);    digitalWrite(Seven_LED,HIGH);       delay(T);    digitalWrite(Seven_LED,LOW);        delay(T2); 
     digitalWrite(One_LED,HIGH);       delay(T);    digitalWrite(One_LED,LOW);       delay(T2);    digitalWrite(Six_LED,HIGH);         delay(T);    digitalWrite(Six_LED,LOW);          delay(T2); 
     digitalWrite(Duck_B_LED,HIGH);    delay(T);    digitalWrite(Duck_B_LED,LOW);    delay(T2);    digitalWrite(Fish_W_LED,HIGH);      delay(T);    digitalWrite(Fish_W_LED,LOW);       delay(T2); 
     digitalWrite(Duck_Y_LED,HIGH);    delay(T);    digitalWrite(Duck_Y_LED,LOW);    delay(T2);    digitalWrite(Fish_B_LED,HIGH);      delay(T);    digitalWrite(Fish_B_LED,LOW);       delay(T2);  
     digitalWrite(One_LED,HIGH);       delay(T);    digitalWrite(One_LED,LOW);       delay(T2);    digitalWrite(Six_LED,HIGH);         delay(T);    digitalWrite(Six_LED,LOW);          delay(T2); 
     digitalWrite(Two_LED,HIGH);       delay(T);    digitalWrite(Two_LED,LOW);       delay(T2);    digitalWrite(Seven_LED,HIGH);       delay(T);    digitalWrite(Seven_LED,LOW);        delay(T2); 
     digitalWrite(Three_LED,HIGH);     delay(T);    digitalWrite(Three_LED,LOW);     delay(T2);    digitalWrite(Eight_LED,HIGH);       delay(T);    digitalWrite(Eight_LED,LOW);        delay(T2); 
     digitalWrite(Four_LED,HIGH);      delay(T);    digitalWrite(Four_LED,LOW);      delay(T2);    digitalWrite(Nine_LED,HIGH);        delay(T);    digitalWrite(Nine_LED,LOW);         delay(T2); 
     digitalWrite(Five_LED,HIGH);      delay(T);    digitalWrite(Five_LED,LOW);      delay(T2);    digitalWrite(Ten_LED,HIGH);         delay(T);    digitalWrite(Ten_LED,LOW);          delay(T2); 
     digitalWrite(Turtles_B_LED,HIGH); delay(T);    digitalWrite(Turtles_B_LED,LOW); delay(T2);    digitalWrite(Frog_G_LED,HIGH);      delay(T);    digitalWrite(Frog_G_LED,LOW);       delay(T2); 
     digitalWrite(Turtles_G_LED,HIGH); delay(T);    digitalWrite(Turtles_G_LED,LOW); delay(T2);    digitalWrite(Frog_Y_LED,HIGH);      delay(T);    digitalWrite(Frog_Y_LED,LOW);       delay(T2); 
     digitalWrite(Turtles_G_LED,HIGH); delay(T);    digitalWrite(Turtles_G_LED,LOW); delay(T2);    digitalWrite(Five_LED,HIGH);        delay(T);    digitalWrite(Five_LED,LOW);         delay(T2);   
     digitalWrite(Ten_LED,HIGH);       delay(T);    digitalWrite(Ten_LED,LOW);       delay(T2);    digitalWrite(Four_LED,HIGH);        delay(T);    digitalWrite(Four_LED,LOW);         delay(T2); 
     digitalWrite(Nine_LED,HIGH);      delay(T);    digitalWrite(Nine_LED,LOW);      delay(T2);    digitalWrite(Three_LED,HIGH);       delay(T);    digitalWrite(Three_LED,LOW);        delay(T2);    
     digitalWrite(Eight_LED,HIGH);     delay(T);    digitalWrite(Eight_LED,LOW);     delay(T2);    digitalWrite(Two_LED,HIGH);         delay(T);    digitalWrite(Two_LED,LOW);          delay(T2);
}

void Sequence_Four(){       /////////////////// 6 SEC SEQUENCE ///////////////////////////
  int T = 200; int T2 = 100;
  LEDs_Off();
  
     digitalWrite(Frog_Y_LED,HIGH);    delay(T);    digitalWrite(Frog_Y_LED,LOW);    delay(T2);    digitalWrite(Frog_G_LED,HIGH);    delay(T);    digitalWrite(Frog_G_LED,LOW);    delay(T2);
     digitalWrite(End_B_LED,HIGH);     delay(T);    digitalWrite(End_B_LED,LOW);     delay(T2);    digitalWrite(End_R_LED,HIGH);     delay(T);    digitalWrite(End_R_LED,LOW);     delay(T2);
     digitalWrite(Start_LED,HIGH);     delay(T);    digitalWrite(Start_LED,LOW);     delay(T2);
     digitalWrite(Fish_W_LED,HIGH);    delay(T);    digitalWrite(Fish_W_LED,LOW);    delay(T2);    digitalWrite(Fish_B_LED,HIGH);    delay(T);    digitalWrite(Fish_B_LED,LOW);    delay(T2);
     digitalWrite(Six_LED,HIGH);       delay(T);    digitalWrite(Six_LED,LOW);       delay(T2);    digitalWrite(Seven_LED,HIGH);     delay(T);    digitalWrite(Seven_LED,LOW);     delay(T2);
     digitalWrite(Eight_LED,HIGH);     delay(T);    digitalWrite(Eight_LED,LOW);     delay(T2);    digitalWrite(Nine_LED,HIGH);      delay(T);    digitalWrite(Nine_LED,LOW);      delay(T2);
     digitalWrite(Ten_LED,HIGH);       delay(T);    digitalWrite(Ten_LED,LOW);       delay(T2);    digitalWrite(Turtles_B_LED,HIGH); delay(T);    digitalWrite(Turtles_B_LED,LOW); delay(T2);
     digitalWrite(Turtles_G_LED,HIGH); delay(T);    digitalWrite(Turtles_G_LED,LOW); delay(T2);    digitalWrite(Five_LED,HIGH);      delay(T);    digitalWrite(Five_LED,LOW);      delay(T2);
     digitalWrite(Four_LED,HIGH);      delay(T);    digitalWrite(Four_LED,LOW);      delay(T2);    digitalWrite(Three_LED,HIGH);     delay(T);    digitalWrite(Three_LED,LOW);     delay(T2);

}

void Sequence_Wrong(){ 
   X.play("Wrong.wav");
   for (int i=22; i<43; i++)
      {   digitalWrite (i, HIGH);
          delay(30);
          digitalWrite (i, LOW);
                                  }
}
