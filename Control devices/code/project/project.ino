#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
// change lcd to lcd(0x27) when using device
LiquidCrystal_I2C lcd(0x20, 16, 2);

#define blth_txd 0
#define blth_rxd 1
#define option1 8
#define option2 9
#define option3 10
#define option4 11
#define option5 12


//My SubFunction
    //DisplayLCD
void DisplayFxn(){
  if(blth_txd=="telephone"){
    lcd.setCursor (0,0);
    lcd.print("    Active     ");
    lcd.setCursor (0,1);
    lcd.print("   TELEPHONE");
    digitalWrite(option5,HIGH);
  }else if(blth_txd=="fan"){
    lcd.setCursor (0,0);
    lcd.print("     Active     ");
    lcd.setCursor (0,1);
    lcd.print("      FAN");
    digitalWrite(option4,HIGH);
  }else if(blth_txd=="lightbulb"){
    lcd.setCursor (0,0);
    lcd.print("     Active     ");
    lcd.setCursor (0,1);
    lcd.print("     LIGHT BULB");
    digitalWrite(option3,HIGH);
  }else if(blth_txd=="playstation"){
    lcd.setCursor (0,0);
    lcd.print("     Active     ");
    lcd.setCursor (0,1);
    lcd.print("  PLAYSTATION");
    digitalWrite(option2,HIGH);
  }else if(blth_txd=="heater"){
    lcd.setCursor (0,0);
    lcd.print("     Active     ");
    lcd.setCursor (0,1);
    lcd.print("   HEATER");
    digitalWrite(option1,HIGH);
  }else {
    lcd.setCursor (0,0);
    lcd.print("    Active     ");
    lcd.setCursor (0,1);
    lcd.print("   TELEPHONE");
    digitalWrite(option5,HIGH);
  }
};
    //INPUT CHANGES
void inputChange(){

}
//MainFunction
void setup(){
      Serial.begin(9600);  
      pinMode(blth_txd, INPUT);
      pinMode(blth_rxd, INPUT);
      pinMode(option1, OUTPUT);
      pinMode(option2, OUTPUT);  
      pinMode(option3, OUTPUT);
      pinMode(option4, OUTPUT);
      pinMode(option5, OUTPUT);

      
      lcd.begin(16, 2);  
      lcd.setCursor (0,0);
      lcd.print("Control Devices");
      lcd.setCursor (0,1);
      lcd.print("     System     ");
      delay (2000);
      lcd.clear();   
      
}


//Loop Function
void loop(){
    
  //Function Call 
    inputChange();
    DisplayFxn();
      delay(1);
}
