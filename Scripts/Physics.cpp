#include "Physics.h"

void Physics::Fric(int& v, double flic) {
	if (v<flic && v>-flic)v = 0;
	if (v >= flic)v -= flic;
	if (v <= -flic)v += flic;
}
void Physics::Accel(int& v,DTR dtr,double power,int velLimit) {
	if (dtr == RIGHT || dtr == DOWN)v += power;
	if (dtr == LEFT || dtr == UP)v -= power;
	
	if (v > velLimit)v = velLimit;
	if (v < -velLimit)v = -velLimit;
}
Physics physics;
