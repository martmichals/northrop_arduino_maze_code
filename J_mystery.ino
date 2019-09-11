void mystery()
{
  int count = 0;
  boolean wRight = !digitalRead(RIGHT_WHISK);
  boolean wLeft = !digitalRead(LEFT_WHISK);
  boolean rightFirst;
  
  while(!wRight && !wLeft)
  {
    maneuver('f', 50);
    count++;
    wLeft = !digitalRead(LEFT_WHISK);
    wRight = !digitalRead(RIGHT_WHISK);
    if(wLeft)
      rightFirst = false;
    else 
      rightFirst = true;
  }
  for(int i = 0; i < ((count / 2) - 20); i++)
    maneuver('b', 50);
  rotate(90);
  maneuver('f', 2500);
}

void lineUpToWall(boolean rightFirst){
  maneuver('b', 500);
  delay(1000);
  boolean wLeft = !digitalRead(LEFT_WHISK);
  boolean wRight = !digitalRead(RIGHT_WHISK);

  if(rightFirst)
  {
    while(rightFirst)
    {
      do{
        maneuver('f', 50);
        wLeft = !digitalRead(LEFT_WHISK);
        wRight = !digitalRead(RIGHT_WHISK);
      }while(!wLeft && !wRight);
      if(wLeft)
           rightFirst = false;
        else 
           rightFirst = true;
      maneuver('b', 300);
      pivot(4);
    }
    pivot(-4);
    pivot(-4);
  }
  else
  {
    while(!rightFirst)
    {
      do{
        maneuver('f', 50);
        wLeft = !digitalRead(LEFT_WHISK);
        wRight = !digitalRead(RIGHT_WHISK);
      }while(!wLeft && !wRight);
      if(wLeft)
           rightFirst = false;
        else 
           rightFirst = true;
      maneuver('b', 300);
      for(int i = 0; i < 4; i++)
        pivot(-4);
    }
    pivot(4);
    pivot(4);
    maneuver('b', 300);
  }
}

