//Code for line tracking, line detection, line alignment, and line counting

/**Tracks line 
 * Pre-condition: there are sensors outputting high and those sensors indicate line to be followed
 * Post-condition: 7 sensors output high when in contact with end of section line
 */
void lineTracking()
{
  int lineSensors[8];
  int manHist[4];
  int manIndex = 0;
  int numHigh = 0;
  int lastMan = 0;
  boolean isLeft;
  boolean isRight;
  maneuver('f', 100);
  if(!checkEnd)
    rotate(-30);
  while(checkEnd()) //Make a find line function
  {
    for(int i = 0; i < 8; i++)
    {
        lineSensors[i] = digitalRead(LINE_PORTS[i]);
    }
    numHigh = getNumHigh();

    if(numHigh > 3)
    {
      if(lineSensors[7] == 1 || lineSensors[6] == 1)
        isRight = true;
      else if(lineSensors[0] == 1 || lineSensors[1] == 1)
        isLeft = true;
        
      maneuver('f', 100);
      if(getNumHigh() == 0)
      {
        maneuver('b', 100);
        if(isRight)
          pivot(90);
        else
          pivot(-90);
      }
      isRight = false;
      isLeft = false;
      Serial.println("here");
    }
    
    else if(lineSensors[7] == 1 || lineSensors[6] == 1 || lineSensors[5] == 1)
    {
      //turn right
       setServos(30, 135, true, false); //100 to 150
       lastMan = 1;
       manHist[manIndex] = 1;
       manIndex++;
    }
    else if(lineSensors[0] == 1 || lineSensors[1] == 1 || lineSensors[2] == 1)
    {
      //turn left
      setServos(-30, 135, true, false); //100 to 150
      lastMan = -1;
      manHist[manIndex] = -1;
      manIndex++;
    }
    else
    {
      maneuver('f', 50);
      lastMan = 0;
      manIndex = 0;
      for(int i = 0; i < 4; i++)
        manHist[i] = 0;
    }

    if(manIndex == 5)
    {
      manIndex = 0;
      for(int i = 0; i < 4; i++)
        manHist[i] = 0;
    }

    if(manIndex >= 2 && manIndex % 2 == 0)
    {
      int manHistSum = 0;
      for(int i = 0; i < 4; i++)
        manHistSum+= manHist[i];
      if(manHistSum == 0)
        maneuver('f', 200);
        
      manIndex = 0;
      for(int i = 0; i < 4; i++)
        manHist[i] = 0;
    }
    numHigh = 0;
  }
}

//Aligns the bot with lines and counts number of lines no matter the section
int alignmentCount()
{
  int numLines = 0;
  int counter = 0;
  boolean reset = true;
  maneuver('b', 700);

  //Section modified 11-24-2017 check for bugs @Northtrop
  while(digitalRead(LINE_PORTS[7]) == 0 || digitalRead(LINE_PORTS[0]) == 0)
  {
    do{
      maneuver('f', 50);
    }while(digitalRead(LINE_PORTS[7]) == 0 && digitalRead(LINE_PORTS[0]) == 0);

    while(digitalRead(LINE_PORTS[7]) == 0)
      setServos(-30, 50, true, false);

    while(digitalRead(LINE_PORTS[0]) == 0)
      setServos(30, 50, true, false);
  }
  numLines++;
  
  while(digitalRead(LINE_PORTS[7]) == 1 || digitalRead(LINE_PORTS[0]) == 1)
  {
    maneuver('f', 50);
  }
  
  while((digitalRead(LINE_PORTS[7]) == 0 || digitalRead(LINE_PORTS[0]) == 0) && counter < 15)
  {
       do{
         maneuver('f', 50);
         counter++;
        }while(digitalRead(LINE_PORTS[7]) == 0 && digitalRead(LINE_PORTS[0]) == 0 && counter < 15);
        
       if(counter <   15)
         counter = 0;
          
       while(digitalRead(LINE_PORTS[7]) == 0 && counter < 15)
         setServos(-30, 50, true, false);

       while(digitalRead(LINE_PORTS[0]) == 0 && counter < 15)
         setServos(30, 50, true, false);
        
      if(digitalRead(LINE_PORTS[7]) == 1 && digitalRead(LINE_PORTS[0]) == 1)
        numLines++;
        
      while(digitalRead(LINE_PORTS[7]) == 1 || digitalRead(LINE_PORTS[0]) == 1)
      {
        maneuver('f', 50);
      }
   }

  playTones(numLines);
  return numLines;
}

/**Gets number of sensors with a high input
 * @return int numHigh: number of sensors high
 */
int getNumHigh()
{
 int numHigh = 0;
 for(int i = 0; i < 8; i++)
    {
        if(digitalRead(LINE_PORTS[i]) == 1)
          numHigh++;
    }
  return numHigh;
}
