#include <Servo.h> //includes the servo library
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
// change lcd to lcd(0x27) when using device
LiquidCrystal_I2C lcd(0x20, 20, 4);

Servo myservo;

#define ir_enter 2
#define ir_back  4

#define car1 5
#define car2 6
#define car3 7
#define car4 8
#define car5 9
#define car6 10

int S1=0, S2=0, S3=0, S4=0, S5=0, S6=0;
int flag1=0, flag2=0; 
int slot = 6;  


//My SubFunction
    //DisplayLCD
void DisplayFxn(){
    if(slot>0){
      lcd.setCursor (0,0);
      lcd.print("   Have Slot: "); 
      lcd.print(slot);
      lcd.print("     ");  
    }
    
    lcd.setCursor (0,1);
    if(S1==1){lcd.print("S1:Fill ");}
         else{lcd.print("S1:Empty");}
    
    lcd.setCursor (10,1);
    if(S2==1){lcd.print("S2:Fill ");}
         else{lcd.print("S2:Empty");}
    
    lcd.setCursor (0,2);
    if(S3==1){lcd.print("S3:Fill ");}
         else{lcd.print("S3:Empty");}
    
    lcd.setCursor (10,2);
    if(S4==1){lcd.print("S4:Fill ");}
         else{lcd.print("S4:Empty");}
    
     lcd.setCursor (0,3);
    if(S5==1){lcd.print("S5:Fill ");}
         else{lcd.print("S5:Empty");}
    
    lcd.setCursor (10,3);
    if(S6==1){lcd.print("S6:Fill ");}
         else{lcd.print("S6:Empty");}  
};
    //INPUT CHANGES
void inputChange(){
    if(digitalRead(car1)==1){
      S1=1;
    }else{
      S1=0;
    }
    if(digitalRead(car2)==1){
      S2=1;
    }else{
      S2=0;
    }
    if(digitalRead(car3)==1){
      S3=1;
    }else{
      S3=0;
    }
    if(digitalRead(car4)==1){
      S4=1;
    }else{
      S4=0;
    }
    if(digitalRead(car5)==1){
      S5=1;
    }else{
      S5=0;
    }
    if(digitalRead(car6)==1){
      S6=1;
    }else{
      S6=0;
    }
}
    //ON PARK FULL
 void onparkFull(){
    if(slot<=0){
      digitalWrite(ir_enter,LOW);
      myservo.write(180);
      lcd.setCursor (0,0);
      lcd.print("Parking Slot iS FULL");
    }else{
      digitalWrite(ir_enter,HIGH);
      myservo.write(90);
      digitalWrite(ir_back,HIGH);
    }
    if(slot>=6){
      digitalWrite(ir_back,LOW);
    }
 }
//MainFunction
void setup(){
      Serial.begin(9600);  
      digitalWrite(ir_enter,HIGH);
      digitalWrite(ir_back,HIGH);
      pinMode(car1, INPUT);
      pinMode(car2, INPUT);
      pinMode(car3, INPUT);
      pinMode(car4, INPUT);
      pinMode(car5, INPUT);
      pinMode(car6, INPUT);
      
      pinMode(ir_enter, OUTPUT);
      pinMode(ir_back, OUTPUT);
        
      myservo.attach(3);
      myservo.write(90);
      
      lcd.begin(20, 4);  
      lcd.setCursor (0,1);
      lcd.print("    Car  parking  ");
      lcd.setCursor (0,2);
      lcd.print("       System     ");
      delay (2000);
      lcd.clear();   
      
}


//Loop Function
void loop(){
  //Get the Remaining Slot
    slot = 6-(S1+S2+S3+S4+S5+S6);

    
  //Function Call 
    inputChange();
    
    DisplayFxn();

    onparkFull();
      delay(1);
}
