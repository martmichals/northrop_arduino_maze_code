void maze(boolean isNotPylon)
{
  while(checkEnd())
  {
    if(normalProcedureMaze(isNotPylon))//inlay checkEnd interrupt (return true if not the end of the section)
       checkRight(); 
  }
}

boolean normalProcedureMaze(boolean isNotPylon) //Checks for case causing 90 degree left and less than 90 degree left (return true if -90 taken and false w/no action taken)
{
  int count = 0;
  while(checkEnd() && count < 50){
     maneuver('f', 50);
    
    if(!digitalRead(LEFT_WHISK))
    {
        do{
          maneuver('b', 50); 
        }while(!digitalRead(LEFT_WHISK));
        rotate(-90);
        return true;
    }

    if(!digitalRead(RIGHT_WHISK))
    {
      //Handles misalign, 90 left and less than 90 left 
        do{
          maneuver('b', 50); 
         }while(!digitalRead(RIGHT_WHISK)); 
        maneuver('b', 200);
        rotate(-15);
        return false;
    }
     
    count++;
  }
  return true;
}

boolean checkRight() //Rotates and checks for case causing 90 degree right and greater than 90 degree right (true for action)
{
  playTones(1);
  rotate(15);
  int count = 0;
  boolean noWall = false;

  boolean wRight = !digitalRead(RIGHT_WHISK);
  boolean wLeft = !digitalRead(LEFT_WHISK);

  do{
    maneuver('f', 50);
    wRight = !digitalRead(RIGHT_WHISK);
    wLeft = !digitalRead(LEFT_WHISK);
    count++;
    if(count == 25)
      noWall = true;
  }while(count < 25 && !wLeft && !wRight && checkEnd());

  if(wLeft && checkEnd()){
    maneuver('b', 500);
    rotate(30);
  }

  if(!noWall && checkEnd()){
    for(int i = 0; i < count; i++)
      maneuver('b', 50);
    rotate(-15);
  }
  else if (checkEnd()){
    maneuver('f', 500);
    for(int i = 0; i < 5 && digitalRead(RIGHT_WHISK); i++){
       rotate(15); 
    }
    delay(100);
  }
}

int getAverageIR()
{ 
    int sum = 0;
    for(int i = 0; i < 3; i++)
      sum += analogRead(AN_IR);
    return sum / 3;
}
