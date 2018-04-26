#include "jiki.h"
#include "Bullet.h"
extern KeyConfig keyconfig;

extern CBulletManager GetBulletManager();

CJiki::CJiki() {
	x = 100;
	y = 300;
	landFlag = false;
}

void CJiki::Fric(double& v, double flic){
	if (v<flic && v>-flic)v = 0;
	if (v >= flic)v -= flic;
	if (v <= -flic)v += flic;
}

void CJiki::Move() {
	if (keyconfig.Right())vx += ACCEL;
	if (keyconfig.Left())vx -= ACCEL;
	
	if (vx > VELOCITY_LIMIT)vx = VELOCITY_LIMIT;
	if (vx < -VELOCITY_LIMIT)vx = -VELOCITY_LIMIT;
	
	if(landFlag)Fric(vx, LAND_FRIC);
	if(!landFlag)Fric(vx, AIR_FRIC);
	
	x += vx;

	/*this->Gravity();*/
	if(y==300+SIZE)landFlag = true;
}

void CJiki::Gravity(){
	if(vy<VELOCITY_LIMIT)vy += G;
	if (y + vy + 50 > 600) {
		y = 600;
		vy = 0;
		
	}
		y += vy;

	//temp
	
}

void CJiki::Draw() {
	DrawBox(x, y, x + SIZE, y + SIZE, RED, true);
}

//bool CJiki::Hit() {
//	rect()
//	HitMRectRect();
//}

int CJiki::GetX() {
	return this -> x;
}

int CJiki::GetY() {
	return this -> y;
}

int CJiki::GetGunX(){
	return x + 50;
}

int CJiki::GetGunY(){
	return y + 25;
}
