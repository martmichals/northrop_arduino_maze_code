//Prototype functions
boolean checkEnd();
boolean findRepetition(int repArray[]);
boolean checkLine(boolean isLineSection);
boolean normalProcedureMaze(boolean isNotPylon);
boolean checkRight();

int getNumHigh();
int alignmentCount();
int getAverageIR();

void startTone();
void initializeServos();
void setServos(int i, int t, bool opp, bool pivot);
void maneuver(char c, int t);
void pivot(int angle);
void sensorTest();
void lineTracking();
void playTones(int num);
void wiggleForTheLine();
void pylon();
void mystery();
void rotate(int angle);
void rotationTests();
void maze(boolean isNotPylon);
void sensorTester();
void straightDriver();
void lineUpToWall(boolean rightFirst);
void executeSection();
