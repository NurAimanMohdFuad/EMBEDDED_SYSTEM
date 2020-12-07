//NUR AIMAN 1716510
//WEEK 6 - TIMER PORTS
//EXAMPLE 3

void setup()
{
    unsigned char*ddrd=(unsigned char*)0x2A;
    unsigned char*ocr0a =(unsigned char*)0x47;
    unsigned char*ocr0b =(unsigned char*)0x48;
    unsigned char*tccr0a = (unsigned char*)0x44;
    unsigned char*tccr0b = (unsigned char*)0x45;

    *ddrd=1 <<5; //refer to the PWM pin 5 on Arduino Board
    *ocr0a =5;
    *ocr0b =2;
    *tccr0a =0b00100011;// To set as normal output, and fast PWM
    *tccr0b =0b00001001;// To set the pre-scaler value 1
}