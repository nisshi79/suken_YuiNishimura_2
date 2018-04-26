#pragma once
#include "Suken.h"

class CMap {
private:
	static const int W = 16;
	static const int H = 12;
	static const int CHIP_GROUP_NUM = 1;
	int map[W][H];
	GraphVec block[1];
public:
	CMap();
	void Draw();
	void Set();
};