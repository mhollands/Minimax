#include "Board.h"
#include <iostream>
#include <vector>
using namespace std;

vector<Board_Base*> Board_Base::listPossibleMoves(bool player)
{
	return vector<Board_Base*>();
}

void Board_Base::print()
{
	cout << "Basic Board" << endl;
}

int Board_Base::calculateHeuristic()
{
	return 0;
}

Board_Base* Board_Base::clone()
{
	return nullptr;
}

void Board_Base::setPiece(long data)
{
		
}

bool Board_Base::isLastBoard()
{
	return false;
}

Board_Base::~Board_Base()
{

}
