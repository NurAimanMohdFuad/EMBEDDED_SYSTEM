//NUR AIMAN 1716510
//BLINKING LED
//WEEK 4 - GPIO
//EXAMPLE 8

unsigned int Y,O,R,B,G;
unsigned long previousTime; 
void setup()
{
  DDRB &= 0b11100000;// Set PB2, PB3, PB4 as input pins 
  //DDRC &= 0b11001111;// Set PC5, PC4 as input pins 
  Serial.begin(9600);
  
}

void loop(){

  unsigned long currentTime = millis();
 
  if((PINB&(0b00010000)) == 0)// PB4
  {
    if (currentTime - previousTime >= 2000) //2000 is OFF duration
    {
      Y++;//Yellow Wire
      previousTime = currentTime; //Take note of the time
    }
  }
  else if((PINB&(0b00001000)) == 0)//PB3
  {
    if (currentTime - previousTime >= 2000) //2000 is OFF duration
    {
      O++;//Orange Wire
      previousTime = currentTime; //Take note of the time
    }
  }
  else if((PINB&(0b00000100)) == 0)//PB2
  {
    if (currentTime - previousTime >= 2000) //2000 is OFF duration
    {
      R++;//Red Wire
      previousTime = currentTime; //Take note of the time
    }
  }
 else if((PINB&(0b00000010)) == 0) //PB1
  {
    if (currentTime - previousTime >= 2000) //2000 is OFF duration
    {
      B++;//Blue Wire
      previousTime = currentTime; //Take note of the time
    }
  }
  else if((PINB&(0b000000001)) == 0) //PB0
  {
    if (currentTime - previousTime >= 2000) //2000 is OFF duration
    {
      G++;//Green Wire
      previousTime = currentTime; //Take note of the time
    }
  }
  else
  {
     previousTime = currentTime;
  }

 Serial.print("\n PB4 = ");
 Serial.print((PINB&(0b00010000)));
 Serial.print("  Y = ");
 Serial.print(Y);
 Serial.print(" \t PB3 = ");
 Serial.print((PINB&(0b00001000)));
 Serial.print("  O = ");
 Serial.print(O);
 Serial.print(" \t PB2 = ");
 Serial.print((PINB&(0b00000100)));
 Serial.print("  R = ");
 Serial.print(R);
 Serial.print(" \t PB1 = ");
 Serial.print((PINB&(0b00000010)));
 Serial.print("  B = ");
 Serial.print(B);
 Serial.print(" \t PB0 = ");
 Serial.print((PINB&(0b00000001)));
 Serial.print("  G = ");
 Serial.print(G);

}
