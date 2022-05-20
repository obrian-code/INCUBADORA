#include  <LiquidCrystal.h>

LiquidCrystal lcd_(12, 11, 5, 4, 3, 2);
int val,buzzerPin=13; 
const int rele=10;  

void setup() {
     
      Serial.begin (9600);                             
      pinMode(A1,INPUT);                               
      pinMode(6,OUTPUT);                               
      pinMode(7,OUTPUT);
      pinMode(rele,OUTPUT);
      lcd_.begin(16, 2);
      lcd_.clear();
      lcd_.setCursor(1,0);
      lcd_.print("INCUBADORA"); 
      lcd_.setCursor(3,1);
      lcd_.print("BIENVENIDO"); 

      delay(500);                               
}

void loop() {
 
        unsigned val = analogRead (A1);                                          
        float temp = (5.0*val*100.0)/1024.0; 
                                     
           lcd_.clear();
           lcd_.print("TEMPERATURA");
           lcd_.setCursor(0, 1);
           lcd_.print("VALUE:");
           lcd_.setCursor(6, 1);
           lcd_.print(temp, 1);
           
        if(temp>=50.0){
          
            digitalWrite(rele,LOW);                                   
            digitalWrite(6,LOW);                         
            digitalWrite(7,HIGH);
            tone(buzzerPin,740,700);
            digitalWrite(buzzerPin,HIGH);
            delay(1000); 
          
        }else{ 
          
          digitalWrite(rele,HIGH);                                            
          digitalWrite(6,HIGH);                          
          digitalWrite(7,LOW); 
          digitalWrite(buzzerPin,LOW);  
          
          }
          
        delay(500);                                     
}
