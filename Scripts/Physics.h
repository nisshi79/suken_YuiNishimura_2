#pragma once
#include "Suken.h"
enum DTR {
	UP,
	DOWN,
	LEFT,
	RIGHT
};
class Physics {
public:
	void Fric(double& v, double flic);
	void Accel(double & v, DTR dtr, double power, int velLimit);
};
