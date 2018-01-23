#include "Bullet.h"

float DTR(float deg) {
	return (float)(deg*DX_PI) / 180.0;
}

void CBullet::Set(int x, int y, int v, float rad) {
	this->x = x;
	this->y = y;
	this->v = v;
	this->rad = rad;
}

void CBullet::Move() {
	x += (float)v*cos(rad);
	y += (float)v*sin(rad);
}

void CBullet::Draw() {
	DrawCircle(x, y, R, RED, true);
}

int CBullet::GetX() {
	return x;
}

int CBullet::GetY() {
	return y;
}

int CBullet::GetR() {
	return R;
}

CBulletManager::CBulletManager() {
	time = 0;
}

void CBulletManager::Appear() {
	if (time % 5 == 0)bullet[time / 5].Set(400, 300, 5, DTR(GetRand(359)));
	time++;
}

void CBulletManager::Move() {
	for (int i = 0; i < 10000; i++)bullet[i].Move();
}

void CBulletManager::Draw() {
	for (int i = 0; i < 10000; i++)bullet[i].Draw();
}

bool CBulletManager::Hit(int x, int y, int r) {
	for (int i = 0; i < 10000; i++) {
		if ((x - bullet[i].GetX())*(x - bullet[i].GetX()) + (y - bullet[i].GetY())*(y - bullet[i].GetY()) <= (r + bullet[i].GetR())*(r + bullet[i].GetR())) {
			return true;
		}
	}
	return false;
}