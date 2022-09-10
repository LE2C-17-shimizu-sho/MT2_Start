#include "Goal.h"


/// <summary>
	/// �Q�[�����̏�����
	/// </summary>
void	Goal::Initialize(){
	posX = 3134;
	posY = 1568;
	handle = LoadGraph("./Resources/goal.png");
}
/// <summary>
/// �Q�[�����̏�����
/// </summary>
void	Goal::State(){
	flag = false;
}
/// <summary>
/// �X�V
/// </summary>
void	Goal::Update(){
	//�A�ԉ摜
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
/// �`��
/// </summary>
void	Goal::Draw(){
	DrawRectGraph(posX -player->scrollX, posY - player->scrollY, num *w, 0, w, h, handle, TRUE, FALSE);
}

void Goal::OnCollision(){
	flag = true;
}