#pragma once
#include "Suken.h"

class CMap {
private:
	static const int W = 16;
	static const int H = 12;
	static const int CHIP_GROUP_NUM = 1;
	GraphVec block[CHIP_GROUP_NUM];
	int map[W][H];
public:
	CMap();
	void Draw();

};