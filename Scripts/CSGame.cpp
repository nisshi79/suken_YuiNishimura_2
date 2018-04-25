#include "MyScene.h"


void CSGame::Start() {
	map.Load();
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


