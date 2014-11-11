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

	virtual vector<Board_Base> listPossibleMoves(bool player)
	{
		return *new vector<Board_Base>();
	}

	virtual bool moveIsLegal(Board_Base newMove)
	{
		return false;
	}

	virtual int calculateHeuristic()
	{
		return 0;
	}
};