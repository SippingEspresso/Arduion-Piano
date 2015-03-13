
//defines led outputs
#define LED1 53
#define LED2 52
#define LED3 51
#define LED4 50
#define LED5 49
#define LED6 48
#define LED7 47
#define LED8 46

int keyReading = 0;

void setup()
{
  Serial.begin(9600);
  
  for (int i = 4; i <= 11; i++){  //goes through 2 to 9 and sets up keys as inputs
    pinMode(i, INPUT);
  }
  for (int i = 25; i <= 29; i++){
    pinMode(i, INPUT);
  }
  for (int i = 46; i <= 53; i++){
    pinMode(i, OUTPUT);
  }
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
      Serial.println(i);
    }
  }
  delay(100);
  
  for (int i = 46; i <= 53; i++){
    digitalWrite(i, LOW);
  }
}
