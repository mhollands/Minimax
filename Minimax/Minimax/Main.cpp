#include <iostream>
#include "NnC_Board.cpp"

using namespace std;

int main()
{
	NnCBoard* board = new NnCBoard(0, 0);
	board->print();
	cout << endl;

	MinimaxEngine engine = MinimaxEngine(board);
	Board_Base* newMove = engine.getSuggestedMove(true);
	newMove->print();


	for (int i = 0; i <0; i++)
	{
		int newPos;
		cin >> newPos;
	}

	int blah;
	cin >> blah;
};