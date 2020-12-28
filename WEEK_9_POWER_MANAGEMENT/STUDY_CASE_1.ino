// NUR AIMAN
// 1716510
// WEEK 9 - STUDY CASE 1

unsigned char* adcsra = (char*)0x7A;
unsigned char* acsr = (char*) 0x50;
unsigned char* pind=(char*)0x29;
unsigned char* sreg=(char*)0x5F;
unsigned char* eimsk=(char*)0x3D;
unsigned char* eicra=(char*)0x69;
unsigned char* ddrd = (char*) 0x2A;
unsigned char* ddrb = (char*) 0x24;
unsigned char* portb = (char*) 0x25;
unsigned char* ddrc = (char*) 0x27;
unsigned char* smcr = (unsigned char*)0x53;
unsigned volatile char* mcucr = (unsigned char*) 0x55;

bool red_button;
bool green_button;


void setup()
{
  DisableADCandComparator();  // Call the function to turn off the ADC and the comparator.
  EnableExternalInterrupts(); // Call the functon to enable external interrupt 
}
void loop()
{
  DeepSleep();
}
ISR(INT0_vect)
{
    red_button = ((*pind) & 0b00000100);    // Check the status PD2
    *portb = red_button << 3;               // LED on PB4 will turned ON if the bool is TRUE
}
ISR(INT1_vect)
{
    green_button = ((*pind) & 0b00001000);   // Check status PD3
    *portb = green_button << 4;             // LED on PB3 will turned ON if the bool is TRUE
}
void DisableADCandComparator()
{
  *ddrd = 0b11110011;                       // Set PB3 and PB4 as input
  *ddrb = 0b11111111;                       // Set up all pin as output to save the power
  *ddrc = 0b11111111;
  *adcsra= 0;                               //Disable ADC
  *acsr= 1<< 7;                             //Disable comparator
}
void EnableExternalInterrupts()
{
  *sreg |= (1 << 7);                        //Enable interrupts
  *eimsk = 3;                               //Enable INT0 and INT1
  *eicra = 15;                              //Set trigger mode to LOW TO HIGH
}
void DeepSleep()
{
  *smcr = 5;                                // POWER DOWN and set Sleep Enable 
  *mcucr = 0b01100000;                      //Set Both BODS and BODSE
  *mcucr = 0b01000000;                      //Set BODS and clear BODSE
  asm("sleep");                          
}
