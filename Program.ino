// By Alexander Zahabizadeh
// PLays piano tones through a buzzer that registers keys connecting to a power source
// Part of Group A's project

// Defines notes for 8 octaves worth of pitches, not all are used
// This was taken from a similiar open source project
// The orginal source can be found a part of  http://www.instructables.com/id/Capacitive-Touch-Arduino-Keyboard-Piano/

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

//defines each key as corresponding pin
#define KEY1 4
#define KEY2 5
#define KEY3 6
#define KEY4 7
#define KEY5 8
#define KEY6 9
#define KEY7 10
#define KEY8 11

//defines octave boolean inputs
#define OCTAVE1 25
#define OCTAVE2 27
#define OCTAVE3 29

//defines led outputs
#define LED1 46
#define LED2 47
#define LED3 48
#define LED4 49
#define LED5 50
#define LED6 51
#define LED7 52
#define LED8 53

#define BUZZER 2  //buzzer key

int notes[]={NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_C5};  //default set at C- Major Scale

int keyReading = 0;

void setup()
{
  for (int i = 4; i <= 11; i++){  //goes through 2 to 9 and sets up keys as inputs
    pinMode(i, INPUT);
  }
  for (int i = 25; i <= 29; i++){
    pinMode(i, INPUT);
  }
  for (int i = 46; i <= 53; i++){
    pinMode(i, OUTPUT);
  }
  
  delay(2000);
  
  /*int readOctave1 = digitalRead(OCTAVE1),
  readOctave2 = digitalRead(OCTAVE2),
  readOctave3 = digitalRead(OCTAVE3);
  
  if (readOctave1 == 0 && readOctave2 == 0 && readOctave3 == 0){
    delay(50);
  }
  else if (readOctave1 == 1 && readOctave2 == 0 && readOctave3 == 0){
    delay(50);
  }
  else if (readOctave1 == 0 && readOctave2 == 1 && readOctave3 == 0){
    delay(50);
  }
  else if (readOctave1 == 1 && readOctave2 == 1 && readOctave3 == 0){
    delay(50);
  }
  else if (readOctave1 == 0 && readOctave2 == 0 && readOctave3 == 1){
    delay(50);
  }
  else if (readOctave1 == 1 && readOctave2 == 0 && readOctave3 == 1){
    delay(50);
  }
  else if (readOctave1 == 0 && readOctave2 == 1 && readOctave3 == 1){
    delay(50);
  }
  else if (readOctave1 == 1 && readOctave2 == 1 && readOctave3 == 1){
    delay(50);
  }
  }*/
}


int ledPrinter(int currentLed)
{
  if (currentLed == 1){
    digitalWrite(LED1, HIGH);
  }
  else if (currentLed == 2){
    digitalWrite(LED2, HIGH);
  }
  else if (currentLed == 3){
    digitalWrite(LED3, HIGH);
  }
  else if (currentLed == 4){
    digitalWrite(LED4, HIGH);
  }
  else if (currentLed == 5){
    digitalWrite(LED5, HIGH);
  }
  else if (currentLed == 6){
    digitalWrite(LED6, HIGH);
  }
  else if (currentLed == 7){
    digitalWrite(LED7, HIGH);
  }
  else if (currentLed == 8){
    digitalWrite(LED8, HIGH);
  }
}
  
  
void loop()  //keeps looping through reading the keys
{
  for (int i = 1; i <= 8; i++){
    keyReading = digitalRead(i + 3);
    
    if (keyReading == 1){
      ledPrinter(i);
      tone(BUZZER, notes[i], 1000/8);
    }
  } 
  
  for (int i = 46; i <= 53; i++){
    digitalWrite(i, LOW);
  }
}
