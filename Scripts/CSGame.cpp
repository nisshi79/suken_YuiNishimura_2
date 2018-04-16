#include "MyScene.h"

CBulletManager bullet;
CJiki jiki;
CMap map;
void CSGame::Start() {
}
void CSGame::Loop() {
	bullet.Appear(jiki.GetGunX(),jiki.GetGunY());
	bullet.Move();
	/*jiki.Gravity();*/
	jiki.Move();
}

void CSGame::Draw() {
	map.Draw();
	bullet.Draw();
	jiki.Draw();
}

void CSGame::End() {
	 
}

CBulletManager GetBulletManager() {
	return bullet;
}