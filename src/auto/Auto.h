/*
 * Auto.h
 *
 *  Created on: Mar 7, 2016
 *      Author: 1750800404
 */

#ifndef SRC_AUTO_AUTO_H_
#define SRC_AUTO_AUTO_H_

#include "systems/DefenseArm.h"
#include "systems/DriveSystem.h"
#include "systems/Shooter.h"

class Auto{
public:
	Auto();
	~Auto();

	DefenseArm *def;
	DriveSystem *drv;
	Shooter *sht;

	void RegularAuton();
	void TerrainAuton();

private:
protected:
};

#endif /* SRC_AUTO_AUTO_H_ */
