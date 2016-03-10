/*
 * Controller.h
 *
 *  Created on: Mar 9, 2016
 *      Author: 1750800404
 */

#ifndef SRC_TELEOP_CONTROLLER_H_
#define SRC_TELEOP_CONTROLLER_H_

#include "Joystick.h"
#include "Buttons/JoystickButton.h"

class Controller{

public:
	Controller(int id);
	~Controller();

	Joystick *stick;
	JoystickButton *aButton;
	JoystickButton *bButton;
	JoystickButton *xButton;
	JoystickButton *yButton;
	JoystickButton *rBumper;
	JoystickButton *lBumper;
	JoystickButton *rStickButton;
	JoystickButton *lStickButton;
	JoystickButton *startButton;
	JoystickButton *backButton;

	bool aButtonGet();
	bool bButtonGet();
	bool xButtonGet();
	bool yButtonGet();
	bool rBumperGet();
	bool lBumperGet();
	bool rStickPress();
	bool lStickPress();
	bool startButtonGet();
	bool backButtonGet();
	int getPOV();
	double getrStickX();
	double getrStickY();
	double getlStickX();
	double getlStickY();
	double getrTrig();
	double getlTrig();

private:

protected:

};

#endif /* SRC_TELEOP_CONTROLLER_H_ */
