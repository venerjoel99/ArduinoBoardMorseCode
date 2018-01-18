#ifndef MORSE_H_INCLUDED
#define MORSE_H_INCLUDED

const int A = int('A');
const int a = int('a');
const int alphabet = 26;
const int zero = int('0');

String letters[]={
  "._",   //A
  "_...", //B
  "_._.", //C
  "_..",  //D
  ".",    //E
  ".._.", //F
  "__.",  //G
  "....", //H
  "..",   //I
  ".___", //J
  "_._",  //K
  "._..", //L
  "__",   //M
  "_.",   //N
  "___",  //O
  ".__.", //P
  "__._", //Q
  "._.",  //R
  "...",  //S
  "_",    //T
  ".._",  //U
  "..._", //V
  ".__",  //W
  "_.._", //X
  "_.__", //Y
  "__..", //Z
};

bool letter(int val){
  return val >= A && val <= A + alphabet - 1;
}

bool lowercase(char input){
  int val = int(input);
  return val >= a && val <= a + alphabet - 1;
}

int digit(char input){
  return int(input) - zero;
}

String morse(int input){
  bool dot = (input >= 1 && input <= 5);
  int count_down = input % 5;
  String result = "";
  for (int i = 0; i < 5; i++){
    result += dot ? '.' : '_';
    count_down--;
    if (count_down==0){
      dot = !dot;
    }
  }
  return result;
}

String morse(char input){
  int digit_val = digit(input);
  if (digit_val >= 0 && digit_val <= 9){
    Serial.println(digit_val);
    return morse(digit_val)+';';
  }
  int index = lowercase(input) ? int(input) - (a-A) : int(input);
  String morse = letter(index) ? letters[index - A] : "";
  return morse + ';';
}

#endif
