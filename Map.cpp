#include "Map.h"

void Map::Initialize()
{
	// ‰æ‘œ‚ğ‰Šú‰»
	block = LoadGraph("./Resources/block.png");
}

void Map::Update()
{
	for (int y = 0; y < 49; y++)
	{
		for (int x = 0; x < 90; x++)
		{
			if (map[y][x] == 1)
			{		
				if (CheckSide1(player->x_, player->y_, player->r, MAPCHIP_WIDTH * x, MAPCHIP_HEIGHT * y, MAPCHIP_WIDTH, MAPCHIP_HEIGHT)&&
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
	for (int y = 0; y < 49; y++)
	{
		for (int x = 0; x < 90; x++)
		{
			if (map[y][x] == 1)
			{
				DrawGraph((x * BLOCK_SIZE)-player->scrollX, (y * BLOCK_SIZE) - player->scrollY, block, true);
			}
		}
	}
}
