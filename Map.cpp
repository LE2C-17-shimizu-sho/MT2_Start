#include "Map.h"

void Map::Initialize()
{
	// ‰æ‘œ‚ğ‰Šú‰»
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
				//ƒvƒŒƒCƒ„[‚Ì‚ ‚½‚è”»’è
				{
					if (CheckSide1(player->x_, player->y_, player->r, MAPCHIP_WIDTH * x, MAPCHIP_HEIGHT * y, MAPCHIP_WIDTH, MAPCHIP_HEIGHT) &&
						CheckSide3(player->x_, player->y_, player->r, MAPCHIP_WIDTH * x, MAPCHIP_HEIGHT * y, MAPCHIP_WIDTH, MAPCHIP_HEIGHT))
					{
						DrawFormatString(100, 0, GetColor(255, 255, 255), "1");
						player->MapCollisionX();

					}
					if (CheckSide2(player->x_, player->y_, player->r, MAPCHIP_WIDTH * x, MAPCHIP_HEIGHT * y, MAPCHIP_WIDTH, MAPCHIP_HEIGHT) &&
						CheckSide4(player->x_, player->y_, player->r, MAPCHIP_WIDTH * x, MAPCHIP_HEIGHT * y, MAPCHIP_WIDTH, MAPCHIP_HEIGHT))
					{
						DrawFormatString(110, 0, GetColor(255, 255, 255), "2");
						player->MapCollisionY();
					}
				}
				//“G‚Ì‚ ‚½‚è”»’è
				{
					for (size_t k = 0; k < 14; k++)
					{
						if (CheckCircleDot4(enemy_[k]->posX, enemy_[k]->posY, enemy_[k]->r, MAPCHIP_WIDTH * x, MAPCHIP_HEIGHT * y, MAPCHIP_WIDTH, MAPCHIP_HEIGHT))
						{
							enemy_[k]->DeathCollision();
						}
					}
				}

				//” ‚Ì“–‚½‚è”»’è
				{
					for (size_t i = 0; i < 2; i++)
					{
						if (CheckBox(box[i]->posX, box[i]->posY, box[i]->width, box[i]->higth, MAPCHIP_WIDTH * x, MAPCHIP_HEIGHT * y, MAPCHIP_WIDTH, MAPCHIP_HEIGHT))
						{
							box[i]->OnCollisionX();

							box[i]->OnCollisionY();
							DrawFormatString(120, 0, GetColor(255, 255, 255), "3");
							
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
}

void Map::Draw()
{
	// •`‰æˆ—
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