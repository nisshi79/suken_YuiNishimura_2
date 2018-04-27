#include "jiki.h"
#include "Bullet.h"
#include "Scroll.h"
#include "Physics.h"
extern Scroll scroll;
extern KeyConfig keyconfig;
extern Physics physics;
extern CBulletManager GetBulletManager();

CJiki::CJiki() {
	x = 100;
	y = 300;
	landFlag = true;
}

void CJiki::Move() {
	if (keyconfig.Right())physics.Accel(vx,RIGHT,ACCEL,VELOCITY_LIMIT);
	if (keyconfig.Left())physics.Accel(vx, LEFT, ACCEL, VELOCITY_LIMIT);
		
	if(landFlag)physics.Fric(vx, LAND_FRIC);
	if(!landFlag)physics.Fric(vx, AIR_FRIC);
	
	x += vx;

	
	if(y==300+SIZE)landFlag = true;
	
	//temp
	if (y + vy + 50 > 600) {
		y = 600;
		vy = 0;
	}
	y += vy;
}



void CJiki::Draw() {
	DrawBox(x-scroll.xScroll(x), y, x + SIZE - scroll.xScroll(x) , y + SIZE, RED, true);
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

CJiki jiki;