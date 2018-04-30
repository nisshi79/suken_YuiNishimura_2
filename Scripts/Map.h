#pragma once
#include "Suken.h"
extern

class CMap {
private:
	static const int H = 12;
	static const int CHIP_SIZE = 50;
	static const int CHIP_GROUP_NUM = 1;
	std::vector< std::vector<int> > buf;
	GraphVec block[1];
	int kBufP,jBufM,jBufP,kBufM;
	MCE mce;
public:
	std::vector< std::vector<Rect> > rect;
	std::vector< std::vector<RectFlag> > enable;
	std::vector< std::vector<RectFlag> > buF;

	int WIDTH;
	int HIGHT;
	CMap();
	void Draw();
	void HitJiki();
	void Set();
};