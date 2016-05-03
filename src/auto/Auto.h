/*
 * Auto.h
 *
 *  Created on: Mar 7, 2016
 *      Author: 1750800404
 */

#ifndef SRC_AUTO_AUTO_H_
#define SRC_AUTO_AUTO_H_

#include "systems/MultiTool.h"
#include "systems/DriveSystem.h"

class Auto{

public:
	Auto(DriveSystem *autoDrive, MultiTool *autoTool);
	~Auto();

	DriveSystem *aDrive;
	MultiTool *aTool;

	void LowPortAuton();
	void RockRoughAuton();
	void MoatRampartsAuton();
	void DoorAuton();
	void SpyAuton();
	void NoAuton();

private:

protected:

};

#endif /* SRC_AUTO_AUTO_H_ */
