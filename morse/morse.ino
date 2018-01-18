#include "morse.h"

const int led = 13;
const int UNIT = 200;
const int DOT = 1;
const int LETTER_END = 2;
const int DASH = 3;
const int SPACE = 4;
void lights(int units){
  digitalWrite(led, HIGH);
  delay(units*UNIT);
  digitalWrite(led, LOW);
  delay(UNIT);
}

void transmit(char symbol){
  switch(symbol){
    case '.':
      lights(DOT);
      break;
    case '_':
      lights(DASH);
      break;
    case ';':
      delay(LETTER_END*UNIT);
      break;
    default:
      delay(SPACE*UNIT);
  }
}

void transmit(String code){
  for (int i = 0; i < code.length(); i++){
    transmit(code[i]);
  }
}

void parse(char* fileName){
  
}

/**
 * Put setup code here
 * Set LED pin as output
 */
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

/**
 * Put looping code here
 * Blinks on and off half a second
 */
void loop() {
  if (Serial.available() > 0){
    char a = Serial.read();
    if (a==' '){
      transmit(' ');
    }
    else{
      transmit(morse(a));
    }    
  }
}
