/**Moves the robot in a variety of ways
 * @param int i: speed in range from -300 to 300
 * @param int t: time
 * @param bool opp: rotational turn?
 * @param bool pivot: pivot turn?
 */
void setServos(int i, int t, bool opp, bool pivot)
  {
    servoRight.attach(12);
    servoLeft.attach(13);
    if(!opp && !pivot)
       { 
          servoRight.writeMicroseconds(1500 - i);
          servoLeft.writeMicroseconds(i + 1500);
       }
       else if (opp && !pivot)
       {
        servoRight.writeMicroseconds(i + 1500);
        servoLeft.writeMicroseconds(i + 1500);  
       }else{
        int left = i + 1500;
        int right = 1500 - i;
        if(left > right)
          {
            servoLeft.writeMicroseconds(left);
            servoRight.writeMicroseconds(1500);
          }else{
            servoRight.writeMicroseconds(left);
            servoLeft.writeMicroseconds(1500);
          }
         
       }
       delay(t);
       servoRight.detach();
       servoLeft.detach();
  }

void maneuver(char c, int t)
  {
    switch(c)
    {
      //driving forward at apx. 40
      case 'f': 
        servoRight.attach(12);
        servoLeft.attach(13);
        
        servoRight.writeMicroseconds(1500 - 48);
        servoLeft.writeMicroseconds(1500 + 33);
        
        delay(t);
        servoRight.detach();
        servoLeft.detach();
        break;
       case 'b':
        servoRight.attach(12);
        servoLeft.attach(13);
        
        servoRight.writeMicroseconds(1500 + 30);
        servoLeft.writeMicroseconds(1500 - 50);
        
        delay(t);
        servoRight.detach();
        servoLeft.detach();
        break;
       case 's':
        servoRight.attach(12);
        servoLeft.attach(13);
        
        servoRight.writeMicroseconds(1500 - 22);
        servoLeft.writeMicroseconds(1500 + 12);
        
        delay(t);
        servoRight.detach();
        servoLeft.detach();
        break;
    }
  }

void pivot(int angle)
{
  boolean negative;
  if(angle < 0)
    negative = true;
  else 
    negative = false;
    
  for(int i = 0; i < 10; i++)
  {
    if(PIVOT_ANGS[i] == angle && !negative)
    {
      setServos(PIVOTSPD, PIVOT_TIMES[i], false, true);
      break;
    }
    else if(PIVOT_ANGS[i] == angle)
    {
      setServos(-PIVOTSPD, PIVOT_TIMES[i], false, true);
      break;
    }
  }
}

void rotate(int angle)
{
  int speeder = 35;
  switch(angle)
  {
    case -15:
      setServos(-speeder, 300, true, false);
      break;
    case 15:
      setServos(speeder, 300, true, false);
      break;
    case 30:
      setServos(speeder, 600, true, false);
      break;
    case -30:
      setServos(-speeder, 1000, true, false); 
      break;
    case 60:
      setServos(speeder, 1200, true, false);
      break;
    case -60:
      setServos(-speeder, 2430, true, false);
      break;
    case 90:
      setServos(speeder, 1200, true, false);
      break;
    case -90:
      setServos(-speeder, 2200, true, false);
      break;
  }
}
