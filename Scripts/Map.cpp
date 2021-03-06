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

	
	enable.resize(WIDTH);
	for (int i = 0; i< WIDTH; i++)enable[i].resize(HIGHT);

	block[0] = LoadDivGraph("MCE/chip.png", 1, 1, 1, 50, 50);
	for (int j = 0; j != WIDTH; j++) {
		for (int k = 0; k != HIGHT; k++) {
			buf[j][k] = mce.Get(mce.layer.A, j, k);
			buF = false;
		}
	}
	

	for (int j = 0; j != WIDTH; j++) {
		for (int k = 0; k != HIGHT; k++) {
			
			
			if (buf[j][k] == 1) {
				rect[j][k].Set(j * CHIP_SIZE, j * CHIP_SIZE + CHIP_SIZE, k * CHIP_SIZE, k * CHIP_SIZE + CHIP_SIZE);
				enable[j][k].Set(true);

				if (j == 0) {
					enable[j][k].left = false;
				}
				else if (buf[j-1][k] == 1) {
					enable[j][k].left = false;
				}
				
				if (j == WIDTH-1) {
					enable[j][k].right = false;
				}
				else if (buf[j+1][k] == 1) {
					enable[j][k].right = false;
				}
				
				if (k == 0) {
					enable[j][k].top = false;
				}
				else if (buf[j][k-1] == 1) {
					enable[j][k].top = false;
				}
				
				if (k == HIGHT-1) {
					enable[j][k].bottom = false;
				}
				else if (buf[j][k+1] == 1) {
					enable[j][k].bottom = false;
				}
				
			}
		}
	}
}
void CMap::Draw(){
	for(int j = 0; j != WIDTH; j++){
		for (int k = 0; k != HIGHT; k++) {
			if(buf[j][k]>=1)block[0][buf[j][k]-1].Draw(j * CHIP_SIZE - camera.GetX(), k * CHIP_SIZE);
		}
	}
}
void CMap::HitJiki(){
	buF = false;
	for (int j = 0; j != WIDTH; j++) {
		for (int k = 0; k != HIGHT; k++) {
			
			HitMRectRect(jiki.x, jiki.y, jiki.vx, jiki.vy, jiki.rect, rect[j][k], enable[j][k], buF);
			
		}
	}
	jiki.landFlag = buF.bottom;

}
CMap map;