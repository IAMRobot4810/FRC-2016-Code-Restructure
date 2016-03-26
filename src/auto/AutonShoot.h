#ifndef SRC_AUTONSHOOT_H
#define SRC_AUTONSHOOT_H

#include "systems/Shooter.h"
#include "systems/DefenseArm.h"

class AutonShoot{
private:
	Shooter* auton_shot;
	DefenseArm* arm;
public:
	AutonShoot();
	~AutonShoot();

	void lower_cradle();
	void lower_arm();

	void low_shot();
	void high_shot();

};


#endif
