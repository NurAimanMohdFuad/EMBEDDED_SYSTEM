//This coding is for example 4 and 5

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
class DCMotor
{
  private:
  Blinky oscillator;
  unsigned long Period;
  
  public:
  DCMotor()
  {
    Initialize('B', 5, 100);
  }
  DCMotor(char port, int pin, double frequency_in_herts)
  {
    Initialize(port, pin, frequency_in_herts);
  }
  void Initialize(char port,int pin, double frequency_in_herts)
  {
    Period = 1000000 /frequency_in_herts;
    oscillator.Initialize(port, pin, 0, Period);
  } 
  void Write(double duty_cycle)
  {
   unsigned long OnTime = Period * duty_cycle;
   unsigned long OffTime = Period - OnTime;
   oscillator.ChangeOnOffTimes(OnTime,OffTime);
  }
  void Refresh()
  {
    oscillator.Refresh();
  }
};
void setup() 
{
  DCMotor motor1('B',0,500);
  DCMotor motor2('B',1,500);
  DCMotor motor3('B',2,500);
  DCMotor motor4('B',3,500);
  motor1.Write(0.2);
  motor2.Write(0.4);
  motor3.Write(0.6);
  motor4.Write(0.8);
  while(1)
  {
  motor1.Refresh();
  motor2.Refresh();
  motor3.Refresh();
  motor4.Refresh();
}
}
void loop() 
{

}
