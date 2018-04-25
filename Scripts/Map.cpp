#include "Map.h"
#include "MyScene.h"

CMap::CMap() {
	MCE mce("MCE/map.mce");
	
	for (int j = 0; j != W; j++) {
		for (int k = 0; k != H; k++) {
			map[j][k] = mce.Get(mce.layer.A, j, k) - 1;
		}
	}
}



void CMap::Draw(){
	
	
	for(int j = 0; j != W; j++){
		for (int k = 0; k != H; k++) {
			if(map[j][k] >= 0)block[0][map[j][k]].Draw(j * 50, k * 50);
		}
	}
}