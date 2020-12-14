//NUR AIMAN 1716510
//WEEK 5 - ANALOG INPUT
//EXAMPLE 1

void setup()
{
    Serial.begin(9600); //For now, we are still using the Serial library
}
void loop()
{
      int reading = analogRead(A2); //int or unsigned int does not matter
      Serial.println("\nPotentiomenter:");Serial.println(reading);
}
