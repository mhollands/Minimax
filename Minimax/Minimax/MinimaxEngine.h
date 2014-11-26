#include "Board.h"

class MinimaxEngine
{
public:
	long moveCount;
	long pathCount;
	MinimaxEngine(Board_Base* initialBoard);

	Board_Base* getSuggestedMove(int depth, bool alphaBetaPruning);

	bool applyMove(Board_Base* newMove);

	int getBoardValueAB(Board_Base* board, int depth, bool player, int a, int b);

	int getBoardValue(Board_Base* board, int depth, bool player);

private:
	Board_Base* board;
};

