#pragma once
#include "Suken.h"

class CJiki {
private:
	const double SCALE=2;
	int x, y;
	double vy, vx;
	const int SIZE = 50;
	const double G = 1;
	const int VELOCITY_LIMIT = 10;
	const double ACCEL=20*SCALE;
	const double AIR_FRIC=0.3*SCALE;
	const double LAND_FRIC = 0.5*SCALE;
	bool landFlag;
	Rect rect;
public:
	CJiki();
	void Move();
	void Draw();
	/*bool Hit();*/
	int GetX(),GetY();
	int GetGunX(), GetGunY();
	int GetVX();
	int GetAccel(),GetAirFric(),GetLandFric(),GetScale();
};
