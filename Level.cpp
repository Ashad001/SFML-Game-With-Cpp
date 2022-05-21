#include "Level.h"

void Level::LevelSelect(int lvl)
{
	int LEVEL1[20 * 20] =
	{
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
		1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1,
		1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1,
		1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
		1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
		1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1,
		1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1,
		1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0,
		1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1,
		1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1,
		1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1,
		1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
		1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,

	};
	int LEVEL2[20 * 20] =
	{
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
		1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 3, 3, 3, 3, 1,
		1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1,
		1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1,
		1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1,
		1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1,
		1, 0, 3, 3, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 3, 0, 3, 1,
		1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 3, 0, 3, 1,
		1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 3, 0, 3, 1,
		1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 3, 1,
		1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 3, 1,
		1, 1, 1, 0, 3, 3, 1, 1, 1, 1, 1, 0, 3, 3, 0, 0, 0, 1, 0, 1,
		1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 3, 1, 0, 1,
		1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 3, 3, 0, 1, 0, 1, 1, 1,
		1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0,
		1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,

	};
	int LEVEL3[20 * 20] =
	{
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
		1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 3, 3, 3, 3, 1,
		1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 4, 1,
		1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1,
		1, 1, 4, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1,
		1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1,
		1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1,
		1, 0, 3, 3, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 3, 0, 3, 1,
		1, 0, 1, 4, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 3, 0, 3, 1,
		1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 3, 0, 3, 1,
		1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 3, 1,
		1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 3, 1,
		1, 0, 1, 0, 3, 3, 1, 1, 1, 1, 1, 0, 3, 3, 0, 0, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 3, 1, 4, 1,
		1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 3, 3, 0, 1, 0, 1, 1, 1,
		1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 4, 0, 0, 0,
		1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,

	};
	int LEVEL4[20 * 20] =
	{
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		0, 0, 0, 3, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3,
		3, 3, 0, 3, 0, 3, 3, 0, 3, 0, 3, 3, 3, 3, 0, 3, 3, 3, 3, 3,
		3, 3, 0, 3, 0, 3, 3, 0, 3, 0, 3, 3, 3, 3, 0, 3, 3, 3, 4, 3,
		3, 3, 0, 0, 0, 3, 3, 0, 3, 0, 3, 3, 3, 3, 0, 3, 3, 3, 0, 3,
		3, 3, 4, 3, 3, 3, 3, 0, 3, 0, 3, 3, 3, 3, 0, 0, 3, 3, 0, 3,
		3, 0, 0, 0, 0, 0, 3, 0, 3, 0, 3, 3, 3, 3, 3, 0, 3, 3, 0, 3,
		3, 0, 3, 3, 3, 0, 3, 0, 3, 0, 3, 3, 3, 3, 3, 0, 3, 3, 0, 3,
		3, 0, 3, 3, 3, 0, 0, 0, 3, 0, 3, 3, 3, 3, 3, 0, 0, 0, 0, 3,
		3, 0, 3, 3, 3, 3, 3, 3, 3, 0, 3, 3, 3, 3, 3, 0, 3, 0, 3, 3,
		3, 0, 3, 4, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 0, 3, 3,
		3, 0, 3, 0, 3, 3, 3, 3, 3, 3, 3, 4, 0, 0, 0, 0, 3, 0, 3, 3,
		3, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 0, 3, 3, 3, 3, 3, 0, 3, 3,
		3, 0, 3, 0, 3, 3, 3, 3, 3, 3, 3, 0, 3, 3, 3, 3, 0, 0, 3, 3,
		3, 0, 3, 0, 3, 3, 3, 3, 3, 3, 3, 0, 3, 3, 0, 0, 0, 3, 0, 3,
		3, 0, 3, 0, 3, 0, 3, 3, 3, 3, 3, 0, 3, 3, 0, 3, 3, 3, 4, 3,
		3, 0, 3, 0, 3, 0, 3, 3, 3, 3, 3, 0, 3, 3, 0, 3, 0, 3, 3, 3,
		3, 0, 3, 0, 0, 3, 3, 3, 3, 3, 3, 0, 3, 3, 0, 3, 4, 0, 0, 0,
		3, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,

	};
	switch (lvl)
	{
	case 1: {
		for (int i = 0; i < 400; i++)
		{
			levelarr[i] = LEVEL1[i];
			cout << levelarr[i];
		}
		break;
	}
	case 2: {
		for (int i = 0; i < 400; i++)
		{
			levelarr[i] = LEVEL2[i];
		}
		break;
	}
	case 3: {
		for (int i = 0; i < 400; i++)
		{
			levelarr[i] = LEVEL3[i];
		}
		break;
	}
	case 4: {
		for (int i = 0; i < 400; i++)
		{
			levelarr[i] = LEVEL4[i];
		}
		break;
	}
	default:
		break;
	}
}
