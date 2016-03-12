/*
 * InOutConverter.h
 *
 *  Created on: Mar 11, 2016
 *      Author: 1750800404
 */

#ifndef SRC_TELEOP_INOUTCONVERTER_H_
#define SRC_TELEOP_INOUTCONVERTER_H_

#include "StickControl.h"
#include "util/Deadband.h"
#include "util/UnitScaling.h"
#include "SmartDashboard/SmartDashboard.h"
#include "util/ConstantVals.h"

class InOutConverter{

public:
	InOutConverter();
	~InOutConverter();

	double stickOut(StickControl *cont, int axis);
	double trigOut(StickControl *cont, int axis);

private:
protected:

};

#endif /* SRC_TELEOP_INOUTCONVERTER_H_ */
