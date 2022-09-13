#include "Map.h"

void Map::Initialize()
{
	// 画像を初期化
	//block = LoadGraph("./Resources/block.png");
}

void Map::Update()
{
	for (int y = 0; y < 49; y++)
	{
		for (int x = 0; x < 90; x++)
		{
			if (map[y][x] == 1)
			{	
				//プレイヤーのあたり判定
				{
					/*if (CheckSide1(player->x_, player->y_, player->r, MAPCHIP_WIDTH * x, MAPCHIP_HEIGHT * y, MAPCHIP_WIDTH, MAPCHIP_HEIGHT) &&
						CheckSide3(player->x_, player->y_, player->r, MAPCHIP_WIDTH * x, MAPCHIP_HEIGHT * y, MAPCHIP_WIDTH, MAPCHIP_HEIGHT))
					{
						player->MapCollisionX();
					
					}
					if (CheckSide2(player->x_, player->y_, player->r, MAPCHIP_WIDTH * x, MAPCHIP_HEIGHT * y, MAPCHIP_WIDTH, MAPCHIP_HEIGHT) &&
						CheckSide4(player->x_, player->y_, player->r, MAPCHIP_WIDTH * x, MAPCHIP_HEIGHT * y, MAPCHIP_WIDTH, MAPCHIP_HEIGHT))
					{
						player->MapCollisionY();
					}*/
				}

				//箱の当たり判定
				{
					for (size_t i = 0; i < 2; i++)
					{
						if (CheckBox(box[i]->posX, box[i]->posY, box[i]->width, box[i]->higth, MAPCHIP_WIDTH * x, MAPCHIP_HEIGHT * y, MAPCHIP_WIDTH, MAPCHIP_HEIGHT))
						{
							box[i]->OnCollisionX();

							box[i]->OnCollisionY();							
						}
					}
				}
			
				//敵のあたり判定
				{
					for (size_t k = 0; k < 14; k++)
					{
						if (CheckSideE1(enemy_[k]->posX, enemy_[k]->posY, enemy_[k]->r, MAPCHIP_WIDTH * x, MAPCHIP_HEIGHT * y, MAPCHIP_WIDTH, MAPCHIP_HEIGHT,4))
						{
							enemy_[k]->OnCollisionX();
						}
						if (CheckSideE2(enemy_[k]->posX, enemy_[k]->posY, enemy_[k]->r, MAPCHIP_WIDTH * x, MAPCHIP_HEIGHT * y, MAPCHIP_WIDTH, MAPCHIP_HEIGHT,4))
						{
							enemy_[k]->OnCollisionY();
						}
						if (CheckSideE3(enemy_[k]->posX, enemy_[k]->posY, enemy_[k]->r, MAPCHIP_WIDTH * x, MAPCHIP_HEIGHT * y, MAPCHIP_WIDTH, MAPCHIP_HEIGHT,4))
						{
							enemy_[k]->OnCollisionX2();
						}
						if (CheckSideE4(enemy_[k]->posX, enemy_[k]->posY, enemy_[k]->r, MAPCHIP_WIDTH * x, MAPCHIP_HEIGHT * y, MAPCHIP_WIDTH, MAPCHIP_HEIGHT,4))
						{
							enemy_[k]->OnCollisionY2();
						}

					}
				}
			}
				
				//if (CheckSide1(player->x_,player->y_,player->r, MAPCHIP_WIDTH*x, MAPCHIP_HEIGHT*y,  MAPCHIP_WIDTH , MAPCHIP_HEIGHT))
				//{
				//	player->MapCollisionX();
				//}
		}
	}
}

void Map::Draw()
{
	// 描画処理
	/*for (int y = 0; y < 49; y++)
	{
		for (int x = 0; x < 90; x++)
		{
			if (map[y][x] == 1)
			{
				DrawGraph((x * BLOCK_SIZE)-player->scrollX, (y * BLOCK_SIZE) - player->scrollY, block, true);
			}
		}
	}*/
}

void	Map::SetEnemy(Enemy* enemy,int	i) {
	enemy_[i] = enemy;
}

void	Map::SetBox(Box* box_, int i) {
	box[i] = box_;
}