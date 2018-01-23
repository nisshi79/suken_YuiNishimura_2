#include "MyScene.h"

CBulletManager bullet;
CJiki jiki;

void CSGame::Start() {
	
}

void CSGame::Loop() {
	bullet.Appear();
	bullet.Move();
	jiki.Move();
}

void CSGame::Draw() {
	bullet.Draw();
	jiki.Draw();
}

void CSGame::End() {
	
}

CBulletManager GetBulletManager() {
	return bullet;
}