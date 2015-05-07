#include <FastSPI_LED2.h>
#include <LiquidCrystal.h>
#define SPEAKER 10
#define SW 2
#define BRIGHTNESS 255
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 	// initialize LCD library
CRGB leds[1];
//1 ). Declare variable here!
/*
  DECLARE VARIABLE
*/
int button, knob, light, rtemp;
float temp;
void setup() {
  pinMode(SW, INPUT);
  pinMode(SPEAKER, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  lcd.begin(16, 2);
  lcd.clear();
  //uncomment if going to use LED
  /*
    LEDS.setBrightness(BRIGHTNESS);
    //update PIN at A!
    LEDS.addLeds<WS2811, A1, RGB>(leds, 1);
    LEDS.show();
  */
  //2.) Setup here
  //------- START SETUP -----------------------
  /*
    SETUP CODE
  */

  //------- END OF SETUP -----------------------
}

void loop() {
  //------- START CODE-----------------------
  //uncomment to get stuff from input
  //button = digitalRead(2);
  //knob = analogRead(A3);
  light = analogRead(A4);
  rtemp = analogRead(A5);
  //uncomment to convert rtemp to temparature (temp);
  temp = ((float(rtemp) * 0.25) - 25.51);

  //3) Main Code
  lcd.print(temp);
  //if temp is more than 30 C
  if ( temp > 30 )
  {
    lcd.setCursor(0, 1);
    //lcd.print("Too Hot");
    if(light > 500)
    {
      lcd.print("Argggggggg!!!!");
    }else
    {
      lcd.print("Too Hot");
    }

  } else if ( temp > 20)
  {
    lcd.setCursor(0, 1);
    if(light < 400)
    {
       lcd.print("Chill Chill"); 
    }else
    {
        lcd.print("Just Right");      
    }

  } else
  {
    lcd.setCursor(0, 1);
    if( light < 300)
    {
       lcd.print("NEED LIGHT"); 
    }else
    {
      lcd.print("Too Cold");
    }
  }

  delay(1000);
  lcd.clear();

  //SNIPPET
  //tone(SPEAKER, 300);
  //noTone(SPEAKER);
  //use color led
  /*
    leds[0] = CRGB::Blue;
    LEDS.show();
  */

  //------- END OF MAIN CODE -----------------------
}
