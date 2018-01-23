#include "jiki.h"
#include "Bullet.h"

extern CBulletManager GetBulletManager();

CJiki::CJiki() {
	x = 100;
	y = 300;
}

void CJiki::Move() {
	if (Input.GetKeyDown(Input.key.RIGHT))x += V;
	if (Input.GetKeyDown(Input.key.LEFT))x -= V;
	if (Input.GetKeyDown(Input.key.UP))y -= V;
	if (Input.GetKeyDown(Input.key.DOWN))y += V;
}

void CJiki::Draw() {
	if (Hit()) {
		DrawCircle(x, y, R, BLUE, true);
	}
	else {
		DrawCircle(x, y, R, GREEN, true);
	}
}

bool CJiki::Hit() {
	return GetBulletManager().Hit(x, y, R);
}