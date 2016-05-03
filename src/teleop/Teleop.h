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

#include "teleop/InOutConverter.h"
#include "systems/DriveSystem.h"
#include "systems/MultiTool.h"

class Teleop{

public:
	Teleop(DriveSystem *teledrive, MultiTool *teletool, StickControl *firstcontroller,
			StickControl *secondcontroller);
	~Teleop();

	StickControl *controller1;
	StickControl *controller2;
	InOutConverter *conv1;
	InOutConverter *conv2;

	DriveSystem *tDrive;
	MultiTool *tTool;

	bool a1Toggle;
	bool b1Toggle;
	bool x1Toggle;
	bool y1Toggle;
	bool r1Toggle;
	bool l1Toggle;
	bool r1StickToggle;
	bool l1StickToggle;
	bool start1Toggle;
	bool back1Toggle;
	bool pov01Toggle;
	bool pov451Toggle;
	bool pov901Toggle;
	bool pov1351Toggle;
	bool pov1801Toggle;
	bool pov2251Toggle;
	bool pov2701Toggle;
	bool pov3151Toggle;

	bool a2Toggle;
	bool b2Toggle;
	bool x2Toggle;
	bool y2Toggle;
	bool r2Toggle;
	bool l2Toggle;
	bool r2StickToggle;
	bool l2StickToggle;
	bool start2Toggle;
	bool back2Toggle;
	bool pov02Toggle;
	bool pov452Toggle;
	bool pov902Toggle;
	bool pov1352Toggle;
	bool pov1802Toggle;
	bool pov2252Toggle;
	bool pov2702Toggle;
	bool pov3152Toggle;

	double currentPos;

	void TeleopNoSensors();
	void TeleopWithSensors();

private:
protected:

};

#endif /* SRC_TELEOP_TELEOP_H_ */
