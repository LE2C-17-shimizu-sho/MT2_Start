#pragma once

#include "Dxlib.h"

class Title
{
public:
	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

private:
	int title = 0;
};

