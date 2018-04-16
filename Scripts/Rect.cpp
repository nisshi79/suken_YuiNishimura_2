#include "Rect.h"
suken::Rect::Rect(float left, float right, float top, float bottom) {
		this->left = left;
		this->top = top;
		this->right = right;
		this->bottom = bottom;
}

suken::Rect::Rect(){}

void suken::Rect::Set(int left, int right, int top, int bottom) {
	this->left = left;
	this->right = right;
	this->top = top;
	this->bottom = bottom;
}


suken::Rect suken::Rect::Add(int x, int y){
	return Rect(left + x, right + x, top + y, bottom + y);
}

suken::Rect suken::Rect::Add()
{
	return Rect();
}

suken::RectFlag::RectFlag() {
	left = false;
	right = false;
	top = false;
	bottom = false;
}

suken::RectFlag::RectFlag(bool init) {
	left = init;
	right = init;
	top = init;
	bottom = init;
}

void suken::RectFlag::Set(bool init) {
	left = init;
	right = init;
	top = init;
	bottom = init;
}