#include "Map.h"
#include "MyScene.h"
#include "Camera.h"
#include "jiki.h"
extern CJiki jiki;
extern Camera camera;

CMap::CMap() {
}
void CMap::Set(){
	mce.Set("MCE/map.mce");
	
	WIDTH = mce.GetWidth();
	HIGHT = mce.GetHeight();
	buf.resize(WIDTH);
	for(int i = 0; i< WIDTH; i++)buf[i].resize(HIGHT);

	block[0] = LoadDivGraph("MCE/chip.png", 1, 1, 1, 50, 50);
	
	for (auto j = 0; j != WIDTH; j++) {
		for (auto k = 0; k != HIGHT; k++) {
			buf[j][k] = mce.Get(mce.layer.A, j, k) - 1;
		}
	}
}
void CMap::Draw(){
	for(int j = 0; j != WIDTH; j++){
		for (int k = 0; k != HIGHT; k++) {
			if(buf[j][k] >= 0)block[0][buf[j][k]].Draw(j * CHIP_SIZE - camera.GetX(), k * CHIP_SIZE);
		}
	}
}
CMap map;