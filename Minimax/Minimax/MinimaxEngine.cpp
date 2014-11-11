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
			boardValueWrapper wrappedMove = boardValueWrapper(possibleMoves[i], 0);
			constructMoveTree(&wrappedMove, player);
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

	struct boardValueWrapper
	{
	public:
		int value = 0;
		Board_Base* board;

		boardValueWrapper(Board_Base b, int v)
		{
			value = v;
			board = &b;
		}
	};

	void constructMoveTree(boardValueWrapper* wrappedMove, bool player)
	{
		vector<Board_Base> possibleMoves = wrappedMove->board->listPossibleMoves(player);
		wrappedMove->value = 1;
	}
};