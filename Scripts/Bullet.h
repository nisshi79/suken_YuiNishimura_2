#pragma once

#include "Suken.h"

class CBullet {
private:
	int v;
	float rad, x, y;
	const int R = 10;
public:
	friend struct Hit;
	void Set(int x, int y, int v, float rad);
	void Move();
	void Draw();
	int GetX();
	int GetY();
	int GetR();
};

class CBulletManager {
private:
	CBullet bullet[10000];
	int time;
public:
	CBulletManager();
	void Appear();
	void Move();
	void Draw();
	bool Hit(int x, int y, int r);
};