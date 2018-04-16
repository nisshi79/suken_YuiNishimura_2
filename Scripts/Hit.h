/**
*@file Input.h
*@brief ��`���m�̏Փ˔���ł��BPhoton���񂪍l�������̂�Nish�����C�u�����̈ꕔ�Ƃ��܂����B
*@author Nish
*/

#pragma once
#include "sukenlib/Manager.h"
#include "Rect.h"
#include "sukenlib/Utility/Primitive.h"
namespace suken {
	bool HitRectRect(const Rect& r1, const Rect& r2) {
		return r1.right > r2.left && r2.right > r1.left && r1.bottom > r2.top && r2.bottom > r1.top;
	}
	/**
	* @brief  ���x�͑������킹�����z��
	*/
	RectFlag HitMRectRect(float& x, float& y, float& vx, float& vy, const Rect& r1, const Rect& r2, const RectFlag& enable = RectFlag(true), RectFlag& flag = RectFlag()) {//���x�͑������킹�����z��
		Vector2D vec = { x,static_cast<float>(y) };

		if (HitRectRect(r1.(vec.x, vec.y), r2)) {
			vec.x -= vx;
			vec.y -= vy;
			Rect l = r1.Add(vec.x, vec.y);

			if (enable.left && (l.top - r2.bottom <= -(l.right - r2.left)) && (l.bottom - r2.top >= l.right - r2.left)) {
				x = r2.left - r1.right;
				vx = 0;
				flag.right = true;
			}
			if (enable.right && (l.top - r2.bottom <= l.left - r2.right) && (l.bottom - r2.top >= -(l.left - r2.right))) {
				x = r2.right - r1.left;
				vx = 0;
				flag.left = true;
			}
			if (enable.top && (l.bottom - r2.top <= l.right - r2.left) && (l.bottom - r2.top <= -(l.left - r2.right))) {
				y = r2.top - r1.bottom;
				vy = 0;
				flag.bottom = true;
			}
			if (enable.bottom && (l.top - r2.bottom >= -(l.right - r2.left)) && (l.top - r2.bottom >= l.left - r2.right)) {
				y = r2.bottom - r1.top;
				vy = 0;
				flag.top = true;
			}
		}
		return flag;
	}
}