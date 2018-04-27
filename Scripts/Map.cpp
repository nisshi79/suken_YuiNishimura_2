#include "Map.h"
#include "MyScene.h"
#include "Scroll.h"
#include "jiki.h"
extern CJiki jiki;
extern Scroll scroll;

CMap::CMap() {
}
void CMap::Set(){
	MCE mce("MCE/map.mce");
	block[0] = LoadDivGraph("MCE/chip.png", 1, 1, 1, 50, 50);
	for (int j = 0; j != W; j++) {
		for (int k = 0; k != H; k++) {
			map[j][k] = mce.Get(mce.layer.A, j, k) - 1;
		}
	}
}
void CMap::Draw(){
	for(int j = 0; j != W; j++){
		for (int k = 0; k != H; k++) {
			if(map[j][k] >= 0)block[0][map[j][k]].Draw(j * CHIP_SIZE - scroll.xScroll(jiki.GetX()), k * CHIP_SIZE);
		}
	}
}


CMap map;