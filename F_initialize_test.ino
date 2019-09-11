//All Methods for Initialization and Testing
void startTone()
{
  for(int i=3000; i<=4000; i+=50)
    {
      tone(PIEZO, i, 50);
      delay(50);
    }
}

void initializeServos()
{ 
    startTone();
}

void playTones(int num)
{
  for(int i = 0; i < num; i++)
  {
    tone(PIEZO, 3500, 150);
    delay(300);
  }
}

void sensorTest()
{
  while(true)
  {
    for(int i = 0; i < 8; i++)
    {
      Serial.print(digitalRead(LINE_PORTS[i]));
      Serial.print(" ");
    }
    Serial.print("      ");
    Serial.print(digitalRead(LEFT_WHISK));
    Serial.print(digitalRead(RIGHT_WHISK));
    Serial.println();
    delay(500);
  }
}

void rotationTests()
{
  boolean wRight = !digitalRead(RIGHT_WHISK);
  boolean wLeft = !digitalRead(LEFT_WHISK);
  while(true)
  {
    if(wLeft)
    { 
      int count = 0;
      wRight = !digitalRead(RIGHT_WHISK);
      wLeft = !digitalRead(LEFT_WHISK);
      while(wLeft)
      {
        wRight = !digitalRead(RIGHT_WHISK);
        wLeft = !digitalRead(LEFT_WHISK);
        if(wRight)
        {
          delay(200);
          count++;
          playTones(1);
        }
      }
      count *= 30;
      delay(100);
      rotate(-count);
      delay(1000);
      rotate(count);
    }else{
      wRight = !digitalRead(RIGHT_WHISK);
      wLeft = !digitalRead(LEFT_WHISK);
    }
  } 
}

void sensorTester()
{
  while(true)
  {
    int sum = 0;
    for(int i = 0; i < 3; i++)
      sum += analogRead(AN_IR);
    Serial.println((double)sum / 3.0);
    delay(500);
  }
}


void straightDriver()
{
  while(true)
  {
    if(!digitalRead(RIGHT_WHISK))
      maneuver('f', 3000);
    else if(!digitalRead(LEFT_WHISK))
      maneuver('b', 3000);
  }
}

