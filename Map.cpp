#include "Map.h"

void Map::Initialize()
{
	// �摜��������
	block = LoadGraph("./Resources/block.png");
}

void Map::Update()
{

}

void Map::Draw()
{
	// �`�揈��
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
