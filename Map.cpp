#include "Map.h"

void Map::Initialize()
{
	// ‰æ‘œ‚ğ‰Šú‰»
	block = LoadGraph("./Resources/block.png");
}

void Map::Update()
{

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
