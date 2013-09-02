int ledArray[] = {2, 3, 4, 5, 6, 7, 8, 9, 10}; // 2-9 for each LED column
int layerArray[] = {11, 12, 13};

void plane();
void setup(){
  for(int pinID = 0; pinID < 10; pinID++){
    pinMode(ledArray[pinID], OUTPUT);
  }
  for(int layerID = 0; layerID < 3; layerID++){
    pinMode(layerArray[layerID], OUTPUT);
  }
}
//When both the ledArray and layerArray intersects, the LED is on
void loop(){
 // cycling through each led
 for(int layer = 0; layer < 3; layer++){
  digitalWrite(layerArray[layer], HIGH);
  for(int led = 0; led < 10; led++){
    digitalWrite(ledArray[led], HIGH); // turn on the led
    delay(200);
    digitalWrite(ledArray[led], LOW); // turn off the led
  }
  digitalWrite(layerArray[layer], LOW);
 }
 // Random leds
 for(int index = 0; index < 10; index++){  
   int rLed = ledArray[random(0,8)];
   int rLayer = layerArray[random(0, 2)];
   
   digitalWrite(rLayer, HIGH);
   delay(10); // establish ground first
   digitalWrite(rLed, HIGH);
   delay(200);
   digitalWrite(rLed, LOW);
   digitalWrite(rLayer, LOW);
 }
 plane();
 
  
}

void plane(){
  // Light up planes
  // Using port manipulation to turn multiple pins on at the same time.
  
  // Turning on each level.
  // Set Layer 1 to high (11-13)
  PORTB = B100000;
  delay(10);
  
  // Turing Each LED Layer on (2-10)
  PORTD = B11111100;
  PORTB = B100111; // First Layer
  delay(200);
  
  // Turn first layer off and second layer on
  PORTB = B000000; //shut off ground
  PORTD = B000000; //Shut off LED
  delay(10);
  PORTB = B010000; // Turn on second ground
  delay(10);
  PORTB = B010111;  
  PORTD = B11111100;
  delay(200);
  
  // Turn Second Layer off and Third Layer on
  PORTB = B000000; //shut off ground
  PORTD = B000000; //Shut off LED
  delay(10);
  PORTB = B001000;
  delay(10);
  PORTB = B001111;
  PORTD = B11111100;
  delay(200);
  PORTB = B000000; //shut off ground
  PORTD = B000000; //Shut off LED
  delay(10);
  
  // Side ways
  PORTB = B111000;
  delay(10);
  PORTB = B111100; 
  PORTD = B10010000;
  delay(200);
  PORTB = B111010;
  PORTD = B01001000;
  delay(200);
  PORTB = B111001;
  PORTD = B00100100;
  delay(200);
  
  //Turn off
  PORTB = B000000;
  PORTD = B00000000;
  delay(10);
  
  //EXPLODE
  for(int index = 0; index < 30; index++){
    //Turn off
    PORTB = B000000;
    PORTD = B00000000;
    delay(10);
    
    //Inner
    PORTB = B010000;
    PORTD = B01000000;
    delay(200);
    //Outer
    PORTB = B111111;
    PORTD = B10111100;
    delay(200);
    
  }
  //Turn off
  PORTB = B000000;
  PORTD = B00000000;
  delay(100);
}
