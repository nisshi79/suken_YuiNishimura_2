#include "Bullet.h"

float DTR(float deg) {
	return (float)(deg*DX_PI) / 180.0;
}



CBullet::CBullet(int x, int y, int v) {
	this->x = x;
	this->y = y;
	this->v = v;
	deleteFlag = false;
}

void CBullet::Move() {
	x += v;
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

bool CBullet::GetDeleteFlag(){
	return deleteFlag;
}

CBulletManager::CBulletManager() {
	time = 0;
}

void CBulletManager::Appear(int x, int y) {
	if (Input.GetKeyDown(Input.key.D) && time%20 == 0)
		bullets.push_back(CBullet(x, y, BULLET_SPEED));
	time++;
}

void CBulletManager::Move(){
	for (auto i = bullets.begin(); i != bullets.end();) {
		i -> Move();
		if (i->GetDeleteFlag()) {
			i = bullets.erase(i);
		}
		else{
			i++;
		}
		
	}
}

void CBulletManager::Draw() {
	for (auto i = bullets.begin(); i != bullets.end(); i++)i -> Draw();
}

//bool CBulletManager::Hit(int x, int y, int r) {
//	for (int i = 0; i < 10000; i++) {
//		if ((x - bullet[i].GetX())*(x - bullet[i].GetX()) + (y - bullet[i].GetY())*(y - bullet[i].GetY()) <= (r + bullet[i].GetR())*(r + bullet[i].GetR())) {
//			return true;
//		}
//	}
//	return false;
//}
