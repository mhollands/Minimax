#ifndef _board_included
#define _board_included
#include <vector>

class Board_Base
{
public:
	virtual std::vector<Board_Base*> listPossibleMoves(bool player);

	virtual void print();

	virtual int calculateHeuristic();

	virtual Board_Base* clone();

	virtual void setPiece(long data);

	virtual bool isLastBoard();

	virtual ~Board_Base();
};

#endif