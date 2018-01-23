#pragma once
#include "Suken.h"

class CJiki {
private:
	int x, y;
	const int R = 10;
	const int V = 5;
public:
	CJiki();
	void Move();
	void Draw();
	bool Hit();
};