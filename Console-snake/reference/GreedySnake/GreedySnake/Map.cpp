#include "stdafx.h"
#include "Map.h"
#include <fstream>

int Map::iMapsOrder = 0;
Map::Map(void)
{
}

Map::~Map(void)
{
}

int** Map::getBlocks()
{
	return (int**)iBlocks;
}

bool Map::loadMap()
{
	iMapsOrder++;
	if (iMapsOrder > NUM_OF_MAPS)
		return false;

	std::ifstream file("map.info");
	char ch;
	int count = 0;

	while(file >> ch)
	{
		if(ch=='#')
			count++;
		if(count == iMapsOrder)
			break;
	}

	for (int i = 0; i< MAP_HEIGHT; i++)
	{
		for(int j = 0; j< MAP_WIDTH; j++)
		{
			file >> ch;
			if (ch != '1')
				iBlocks[i][j] = MAP_SAFESPACE;
			else
				iBlocks[i][j] = MAP_OBSTACLE;
		}
	}
	file.close();
	return true;
}