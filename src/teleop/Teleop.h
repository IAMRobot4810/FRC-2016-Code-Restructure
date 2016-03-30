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
#include "systems/Shooter.h"
#include "systems/DefenseArm.h"
#include "systems/Camera.h"

class Teleop{

public:
	Teleop();
	~Teleop();

	StickControl *controller1;
	StickControl *controller2;
	InOutConverter *conv1;
	InOutConverter *conv2;

	DriveSystem *drive;
	Shooter *shoot;
	DefenseArm *def;

	Camera* camera;

	bool aToggle;
	bool bToggle;
	bool xToggle;
	bool yToggle;
	bool rToggle;
	bool lToggle;
	bool rStickToggle;
	bool lStickToggle;
	bool startToggle;
	bool backToggle;

	double currentPos;

	void TeleopNoSensors();
	void TeleopWithSensors();

private:
protected:

};

#endif /* SRC_TELEOP_TELEOP_H_ */
