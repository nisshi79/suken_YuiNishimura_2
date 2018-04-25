#pragma once

#include "Suken.h"
#include "Bullet.h"
#include "jiki.h"
#include "Map.h"

class CSGame :public CScene {
	//～変数宣言～
	CMap map;
	CBulletManager bullet;
	CJiki jiki;
	
	//初期化　画像のロードなども
	void Start();
	//処理　毎フレーム呼ばれる
	void Loop();
	//描画　毎フレーム呼ばれる
	void Draw();
	//後片付け	必要なら使おう
	void End();
};