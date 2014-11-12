#include <iostream>
#include <vector>

using namespace std;

class Board_Base
{
public:
	virtual int countPossibleMoves(bool player)
	{
		return 0;
	}

	virtual vector<Board_Base*> listPossibleMoves(bool player)
	{
		return vector<Board_Base*>();
	}

	virtual bool moveIsLegal(Board_Base newMove)
	{
		return false;
	}

	virtual void print()
	{
		cout << "Basic Board" << endl;
	}

	virtual int calculateHeuristic()
	{
		return 0;
	}

	virtual Board_Base* clone()
	{
		return nullptr;
	}

	int getValue(int depth, bool player)
	{
		vector<Board_Base*> childMoves = listPossibleMoves(player);

		if (depth == 0 || childMoves.size() == 0)
		{
			return calculateHeuristic();
		}
		
		bool assigned = false;
		int value = 0;
		for (int i = 0; i < childMoves.size(); i++)
		{
			int childValue = childMoves[i]->getValue(depth - 1, !player);
			delete childMoves[i];

			if ((player &&  childValue > value) || !assigned)
			{
				value = childValue;
				assigned = true;
				continue;
			}

			if (!player && childValue < value)
			{
				value = childValue;
			}
		}

		return value;
	}
};