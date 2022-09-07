#include "Map.h"

void Map::Initialize()
{
	// �摜��������
	block = LoadGraph("block.png");
}

void Map::Update()
{

}

void Map::Draw()
{
	// �`�揈��
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
