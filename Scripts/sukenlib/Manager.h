﻿#pragma once

#include <DxLib.h>
#include <vector>

//#define DEBUG

namespace suken {

	//GameEngine
	struct DrawMode;
	struct Flip;
	class CScene;

	class CInput;
	

	//Object
	class Object;
	template <class Object>
	class Manager;

	//System
	struct SystemSetting;
	class CSystem;

	//Utility
	template<typename T>
	struct Twin;
	typedef Twin<float> Point2D;
	struct Vector2D;

	struct Graph;
	struct Anim;
	struct Font;
	typedef std::vector<Graph> GraphVec;

	class CData;
	struct MCE;

	struct Memory;
	struct CSV;
	
	

	/**
	*	@brief　Main.cppにあるやつ。
	*/
	SystemSetting Config();
	/**
	*	@brief　Main.cppにあるやつ。
	*/
	void Awake();
	/**
	*	@brief　Main.cppにあるやつ
	*/
	void DebugLoopEnter();
	/**
	*	@brief　Main.cppにあるやつ
	*/
	void DebugLoopExit();

	extern CSystem System;

	extern CInput Input;

	int Main(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR lpszCmdLine, int nCmdShow);
}
