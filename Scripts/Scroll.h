#pragma once
#include "Suken.h"

class Scroll {
private:
	int x;
public:
	int GetX();
	void xScroll(int x,int back, int forward,bool backFlag=false);
};