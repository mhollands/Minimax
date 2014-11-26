#include <vector>
#include <iostream>
#include "Board.h"

using namespace std;

class Othello_Board : public Board_Base
{
private:
	__int8 spaces[8][8];

	bool applyMove(int space, bool player)
	{
		int spaceX = space % 8;
		int spaceY = space / 8;
		if (spaces[spaceX][spaceY] != 0)
		{
			return false;
		}

		spaces[spaceX][spaceY] = player ? 1 : -1;

		bool validMove = false;

		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if (i == 0 && j == 0)
				{
					continue;
				}			

				int v = 0;
				int checkSpaceX = spaceX;
				int checkSpaceY = spaceY;
				bool started = false;
				bool lineOfAttack = false;
				for (v = 1; ((checkSpaceX = spaceX + v*i) < 8) & ((checkSpaceY = spaceY + v*j) < 8)
						&& checkSpaceX >= 0 && checkSpaceY >= 0; v++)
				{
					bool quitVector = false;
					switch(spaces[checkSpaceX][checkSpaceY])
					{
					case 0:
						quitVector = true;
						break;

					case 1:
						if (player)
						{
							if (started)
							{
								validMove = true;
								lineOfAttack = true;
							}
							quitVector = true;
							break;
						}

						started = true;
						break;

					case -1:
						if (!player)
						{
							if (started)
							{
								lineOfAttack = true;
								validMove = true;
							}
							quitVector = true;
							break;
						}

						started = true;
						break;
					}

					if (quitVector)
					{
						break;
					}
				}

				
				if (lineOfAttack)
				{
					bool ended = false;
					while(checkSpaceX != spaceX || checkSpaceY != spaceY)
					{
						spaces[checkSpaceX][checkSpaceY] = (player ? 1 : -1);
						checkSpaceX -= i;
						checkSpaceY -= j;
					}
				}
				

			}
		}

		return validMove;
	}

	Othello_Board* privateClone()
	{
		int newSpaces[8][8];

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				newSpaces[i][j] = spaces[i][j];
			}
		}
	
		return new Othello_Board(newSpaces);
	}

public:
	~Othello_Board()
	{
		
	}

	Othello_Board()
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if ((i == 3 || i == 4))
				{
					if (i == j)
					{
						spaces[i][j] = 1;
						continue;
					}

					if (i == 7 - j)
					{
						spaces[i][j] = -1;
						continue;
					}
				}

				spaces[i][j] = 0;
			}
		}
		
	}

	Othello_Board(int newSpaces[8][8])
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				spaces[i][j] = newSpaces[i][j];
			}
		}
			
	}

	bool isLastBoard()
	{
		int plus = 0;
		int minus = 0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (spaces[i][j] == 0)
				{
					continue;
				}

				if (spaces[i][j] == 1)
				{
					plus++;
					continue;
				}

				minus++;
			}
		}

		if (plus == 0 || minus == 0 || minus + plus == 64)
		{
			return true;
		}

		return false;
	}

	vector<Board_Base*> listPossibleMoves(bool player)
	{
		vector<Board_Base*> newMoves;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (spaces[i][j] == 0)
				{
					Othello_Board* newMove = privateClone();

					if (newMove->applyMove(i + j * 8, player))
					{
						newMoves.push_back(newMove);
						continue;
					}

					delete newMove;
				}
			}
		}

		return newMoves;
	}

	void print()
	{
		for (int j = 0; j < 8; j++)
		{
			for (int i = 0; i < 8; i++)
			{
				switch (spaces[i][j])
				{
				case 0:
					cout << ".";
					break;
				case 1:
					cout << "o";
					break;
				case -1:
					cout << "x";
					break;
				}
			}
			cout << (j*8 + 7) << endl;
		}
	}

	int calculateHeuristic()
	{
		int score = 0;
		for (int j = 0; j < 8; j++)
		{
			for (int i = 0; i < 8; i++)
			{
				score += spaces[i][j];
			}
		}

		return score;
	}

	Board_Base* clone()
	{
		return privateClone();
	}

	void setPiece(long data)
	{
		if (data > 1000)
		{
			data -= 1000;
			applyMove(data, false);
			return;
		}

		applyMove(data, true);
		return;
	}
};