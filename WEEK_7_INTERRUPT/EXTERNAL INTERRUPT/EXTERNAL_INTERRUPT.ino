//NUR AIMAN 1716510
//WEEK 7 - INTERRUPT
//EXTERNAL INTERRUPT

unsigned char *pind=(unsigned char*)0x29; //These addresseses can be obtained in the datasheet
unsigned char *ddrb=(unsigned char*)0x24;
unsigned char *portb=(unsigned char*)0x25;
unsigned char *sreg=(unsigned char*)0x5F;
unsigned char *eimsk=(unsigned char*)0x3D;
unsigned char *eicra=(unsigned char*)0x69;

void setup()
{
  *ddrb   = 1 <<  5;                      //Set PB5 as output. The pin which is connecterd to the green LED
  *sreg  |= (1 <<  7);                    //The Most Significant Bit to enable or disable interrupts in general. Set this bit to enable the interrupt
  *eimsk  = 1                             //Enable INT0 at pin PD2
  *eicra  = 1;                            //Set interrupt mode to "any logic change", Interrupt Sense Control
}

ISR(INT0_vect)//Interrupt Service Routine
{
  bool pin_status= ((*pind) &4);
  *portb=pin_status<<5;                   //Same as digitalWrite(13, digitalRead(2));
}

void loop()
{

}
