#pragma once

#include "Suken.h"
#include "Bullet.h"
#include "jiki.h"
#include "Map.h"

class CSGame :public CScene {
	//�`�ϐ��錾�`
	CMap map;
	CBulletManager bullet;
	CJiki jiki;
	
	//�������@�摜�̃��[�h�Ȃǂ�
	void Start();
	//�����@���t���[���Ă΂��
	void Loop();
	//�`��@���t���[���Ă΂��
	void Draw();
	//��Еt��	�K�v�Ȃ�g����
	void End();
};