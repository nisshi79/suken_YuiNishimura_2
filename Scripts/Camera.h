#pragma once
#include "Suken.h"

class Camera {
private:
	int x;
	
	static const int BACK_POINT=200;
	static const int FORWARD_POINT=200;
	static const int ACCEL = 10;
	const double FRIC = 0.3;
public:
	
	int GetX(bool backFlag = true);
};