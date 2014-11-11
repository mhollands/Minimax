#include "Board.cpp"

class MinimaxEngine
{
public:
	MinimaxEngine(Board_Base* initialBoard)
	{
		board = initialBoard;
	}

	Board_Base getSuggestedMove(bool player)
	{
		vector<Board_Base> possibleMoves = board->listPossibleMoves(player);
		vector<boardValueWrapper> possibleWrappedMoves;

		for (int i = 0; i < possibleMoves.size(); i++)
		{
			boardValueWrapper wrappedMove = boardValueWrapper(possibleMoves[i]);
			possibleWrappedMoves.push_back(wrappedMove);
		}

		return *board;
	}

	bool applyMove(Board_Base newMove)
	{
		return false;
	}

private:
	Board_Base* board;

	class boardValueWrapper
	{
	public:
		Board_Base* board;

		boardValueWrapper(Board_Base b)
		{
			board = &b;
		}

		int getValue()
		{
			return board->calculateHeuristic();
		}
	};
};