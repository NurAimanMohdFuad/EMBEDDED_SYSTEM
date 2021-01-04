//This coding is for example 1, 2, and 3

class Blinky
{
  private:
  unsigned long OnTime;
  unsigned long OffTime;
  unsigned long last_time = 0;
  char mask;
  char mask_inv;

  char* DDR;
  char* PORT;

  public:
  Blinky()
  {
    Initialize('B',5, 1000000, 1000000);
  }
  Blinky(char port, int pin, long ontime, long offtime)
  {
    Initialize(port, pin, ontime, offtime);
  }
  void Initialize(char port, int pin, long ontime, long offtime)
  {
    OnTime = ontime;
    OffTime = offtime;
    switch(port)
    {
      case 'B':
      DDR = (char*)0x24;
      PORT = (char*)0x25;
      break;
      case'C':
      DDR =(char*)0x27;
      PORT =(char*)0x28;
      break;
      case'D':
      DDR = (char*)0x2A;
      PORT = (char*)0x2B;
      break;
    }
    mask = (1<<pin);
    mask_inv = ~mask;
    *DDR |= mask;
  }
  void ChangeOnOffTimes(long ontime,long offtime)
  {
    OnTime = ontime;
    OffTime = offtime;
  }
  void Refresh()
  {
    unsigned long now = micros();
    if (*PORT & mask)
    {
      if(now-last_time > OnTime)
      {
        if (OffTime > 0)
        {
          *PORT &= mask_inv;
        }
        last_time =now;
      }
    }
    else
    {
      if(now - last_time > OffTime)
      {
        if(OnTime > 0)
        {
          *PORT |=mask;
        }
        last_time = now;
      }
    }
  }
};

void setup() 
{
  Blinky blinker('B',5,1000000,1000000);
  while(1)
  {
      blinker.Refresh();
  }
}
void loop() 
{

}
