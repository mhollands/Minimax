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

	NnCBoard(int newSpaces[9])
	{
		for (int i = 0; i < 9; i++)
		{
			spaces[i] = newSpaces[i];
		}
	}

	NnCBoard(int a, int b)
	{
		for (int i = 0; i < 8; i++)
		{
			if ((a & (1 << i)) != 0)
			{
				spaces[i] = 1;
				continue;
			}

			if ((b & (1 << i)) != 0)
			{
				spaces[i] = -1;
				continue;
			}

			spaces[i] = 0;
		}
		spaces[8] = 0;
	}

	Board_Base* clone()
	{
		int newSpaces[9];
		for (int i = 0; i < 9; i++)
		{
			newSpaces[i] = spaces[i];
		}

		return new NnCBoard(newSpaces);
	}

	void setPiece(long data)
	{
		if (data > 1000)
		{
			spaces[data - 1000] = -1;
			return;
		}

		spaces[data] = 1;
		return;
	}

	vector<Board_Base*> listPossibleMoves(bool player)
	{
		vector<Board_Base*> possibleMoves;

		if (calculateHeuristic() != 0)
		{
			return possibleMoves;
		}

		int newSpaces[9];
		for (int i = 0; i < 9; i++)
		{
			newSpaces[i] = spaces[i];
		}

		for (int i = 0; i < 9; i++)
		{
			if (spaces[i] == 0)
			{
				newSpaces[i] = (player ? 1 : -1);
				possibleMoves.push_back(new NnCBoard(newSpaces));
				newSpaces[i] = 0;
			}
		}

		return possibleMoves;
	}

	int calculateHeuristic()
	{
		int rowCounts[5];

		for (int i = 0; i < 5; i++)
		{
			rowCounts[i] = 0;
		}

		for (int i = 0; i < 3; i++)
		{
			int colCount = 0;
			for (int j = 0; j < 3; j++)
			{
				int pos = j * 3 + i;

				colCount += spaces[pos];
				rowCounts[j] += spaces[pos];

				if (i == j)
				{
					rowCounts[3] += spaces[pos];
				}

				if (i == 2 - j)
				{
					rowCounts[4] += spaces[pos];
				}
			}
			
			if (colCount == 3 || colCount == -3)
			{
				return colCount / 3;
			}
		}

		for (int i = 0; i < 5; i++)
		{
			if (rowCounts[i] == 3 || rowCounts[i] == -3)
			{
				return rowCounts[i] / 3;
			}
		}

		return 0;
	}

	void print()
	{
		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				int pos = j * 3 + i;

				if (spaces[pos] == 1)
				{
					cout << "x";
					continue;
				}

				if (spaces[pos] == -1)
				{
					cout << "o";
					continue;
				}

				cout << ".";
			}
			cout << endl;
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
	int spaces[9];
};