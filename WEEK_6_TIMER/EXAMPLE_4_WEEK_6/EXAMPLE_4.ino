//NUR AIMAN 1716510
//WEEK 6 - TIMER PORTS
//EXAMPLE 4


void setup()
{
  unsigned char *ddrb= (unsigned char*)0x24;
  unsigned char *ocr1al = (unsigned char*)0x88;
  unsigned char *tccr1a = (unsigned char*)0x80;
  unsigned char *tccr1b = (unsigned char*)0x81;
  
  *ddrb=2;                  // Refer to the pin PWM 9 on the arduino board.
  *ocr1al =255;             // These registers affects the duty cycle of Channel A of timer1.
  *tccr1a =0b10000011;      // Set up normal output, Phase correct PWM 10-bit
  *tccr1b =0b00000010;      // Pre scaler value of 8
}
