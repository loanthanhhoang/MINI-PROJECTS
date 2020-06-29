/*
  This project is modified from https://github.com/sparkfun/SIK-Guide-Code (3 buttons trumpet)
*/

//set the pins for the button and buzzer
int firstKeyPin = 12;
int secondKeyPin = 11;
int thirdKeyPin = 10;
int fourthKeyPin = 9;

int buzzerPin = 8;


void setup() {
  //set the button pins as inputs (to read whether the button is pressed or not, if it is then digitalRead of the Pin will give value LOW, and HIGH otherwise
  pinMode(firstKeyPin, INPUT_PULLUP);
  pinMode(secondKeyPin, INPUT_PULLUP);
  pinMode(thirdKeyPin, INPUT_PULLUP);
  pinMode(fourthKeyPin, INPUT_PULLUP);

  //set the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  if (digitalRead(firstKeyPin) == LOW) { //if the first key is pressed
    if (digitalRead(secondKeyPin) == HIGH && digitalRead(fourthKeyPin) == HIGH){ // if the second key and fourth keys are not pressed
      tone(buzzerPin, 262); //play c
      } 
    else{ //if the second key is pressed
      tone(buzzerPin, 294); //play d
      }
   }
  
  else if (digitalRead(secondKeyPin) == LOW) { //if the second key is pressed
    if (digitalRead(thirdKeyPin) == HIGH){ //if the third key is not pressed
      tone(buzzerPin, 330); //play the frequency for e
      }
    else { //if the third key pressed
      tone(buzzerPin, 349); //play f
      }
  }
  else if (digitalRead(thirdKeyPin) == LOW) { //if the third key is pressed
    if (digitalRead(fourthKeyPin) == HIGH) { //if the fourth key is not pressed
      tone(buzzerPin, 392); //play g
      }
    else {
      tone(buzzerPin, 440); //play a
      }
   }
  else if (digitalRead(fourthKeyPin) == LOW){ //if the fourth key is pressed
    if (digitalRead (firstKeyPin) == HIGH){
      tone (buzzerPin, 1000); //play b
    }
    else{
      tone(buzzerPin, 523); // Play higher C
      }
    }
  else{
    noTone(buzzerPin);                        //if no key is pressed turn the buzzer off    
    }
}

/*
  note  frequency
  c     262 Hz
  d     294 Hz
  e     330 Hz
  f     349 Hz
  g     392 Hz
  a     440 Hz
  b     494 Hz
  C     523 Hz
*/
