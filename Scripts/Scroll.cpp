#include "Scroll.h"
#include "jiki.h"
extern CJiki jiki;

int Scroll::xScroll(bool backFlag)
{
	if (jiki.GetX() < this->x + BACK_POINT && backFlag)this->x=jiki.GetX()-BACK_POINT;
	if (jiki.GetX() > this->x + FORWARD_POINT)this->x = jiki.GetX() - FORWARD_POINT;
	return this->x;
}
Scroll scroll;