//NUR AIMAN 1716510
//BLINKING LED
//WEEK 4 - GPIO
//EXAMPLE 9

void setup()
{
  DDRD |= 0b11111111;// Set PB0 and PB1 as output pins 
}

void loop(){

  PORTD |= 0b00000001; //Set PD0 HIGH for 781ms
  delay(781);
  PORTD &= 0b11111110; //Set PD0 LOW for 515ms
  delay(515);
  PORTD |= 0b00000010; //Set PD1 HIGH for 2014ms
  delay(2014);
  PORTD &= 0b11111101; //Set PD1 LOW for 1348ms
  delay(1348);
  PORTD |= 0b00000100; //Set PD2 HIGH for 343ms
  delay(343);
  PORTD &= 0b11111011; //Set PD2 LOW for 573ms
  delay(573);
  PORTD |= 0b00001000; //Set PD3 HIGH for 678ms
  delay(678);
  PORTD &= 0b11110111; //Set PD3 LOW for 1839ms
  delay(1839);
  PORTD |= 0b00010000; //Set PD4 HIGH for 342ms
  delay(342);
  PORTD &= 0b11101111; //Set PD4 LOW for 534ms
  delay(534);
  PORTD |= 0b00100000; //Set PD5 HIGH for 1478ms
  delay(1478);
  PORTD &= 0b11011111; //Set PD5 LOW for 326ms
  delay(326);
  PORTD |= 0b01000000; //Set PD6 HIGH for 1859ms
  delay(1859);
  PORTD &= 0b10111111; //Set PD6 LOW for 351ms
  delay(351);
  PORTD |= 0b10000000; //Set PD7 HIGH for 678ms
  delay(678);
  PORTD &= 0b01111111; //Set PD7 LOW for 1839ms
  delay(1839);
  
}
