#include "MyScene.h"
GraphVec CSGame::block[1];
CBulletManager bullet;
CJiki jiki;
CMap map;
void CSGame::Start() {
	block[0] = LoadDivGraph("MCE/chip.png", 1, 1, 1, 50, 50);
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