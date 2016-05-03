/*
 * MultiTool.h
 *
 *  Created on: Apr 5, 2016
 *      Author: Achintya
 *
 *      For all the systems located on the central shaft
 */

#ifndef SRC_SYSTEMS_MULTITOOL_H_
#define SRC_SYSTEMS_MULTITOOL_H_

#include "systems/mtsub/Roller.h"
#include "systems/mtsub/Shooter.h"
#include "DigitalInput.h"
#include "systems/mtsub/DefenseArm.h"

class MultiTool{

public:
	MultiTool(Shooter *shooter, Roller *roller,
			DigitalInput *ballsensor, DefenseArm *defensearm);
	~MultiTool();

	Shooter *shooty;
	Roller *rolly;
	DigitalInput *ballSense;
	DefenseArm *def;

	void moveRoll(); //Move the roller into up or down position
	void shootBall(float leftSpeed, float rightSpeed, bool RPM); //Shoot the ball
	void pickBall(float speed); //Detect if a ball is present and if not attempt to pick one up
	void pickBallNoSensor(float speed); //Attempt to pick up a ball with a sensor override
	void moveDef(); //Move the defense arm up and down
	void raiseAll(); //Raise all multitool systems
	void lowerAll(); //Lower all multitool systems

private:

protected:

};

#endif /* SRC_SYSTEMS_MULTITOOL_H_ */
