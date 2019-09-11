/**
 * @author: Martin Michalski
 * @mentor: Gerald Chapman
 * @version: 4-17-2018
 * @description: Code for the Boe Bot deisgned by parallax, intended to get the Boe Bot 
 *               through a maze designed by the HIP program at Northrop Grumann in
 *               Rolling Meadows
 * @hardware setup:
 *          - Right whisker: pin 2
 *          - Left whisker: pin 8
 *          - Piezo speaker: pin 4
 *          - Line sensor: pins 3, 4, 5, 6, 7, 9, 10, 11
 *          - (Optional) IR sensor: pin 1 
 * @notes before running:
 *          - Run through test functions to calibrate rotation angles
 *          - Run through test functions to calibrate pivot angles
 *          - Double check section order 
 */
#include <Servo.h>
#include <math.h>

Servo servoLeft;
Servo servoRight;

//Pivot constants 
const int PIVOTSPD = 40;
const int PIVOT_TIMES[] = {100, 100, 800, 800, 1200, 1200,  1600, 1600, 2400, 2400, 3000, 3000};
const int PIVOT_ANGS[] =  {4, -4, 30, -30, 45,  -45, 60, -60, 90, -90, 120, -120};

//Constants for input/output ports
const int RIGHT_WHISK = 2;
const int LEFT_WHISK = 8;
const int PIEZO = 4;
const int AN_IR = 1;
const int LINE_PORTS[] = {3, 4, 5, 6, 7, 9, 10, 11};

//Section Number
int sectionNum = 1;
boolean endAll = false;


