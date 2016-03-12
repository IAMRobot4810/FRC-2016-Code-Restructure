/*
 * Teleop.h
 *
 *  Created on: Mar 7, 2016
 *      Author: 1750800404
 *
 *      Manages teleop mappings to functions
 */

#ifndef SRC_TELEOP_TELEOP_H_
#define SRC_TELEOP_TELEOP_H_

#include "InOutConverter.h"
#include "systems/DriveSystem.h"

class Teleop{

public:
	Teleop();
	~Teleop();

	StickControl *controller1;
	StickControl *controller2;
	InOutConverter *conv1;
	InOutConverter *conv2;

	DriveSystem *drive;

	void TeleopNoSensors();
	void TeleopWithSensors();

private:
protected:

};

#endif /* SRC_TELEOP_TELEOP_H_ */
