#pragma once
/**
*@file Rect.h
*@brief 矩形関連を扱います。
*@author Nish
*/


#include "sukenlib/Manager.h"

namespace suken {
	struct Rect {
	public:
		float left, right, top, bottom;
		Rect(float left, float right, float top, float bottom);
		Rect();
		Rect Add(int x, int y);
		Rect Add();
		void Set(int left, int right, int top, int bottom);

		
	};
	struct RectFlag {
	public:
		bool left, right, top, bottom;
		RectFlag();
		RectFlag(bool init);
		void Set(bool init);
	};
}
