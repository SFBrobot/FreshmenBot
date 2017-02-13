#pragma config(Motor,  port1,           blDrive,       tmotorVex393HighSpeed_HBridge, openLoop, driveLeft)
#pragma config(Motor,  port2,           blLift,        tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           lClaw,         tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           rClaw,         tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           tlLift,        tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           brLift,        tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port7,           trLift,        tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           flDrive,       tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           frDrive,       tmotorVex393HighSpeed_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port10,          brDrive,       tmotorVex393HighSpeed_HBridge, openLoop, reversed, driveRight)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

#include "stickThresh.h"
#include "arcadeCtl.h"


#define setDriveL(pwr) motor[blDrive] = \
	motor[flDrive] = \
	pwr


#define setDriveR(pwr) motor[brDrive] = \
	motor[frDrive] = \
	pwr

#define setLift(pwr) motor[brLift] = \
	motor[blLift] = \
	motor[tlLift] = \
	motor[trLift] = \
	pwr

#define setClaw(pwr) motor[lClaw] = \
	motor[rClaw] = \
	pwr


/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

int drivePwrs[2];

void setDrive(int* pwrs) {
	setDriveL(pwrs[0]);
	setDriveR(pwrs[1]);
}




void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{

}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol() {
	int stick[4];
	while (true) {

		upSticks(&stick[3], 7);

		arcade(&drivePwrs[1], stick[1], stick[2]);
		setDrive(&drivePwrs[1]);

		if(vexRT[Btn5U] ^ vexRT[Btn5D]) {
			if(vexRT[Btn5U])
				setLift(127);
			else
				setLift(-127);
		}
		else
			setLift(0);

		if(vexRT[Btn6U] ^ vexRT[Btn6D]) {
			if(vexRT[Btn6U])
				setClaw(127);
			else
				setClaw(-127);
		}
		else
			setClaw(0);

		wait1Msec(20);
	}
}
