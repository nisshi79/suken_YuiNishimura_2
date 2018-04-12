#pragma once
#include "Suken.h"

class CJiki {
private:
	int x, y, vy, vx;
	const int SIZE = 50;
	const int A = 5;
	const float G = 1;
public:
	CJiki();
	void Move();
	void Gravity();
	void Draw();
	/*bool Hit();*/
	int GetX(),GetY();
	int GetGunX(), GetGunY();
};