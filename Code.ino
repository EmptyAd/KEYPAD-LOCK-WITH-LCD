#include <LiquidCrystal.h>   
#include <Keypad.h>
#include <Servo.h>

int servostate;
int posOpen = 90;
int posClose = 0;
int a=0, b=0, c=0, d=0;
int var=0; 
int C1=1,C2=2,C3=3,C4=4;
char f='*';  
const byte row = 4; 
const byte column = 4;
char tecla[row][column] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte pinRow[row] = {0, 6, 5, 4}; 
byte pinColumn[column] = {3, 2, 1};

Servo myservo;
Keypad keypad = Keypad( makeKeymap(tecla), pinRow, pinColumn, row, column );
LiquidCrystal lcd(8,9,10,11,12,13);
void setup(){
  lcd.begin(16,2); 
  pinMode(A0,OUTPUT); 
  pinMode(A1,OUTPUT); 
  myservo.attach(7); 
  myservo.write(posOpen);
  servostate = 1;
}
  
void loop(){  
  char key = keypad.getKey();
  if (key){
   lcd.setCursor(6+var,1);
   lcd.print(key),lcd.setCursor(6+var,1),lcd.print(f);
   key=key-48;
   var++; 
   switch(var){
    case 1:
    a=key; 
    break;
    case 2:
    b=key; 
    break;
    case 3:
    c=key; 
    break;
    case 4:
    d=key; 
   delay(50);
  if(a==C1 && b==C2 && c==C3 && d==C4){
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Gate");
    lcd.setCursor(5,1);
    if(servostate == 0){
    	lcd.print("Open");
      myservo.write(posOpen);
      servostate = 1;      
    }
    else{
      lcd.print("Closed");
      myservo.write(posClose);
      servostate = 0;      
    }
    
    digitalWrite(A0,HIGH);
    delay(1000); 
    lcd.clear();
    digitalWrite(A0,LOW);
    }
  else{
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Password");
    lcd.setCursor(4,1);
    lcd.print("Invalid");
    digitalWrite(A1,HIGH); 
    delay(1000); 
    lcd.clear();
    digitalWrite(A1,LOW); 
    }

   var=0;
   lcd.clear();

  break;
  }

 }
 if(!key){lcd.setCursor(0,0),lcd.print("Enter Pass");}

  delay(2);
}
