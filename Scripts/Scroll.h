#pragma once
#include "Suken.h"

class Scroll {
private:
	int x;
	static const int BACK_POINT=50;
	static const int FORWARD_POINT=400;
	static const int DELAY_FLAMES = 30;
public:
	
	int xScroll(bool backFlag = true);
};