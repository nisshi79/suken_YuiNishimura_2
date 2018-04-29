#include "Camera.h"
#include "jiki.h"
#include "Physics.h"
#include "Map.h"

extern Physics physics;
extern CJiki jiki;
int Camera::GetX(bool backFlag){
	if (jiki.GetX() < x + BACK_POINT && backFlag )x = jiki.GetX() - BACK_POINT;
	if (jiki.GetX() > x + FORWARD_POINT)x = jiki.GetX() - FORWARD_POINT;
	if (0 > x)x = 0;
	
	return x;
}
Camera camera;