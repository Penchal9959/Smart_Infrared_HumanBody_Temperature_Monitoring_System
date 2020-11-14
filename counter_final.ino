#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
const int buzzer = 10;
const int ledPin1 = 11;
const int ledPin2 = 12;
#define in 8
#define out 9
int count=0;


Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  //Serial.println("Adafruit MLX90614 test");
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  mlx.begin();  
}

void loop() 
{

  lcd.setCursor(8,1);
  lcd.print(mlx.readObjectTempC());
  delay(700);
  lcd.setCursor(13,1);
  lcd.print("C  ");
  lcd.setCursor(1,1);
  lcd.print("TEMP = ");

////////////////////////////////////////////////////////////////////////MLX90614//////////////////////////////
  if(mlx.readObjectTempC() >= 33 && mlx.readObjectTempC() <= 35 )
  {
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledPin1, HIGH); 
    
    }
  else
  {
    digitalWrite(buzzer, LOW);
    digitalWrite(ledPin1, LOW); 
  }

  if(mlx.readObjectTempC() >= 30 && mlx.readObjectTempC() <= 33 )
  {
    digitalWrite(ledPin2, HIGH); 
    
    }
  else
  {
        digitalWrite(ledPin2, LOW); 
  }
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  //////////////////IR sensors/////////////////////////////////////////////////////////////////////////////////////
  int in_value = digitalRead(in);
  int out_value = digitalRead(out);

    lcd.setCursor(1, 0);
    lcd.print("PersonInRoom:");
    //lcd.setCursor(4,0);
    lcd.setCursor(14,0);
    lcd.print(count);
    delay(100);
  if(in_value == LOW)
  {
    count++;
      
  }

    lcd.setCursor(1, 0);
    lcd.print("PersonInRoom:");
    lcd.setCursor(14,0);
    lcd.print(count);
    delay(100);
  if(out_value == LOW)
  {
    count--;
       
  }
////////////////////////////IREND/////////////////////////////////////////////////////////////////////////////// 
}
