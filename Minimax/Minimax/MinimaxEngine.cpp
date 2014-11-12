#include "Board.cpp"

class MinimaxEngine
{
public:
	MinimaxEngine(Board_Base* initialBoard)
	{
		board = initialBoard;
	}

	Board_Base* getSuggestedMove(int depth)
	{
		vector<Board_Base*> possibleMoves = board->listPossibleMoves(true);

		int maxValue = INT_MIN;
		bool assigned = false;
		Board_Base* suggestedMove = board;

		for (int i = 0; i < possibleMoves.size(); i++)
		{
			int childValue = possibleMoves[i]->getValue(depth, false);

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

		return suggestedMove;
	}

	bool applyMove(Board_Base* newMove)
	{
		//need to check legal here here
		board = newMove;
	}

private:
	Board_Base* board;
};