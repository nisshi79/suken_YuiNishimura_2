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
	void Fric(int& v, double flic);
	void Accel(int & v, DTR dtr, double power, int velLimit);
};
