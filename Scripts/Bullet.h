#pragma once

#include "Suken.h"
#include "KeyConfig.h"



static int BULLET_SPEED = 15;

class CBullet {
private:
	int v;
	float x, y;
	const int R = 10;
	bool deleteFlag;
public:
	friend struct Hit;
	CBullet(int x, int y, int v);
	void Move();
	void Draw();
	int GetX();
	int GetY();
	int GetR();
	bool GetDeleteFlag();
};

class CBulletManager {
private:
	std::list<CBullet>bullets;
	int time;
public:
	CBulletManager();
	void Appear(int x, int y);
	void Move();
	void Draw();
	/*bool Hit(int x, int y, int r);*/
};
