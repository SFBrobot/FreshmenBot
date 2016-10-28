#pragma config(Motor,  port1,           motorRB,       tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           motorRF,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           motorLF,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           bottomArmR,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           bottomArmL,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           topArmR,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           topArmL,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           clawA,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           clawB,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          motorLB,       tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//

void arm(int pwr) {
	motor[bottomArmR] = motor[bottomArmL] = motor[topArmR] = motor[topArmL] = pwr;
}
void armTime(int pwr, int s) {
	arm(pwr);
	wait1Msec(s);
}

#include "Vex_Competition_Includes.c"

void pre_auton() { }

task autonomous() { 
	
}

task usercontrol() {
	while(true) {
		motor[motorLF] = motor[motorLB] = (vexRT[Ch3] + vexRT[Ch1]);
		motor[motorRF] = motor[motorRB] = (vexRT[Ch3] - vexRT[Ch1]);
		
		if(vexRT[Btn5U] == 1) {
			arm(63);
		}
		else if(vexRT[Btn5D] == 1) {
			arm(-63);	
	}
		else {
			arm(0);
		}
		if(vexRT[Btn6U] == 1) {
			motor[clawA] = 63;
			motor[clawB] = 63;
	}
		else if(vexRT[Btn6D] == 1) {
			motor[clawA] = -63;
			motor[clawB] = -63;
	}
		else {
			motor[clawA] = 0;
			motor[clawB] = 0;
	}

}
}
void allMotorsOff() { }
void allTasksStop() { }