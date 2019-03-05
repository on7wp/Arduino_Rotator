/********************************************************

 Description: Rotator controller for DC Create by ON7WP
   

********************************************************/

#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);        // select the pins used on the LCD panel

// Motor Azimuth connections
   int enA = 11;
   int in1 = 12;
   int in2 = 13;
// Motor Elevation connections
   int enB = 3;
   int in3 = 2;
   int in4 = 1;

  int rotorfeedback;                      // variable to store the value coming from the analog pin 
  double act;                             // variable to store the temperature value coming from the conversion formula
  double error;                           // variable to store the pointing error
  int potmeter;                           // variable to store the value coming from the analog pin 
  double set;                             // variable to store the temperature value coming from the conversion formula

void setup(){ 
  lcd.begin(16, 2);                       // start the library

// Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
// Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop(){ 
 
    rotorfeedback= analogRead(1);                     // read the analog in value:
    act = (double) rotorfeedback * (398/1024.0);      // temperature conversion formula
 
    potmeter=analogRead(2);                           // read the analog in value:
    set = (double) potmeter * (398/1024.0);           // temperature conversion formula
       
             // print the results to the lcd
             lcd.setCursor(0, 0);                     // set the LCD cursor   position 
             lcd.print("ACT: ");               
             lcd.print(act-19);             
             lcd.print(" deg.");
             lcd.setCursor(0, 1);                     // set the LCD cursor   position 
             lcd.print("SET: ");
             error=set-act;               
             lcd.print(set-19);             
             lcd.print(" deg.");                     
    if(set < act)
      {
      TurnCCW();
      } 
       else {
       TurnCW();
      } 
//speedcontrol while reaching target    
if ((abs(set-act))<10) 
  { 
  analogWrite(enA, 200);
  analogWrite(enB, 200);
  } 
if ((abs(set-act))<3) 
  { 
  analogWrite(enA, 150);
  analogWrite(enB, 150);
  } 
if ((abs(set-act))<0.3) 
  { 
  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);
//  Stop();
  }   
}
// This function lets you control the motor to turn clockwise
void TurnCW(){
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void TurnCCW(){
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void Stop(){
   // Turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
