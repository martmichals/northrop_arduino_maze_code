void setup()
{
  Serial.begin(9600);
  pinMode(RIGHT_WHISK, INPUT);
  pinMode(LEFT_WHISK, INPUT);
  
  //Line tracker pin instantiation
  for(int i = 0; i < 8; i++)
  {
    pinMode(LINE_PORTS[i], INPUT);
  }
  delay(500);
  
  initializeServos();
//  delay(1000);
//  maneuver('f', 3000);

  sectionNum = 1; //Initial Section Number
  while(!endAll)
  {
    executeSection();
    endProcedure();
    if(!endAll && sectionNum != 3){
      sectionNum = 3;
      lineTracking();
      sectionNum = alignmentCount();
    }else if(!endAll){
      sectionNum = alignmentCount();
    }
    delay(3000);
    playTones(sectionNum);
  }
}

