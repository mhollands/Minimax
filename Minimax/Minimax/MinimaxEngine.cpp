#include "Board.cpp"

class MinimaxEngine
{
public:
	long moveCount = 0;
	long pathCount = 0;
	MinimaxEngine(Board_Base* initialBoard)
	{
		board = initialBoard;
	}

	Board_Base* getSuggestedMove(int depth)
	{
		moveCount = 0;
		pathCount = 0;
		vector<Board_Base*> possibleMoves = board->listPossibleMoves(true);

		int maxValue = INT_MIN;
		bool assigned = false;
		Board_Base* suggestedMove = board;

		for (int i = 0; i < possibleMoves.size(); i++)
		{
			int childValue = getBoardValue(possibleMoves[i], depth, false);

			if (childValue > maxValue || !assigned)
			{
				if (assigned)
				{
					delete suggestedMove;
				}

				assigned = true;
				suggestedMove = possibleMoves[i];
				maxValue = childValue;
				continue;
			}

			delete possibleMoves[i];
		}

		cout << "Visited " << moveCount << " moves." << endl;
		cout << "Visited " << pathCount << " paths." << endl;
		return suggestedMove;
	}

	bool applyMove(Board_Base* newMove)
	{
		//need to check legal here here
		board = newMove;
	}

	int getBoardValue(Board_Base* board, int depth, bool player)
	{
		moveCount++;
		vector<Board_Base*> childMoves = board->listPossibleMoves(player);

		if (depth == 0 || childMoves.size() == 0)
		{
			pathCount++;
			return board->calculateHeuristic();
		}

		bool assigned = false;
		int value = 0;
		for (int i = 0; i < childMoves.size(); i++)
		{
			int childValue = getBoardValue(childMoves[i], depth - 1, !player);
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

private:
	Board_Base* board;
};