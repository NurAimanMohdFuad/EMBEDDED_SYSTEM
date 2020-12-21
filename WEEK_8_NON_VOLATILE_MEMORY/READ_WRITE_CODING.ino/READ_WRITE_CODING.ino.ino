//NUR AIMAN 1716510
//WEEK 8 - NON-VOLATILE MEMORY
//READ & WRITE CODING

char *eedr = (char*)0x40;             //Points to EEDR
  
volatile char *eecr = (char*)0x3F;    //Points to EECR
  
int *eear  = (int*)0x41;              //Points to EEAR. Note that intis 16bit on ATmega328p
                                      //This pointer points to both low byte and high byte
                                      //of EEAR
char ReadByte(int address)
{                                    
   while(((*eecr) & 2))                //If the data is being written (EEPE is high), the integer of 2 is with respect to 10 of EEPM which indicate write only
  {
    //Nothing
  }
  *eear = address;                    //Stores the address in the EEAR
  *eecr = 1;                          //Set EERE (Initiate reading)
  return *eedr;                       //Return the contents of the data register (EEDR)
}

void WriteByte(int address,char data)
{
  while(((*eecr) &2))                 //If the data is being written (EEPE is high)
  {
    //Nothing
  }
  *eear = address;                    //Stores the address in the EEAR
  *eedr = data;                       //Stores the data in the EEDR
  *eecr = 4;                          //Enable Master Write
  *eecr|=2;                           //Start writing
}
void setup()
{
  Serial.begin(9600);
  WriteByte(115,198);                 //Write a value of 168 to the memory location 115
  unsigned char a = ReadByte(115);      //Read the value at memory location 115
  Serial.println(a);                  //Prints the value of the EEPROM at memory address 115
}

void loop(){
  //Nothing
}
