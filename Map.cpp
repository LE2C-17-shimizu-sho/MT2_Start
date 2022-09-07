#include "Map.h"

void Map::Initialize()
{
	// ‰æ‘œ‚ğ‰Šú‰»
	block = LoadGraph("block.png");
}

void Map::Update()
{

}

void Map::Draw()
{
	// •`‰æˆ—
	for (int y = 0; y < 45; y++)
	{
		for (int x = 0; x < 80; x++)
		{
			if (map[y][x] == 1)
			{
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, block, true);
			}
		}
	}
}
