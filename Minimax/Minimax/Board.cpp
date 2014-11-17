#include <iostream>
#include <vector>

using namespace std;

class Board_Base
{
public:
	virtual vector<Board_Base*> listPossibleMoves(bool player)
	{
		return vector<Board_Base*>();
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

	virtual void setPiece(long data)
	{
		
	}

	virtual bool isLastBoard()
	{
		return false;
	}

	virtual ~Board_Base()
	{

	}
};