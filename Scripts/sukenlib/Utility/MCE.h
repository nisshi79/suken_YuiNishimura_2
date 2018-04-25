﻿#pragma once

#include"Data.h"

namespace suken {
	struct MCE {
	public:
		struct Layer {
			enum LayerData {
				A = 0,
				B = 1,
				C = 2
			};
		}static  layer;

		MCE();

		MCE(const char* file);

		/**
		*	FILE：mcepicと、その他のmceファイルがある場所を指定
		*	index：mceを開いた時の上から０，１，２....と数えた番号
		*/
		MCE(const char* FILE,unsigned int index);

		~MCE();

		void Set(const char* file);

		MCE& operator =(const char* file);

		int& Get(Layer::LayerData layer, int x, int y);

		const int& Get(Layer::LayerData layer, int x, int y)const;

		int GetWidth()const;

		int GetHeight()const;

		int GetEdge()const;

		std::string GetGraph(Layer::LayerData layer)const;

		int& operator()(Layer::LayerData layer, int x, int y);

		const int& operator()(Layer::LayerData layer, int x, int y)const;

	private:
		int *chip;
		int width;
		int height;
		int edge;
		std::string graph[3];

		int Array(char layer, int x, int y)const;
	};
}

