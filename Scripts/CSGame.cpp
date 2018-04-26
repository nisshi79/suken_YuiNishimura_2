#include "MyScene.h"

CBulletManager bullet;
CJiki jiki;
CMap map;

void CSGame::Start() {
	map.Set();
}

void CSGame::Loop() {
	bullet.Appear(jiki.GetGunX(),jiki.GetGunY());
	bullet.Move();
	jiki.Move();



}

void CSGame::Draw() {
	map.Draw();
	bullet.Draw();
	jiki.Draw();
}

void CSGame::End() {
	 
}