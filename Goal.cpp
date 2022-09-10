#include "Goal.h"


/// <summary>
	/// ゲーム内の初期化
	/// </summary>
void	Goal::Initialize(){
	posX = 3134;
	posY = 1568;
	handle = LoadGraph("./Resources/goal.png");
}
/// <summary>
/// ゲーム内の初期化
/// </summary>
void	Goal::State(){
	flag = false;
}
/// <summary>
/// 更新
/// </summary>
void	Goal::Update(){
	//連番画像
	if (timer-- <= 0)
	{
		num++;
		timer = time;
		if (num == 4)
		{
			num = 0;
		}
	}
}
/// <summary>
/// 描画
/// </summary>
void	Goal::Draw(){
	DrawRectGraph(posX -player->scrollX, posY - player->scrollY, num *w, 0, w, h, handle, TRUE, FALSE);
}

void Goal::OnCollision(){
	flag = true;
}