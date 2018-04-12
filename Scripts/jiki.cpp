#include "jiki.h"
#include "Bullet.h"

extern CBulletManager GetBulletManager();

CJiki::CJiki() {
	x = 100;
	y = 300;
}

void CJiki::Move() {
	if (Input.GetKeyDown(Input.key.RIGHT))vx += A;
	if (Input.GetKeyDown(Input.key.LEFT))vx -= A;
	if (Input.GetKeyDown(Input.key.UP))vy -= A;
	x += vx;
}

void CJiki::Gravity(){
	vy += G;
	y += vy;
}

void CJiki::Draw() {
	DrawBox(x, y, x + SIZE, y + SIZE, RED, true);
}

//bool CJiki::Hit() {
//	return GetBulletManager().Hit(x, y, R);
//}

int CJiki::GetX() {
	return this -> x;
}

int CJiki::GetY() {
	return this -> y;
}

int CJiki::GetGunX()
{
	return x + 50;
}

int CJiki::GetGunY()
{
	return y + 25;
}
