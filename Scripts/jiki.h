#pragma once
#include "Suken.h"

class CJiki {
private:
	
	const double SCALE=30;
	double x, y, vy, vx;
	const int SIZE = 50;
	const double G = 1;
	const int VELOCITY_LIMIT = 10;
	const double ACCEL=2*SCALE;
	const double AIR_FRIC=0.3;
	const double LAND_FRIC = 0.5*SCALE;
	bool landFlag;
	Rect rect;
public:
	CJiki();
	void Fric(double& v,double flic);
	void Move();
	void Gravity();
	void Draw();
	/*bool Hit();*/
	int GetX(),GetY();
	int GetGunX(), GetGunY();
};
