void buzz_timer();
int inputPin = 1; //setting up the pins, change the pins here
int buzzPin = 2;

void setup(){//Setting up the pin
  pinMode(inputPin, INPUT); //pin that handles the incoming input
  pinMode(buzzPin, OUTPUT); //pin that handles the buzz
} 

void loop(){
int buzz_flag = 0; //check if the buzzer has been turn on once. 1 means it has been turned on once.

buzz_timer(inputPin, buzzPin, &buzz_flag);
}

void buzz_timer(int input, int buzz, int * flag){
  digitalWrite(buzz, LOW); //turn the buzzer off no matter what
  if (digitalRead(input) && *flag == 0){ //if inputPin is HIGH and buzzer has not been turned on.
    digitalWrite(buzz, HIGH); //turn the buzzer on
    delay(3000); //hold it for 3 seconds
  }
  digitalWrite(buzz, LOW); //turn off the buzzer
  *flag = 1; //set the flag to 1
}

