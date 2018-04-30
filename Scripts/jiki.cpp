#include "jiki.h"
#include "Bullet.h"
#include "Camera.h"
#include "Physics.h"
extern Camera camera;
extern KeyConfig keyconfig;
extern Physics physics;
extern CBulletManager GetBulletManager();

CJiki::CJiki() {
	x = 100;
	y=200;
	landFlag = false;
	
	rect.left = 0;
	rect.right = 50;
	rect.top = 0;
	rect.bottom = 50;
	place = {x, y};
}

void CJiki::Move() {
	if (keyconfig.Right())physics.Accel(vx,RIGHT,ACCEL,VELOCITY_LIMIT);
	if (keyconfig.Left())physics.Accel(vx, LEFT, ACCEL, VELOCITY_LIMIT);
		
	if(landFlag)physics.Fric(vx, LAND_FRIC);
	if(!landFlag)physics.Fric(vx, AIR_FRIC);
	
	if (!landFlag)physics.Accel(vy, DOWN, G, VELOCITY_LIMIT);

	x += vx;

	
	
	
	y += vy;
}



void CJiki::Draw() {
	DrawBox(x-camera.GetX(), y, x + SIZE - camera.GetX() , y + SIZE, RED, true);
}

//bool CJiki::Hit() {
//	for (int i = 0; i != 16; ++i) {
//		for (int k = 0; k != 12; ++k) {
//			
//		}
//	}
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

int CJiki::GetVX()
{
	return vx;
}

int CJiki::GetAccel()
{
	return ACCEL;
}

int CJiki::GetAirFric()
{
	return AIR_FRIC;
}

int CJiki::GetLandFric()
{
	return LAND_FRIC;
}

int CJiki::GetScale()
{
	return SCALE;
}

CJiki jiki;