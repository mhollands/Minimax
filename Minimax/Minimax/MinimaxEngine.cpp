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

		int maxValue = 0;
		Board_Base* suggestedMove = board;

		for (int i = 0; i < possibleMoves.size(); i++)
		{
			int childValue = possibleMoves[i]->getValue(depth, true);

			if (childValue > maxValue)
			{
				suggestedMove = possibleMoves[i];
				maxValue = childValue;
			}
		}

		return suggestedMove;
	}

	bool applyMove(Board_Base newMove)
	{
		return false;
	}

private:
	Board_Base* board;
};