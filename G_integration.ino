//Returns true to keep going, false @end of section
boolean checkEnd()
{
 if(sectionNum == 3)
    return checkLine(true);
 else
    return checkLine(false);
}

//Checks for line at the end of section, section dependent
boolean checkLine(boolean isLineSection)
{
  if(isLineSection)
  {
    if(getNumHigh() >= 7)
    {
      maneuver('f', 50);
      if(getNumHigh() >= 7)
        return false;
      else 
      {
        maneuver('b', 25);
        return true;
      }
    }
    else
      return true;
  }
  else
  {
    if(getNumHigh() >= 2)
    {
      return false;
    }
    else
    {
      return true;
    }
  }
}

void executeSection()
{
  if(sectionNum == 1){
    maze(true);
  }if(sectionNum == 2){
    maneuver('f', 2000);
    rotate(90);
    maze(true);
  }if(sectionNum == 3){
    maneuver('f', 1500);
    lineTracking();
  }if(sectionNum == 4){
    mystery();
    endAll = true;
  }if(sectionNum == 5){
    rotate(30);
    maneuver('f', 1500);
    rotate(30);
    maze(false);
  }
}   

void endProcedure()
{
  if(sectionNum == 1){
    rotate(-30);
  }if(sectionNum == 2){
    
  }if(sectionNum == 3){
   
  }if(sectionNum == 4){

  }if(sectionNum == 5){

  }
}

