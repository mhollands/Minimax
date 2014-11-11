#include "Base_Header.h"

class NnCBoard: public Board_Base
{
	//positive player = x, negative player = 0
public:

	NnCBoard()
	{
		for (int i = 0; i < 9; i++)
		{
			spaces[i] = 0;
		}
	}

	int countPossibleMoves(bool player)
	{
		int count = 0;
		for (int i = 0; i < 9; i++)
		{
			if (spaces[i] == 0)
			{
				count++;
			}
		}

		return count;
	}

private:
	int spaces[9]
};