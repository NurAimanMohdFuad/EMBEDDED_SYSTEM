//NUR AIMAN 1716510
//BLINKING LED
//WEEK 4 - GPIO
//EXAMPLE 7

void setup()
{
  DDRB |= 0b00000011;// Set PB0 and PB1 as output pins 
}

void loop(){

  PORTB |= 0b00000001; //Set PB0 HIGH for 750ms
  delay(750);
  PORTB &= 0b11111110; //Set PB0 LOW for 3000ms
  delay(300);
  PORTB |= 0b00000010; //Set PB1 HIGH for 400ms
  delay(400);
  PORTB &= 0b11111101; //Set PB1 LOW for 600ms
  delay(600);
}
