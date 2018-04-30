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

	rect.resize(WIDTH);
	for (int i = 0; i< WIDTH; i++)rect[i].resize(HIGHT);

	buF.resize(WIDTH);
	for (int i = 0; i< WIDTH; i++)buF[i].resize(HIGHT);
	
	enable.resize(WIDTH);
	for (int i = 0; i< WIDTH; i++)enable[i].resize(HIGHT);

	block[0] = LoadDivGraph("MCE/chip.png", 1, 1, 1, 50, 50);
	
	

	for (int j = 0; j != WIDTH; j++) {
		for (int k = 0; k != HIGHT; k++) {
			buf[j][k] = mce.Get(mce.layer.A, j, k) - 1;
			buF[j][k] = false;
			enable[j][k] = true;
			
			if (buf[j][k] == 1) {
				rect[j][k] = { static_cast<float>(j) * 50,static_cast<float>(j) * 50 + 50,static_cast<float>(k) * 50,static_cast<float>(k) * 50 + 50 };
				enable[j][k].Set(true);
				if (buf[j - 1][k] == 1) {
					enable[j][k].left = false;
				}
				if (buf[j + 1][k] == 1) {
					enable[j][k].right = false;
				}
				if (buf[j][k - 1] == 1) {
					enable[j][k].top = false;
				}
				if (buf[j][k + 1] == 1) {
					enable[j][k].bottom = false;
				}
				HitMRectRect(jiki.x, jiki.y, jiki.vx, jiki.vy, jiki.rect, map, enable, buf);
			}
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