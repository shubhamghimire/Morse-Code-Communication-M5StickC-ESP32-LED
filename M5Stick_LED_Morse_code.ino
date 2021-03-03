//M5 Stick C, Morse code generator

#include <M5StickC.h>

int PIN = 32;
char stringToMorseCode[] = "";
int dotLen = 500;     // length of the morse code 'dot'
int dashLen = dotLen * 3;    // length of the morse code 'dash'

void setup() {
  M5.begin();
  Serial.begin(115200);
  pinMode(GPIO_NUM_10, OUTPUT);
  digitalWrite(GPIO_NUM_10, HIGH);
}
void loop()
{
  char inChar = 0;
  char inData[100] = "";        // data length of 6 characters
  String variable = "";
  String variable1 = "";
  int index1 = 0;

  if ( Serial.available() > 0 ) {                      
    while (Serial.available() > 0 && index1 < 500)    
    {
      delay(100);
      inChar = Serial.read();      // start reading serilly and save to variable
      inData[index1] = inChar;
      index1++;
      inData[index1] = '\0';         // Add a null at the end
    }
    variable.toUpperCase();       // convert to uppercase
    for (byte  i = 0 ; i < 100 ; i++) {
      variable.concat(String(inData[i]));    // concat strings
    }
    delay(20);
  }
  String  stringToMorseCode = String(variable);
  for (int i = 0; i < sizeof(stringToMorseCode) - 1; i++)
  {
    char tmpChar = stringToMorseCode[i];
    tmpChar = toLowerCase(tmpChar);
    GetChar(tmpChar);
  }
}
void MorseDot()
{
  digitalWrite(GPIO_NUM_10, LOW);
  delay(dotLen);                       // hold in this position
  digitalWrite(GPIO_NUM_10, HIGH);
}
void MorseDash()
{
  digitalWrite(GPIO_NUM_10, LOW);
  delay(dashLen);                      // hold in this position
  digitalWrite(GPIO_NUM_10, LOW);
}
void GetChar(char tmpChar)
{
  switch (tmpChar) {
    case 'a':
      MorseDot();
      delay(500);
      MorseDash();
      delay(500);
      break;
    case 'b':
      MorseDash();
      delay(500);
      MorseDot();
      delay(500);
      MorseDot();
      delay(500);
      MorseDot();
      delay(500);
      break;
    case 'c':
      MorseDash();
      delay(500);
      MorseDot();
      delay(500);
      MorseDash();
      delay(500);
      MorseDot();
      delay(500);
      break;
    case 'd':
      MorseDash();
      delay(500);
      MorseDot();
      delay(500);
      MorseDot();
      delay(500);
      break;
    case 'e':
      MorseDot();
      delay(500);
      break;
    case 'f':
      MorseDot();
      delay(500);
      MorseDot();
      delay(500);
      MorseDash();
      delay(500);
      MorseDot();
      delay(500);
      break;
    case 'g':
      MorseDash();
      delay(500);
      MorseDash();
      delay(500);
      MorseDot();
      delay(500);
      break;
    case 'h':
      MorseDot();
      delay(500);
      MorseDot();
      delay(500);
      MorseDot();
      delay(500);
      MorseDot();
      delay(500);
      break;
    case 'i':
      MorseDot();
      delay(500);
      MorseDot();
      delay(500);
      break;
    case 'j':
      MorseDot();
      delay(500);
      MorseDash();
      delay(500);
      MorseDash();
      delay(500);
      MorseDash();
      delay(500);
      break;
    case 'k':
      MorseDash();
      delay(500);
      MorseDot();
      delay(500);
      MorseDash();
      delay(500);
      break;
    case 'l':
      MorseDot();
      delay(500);
      MorseDash();
      delay(500);
      MorseDot();
      delay(500);
      MorseDot();
      delay(500);
      break;
    case 'm':
      MorseDash();
      delay(500);
      MorseDash();
      delay(500);
      break;
    case 'n':
      MorseDash();
      delay(500);
      MorseDot();
      delay(500);
      break;
    case 'o':
      MorseDash();
      delay(500);
      MorseDash();
      delay(500);
      MorseDash();
      delay(500);
      break;
    case 'p':
      MorseDot();
      delay(500);
      MorseDash();
      delay(500);
      MorseDash();
      delay(500);
      MorseDot();
      delay(500);
      break;
    case 'q':
      MorseDash();
      delay(500);
      MorseDash();
      delay(500);
      MorseDot();
      delay(500);
      MorseDash();
      delay(500);
      break;
    case 'r':
      MorseDot();
      delay(500);
      MorseDash();
      delay(500);
      MorseDot();
      delay(500);
      break;
    case 's':
      MorseDot();
      delay(500);
      MorseDot();
      delay(500);
      MorseDot();
      delay(500);
      break;
    case 't':
      MorseDash();
      delay(500);
      break;
    case 'u':
      MorseDot();
      delay(500);
      MorseDot();
      delay(500);
      MorseDash();
      delay(500);
      break;
    case 'v':
      MorseDot();
      delay(500);
      MorseDot();
      delay(500);
      MorseDot();
      delay(500);
      MorseDash();
      delay(500);
      break;
    case 'w':
      MorseDot();
      delay(500);
      MorseDash();
      delay(500);
      MorseDash();
      delay(500);
      break;
    case 'x':
      MorseDash();
      delay(500);
      MorseDot();
      delay(500);
      MorseDot();
      delay(500);
      MorseDash();
      delay(500);
      break;
    case 'y':
      MorseDash();
      delay(500);
      MorseDot();
      delay(500);
      MorseDash();
      delay(500);
      MorseDash();
      delay(500);
      break;
    case 'z':
      MorseDash();
      delay(500);
      MorseDash();
      delay(500);
      MorseDot();
      delay(500);
      MorseDot();
      delay(500);
      break;
    default:
      break;
  }
}
