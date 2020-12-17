//NUR AIMAN 1716510
//WEEK 7 - INTERRUPT
//TIMER INTERRUPT

volatile unsigned long ms;
unsigned char *tccr2a = (unsigned char*)0xB0;
unsigned char *tccr2b = (unsigned char*)0xB1;
unsigned char *timsk2 = (unsigned char*)0x70;
unsigned char *portb= (unsigned char*)0x25;
unsigned char *ddrb= (unsigned char*)0x24;
unsigned char *sreg= (unsigned char*)0x5F;
unsigned long previousTime;


ISR(TIMER2_OVF_vect)
{
  ms++;
}
unsigned long getMilliseconds()
{
  *timsk2 =0; //Disable timer2 interrupts
  unsigned long val=ms; //Read the variable
  *timsk2 =1; //Re-enable timer2 interrupts
  return val;
}
void setup()
{
  *ddrb   = 1 << 5; //Set PB5 as output
  *tccr2a = 3; //8-bit Fast PWM on timer2
  *tccr2b = 4; //Set pre-scalerto 64
  *sreg  |= 1 <<7; //The Most Significant Bit to enable or disable interrupts in general. Set this bit to enable the interrupt
  *timsk2 =1; //Enable timer2 overflow interrupt
}

void loop()
{
   unsigned long currentTime=getMilliseconds();
   if((*portb) & 32)//If LED is currently ON
    {
      if(currentTime-previousTime>=1000)
      {
        *portb=0; //Turn it OFF
         previousTime=currentTime;
      }
    }
   else//If LED is currently OFF
    {
      if(currentTime-previousTime>=1000)
      {
        *portb=32; //Turn it ON
         previousTime=currentTime;
      }
    }
  }
