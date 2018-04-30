#include "MyScene.h"



extern CMap map;
extern CJiki jiki;
extern CBulletManager bullet;

void CSGame::Start() {
	map.Set();
}

void CSGame::Loop() {
	bullet.Appear(jiki.GetGunX(),jiki.GetGunY());
	bullet.Move();
	jiki.Move();
	map.HitJiki();
}

void CSGame::Draw() {
	map.Draw();
	bullet.Draw();
	jiki.Draw();
}

void CSGame::End() {
	 
}