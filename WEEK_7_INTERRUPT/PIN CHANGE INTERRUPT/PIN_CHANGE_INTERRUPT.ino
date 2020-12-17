//NUR AIMAN 1716510
//WEEK 7 - INTERRUPT
//PIN CHANGE INTERRUPT

volatile bool changed;
unsigned char *sreg= (unsigned char*)0x5F; // These addresses are obtained from the datasheet
unsigned char *pcicr= (unsigned char*)0x68;
unsigned char *pcmsk0 = (unsigned char*)0x6B;

void setup ()
{
    *sreg   |= (1 <<7); //The Most Significant Bit to enable or disable interrupts in general. Set this bit to enable the interrupt
    *pcicr   =  1; //Enable pin change interrupt 0
    *pcmsk0  =  255; //Enable pin change interrupt on all the Port B pin
    Serial.begin(9600);
    while(1)
    {
      if(changed)// condition is true if bool changed is true
      {
        Serial.println("Sensor values changed");
        changed = 0;
      }
      //Do other things or go back to sleep
     }
}
ISR(PCINT0_vect)//for portB
{
  changed = 1; // detected the value on the portB
}
void loop (){
  
}
