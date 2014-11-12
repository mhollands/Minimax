#include <iostream>
#include "NnC_Board.cpp"

using namespace std;

int main()
{
	Board_Base* board = new NnCBoard(0, 0);
	board->print();
	cout << endl;


	for (int i = 0; i <5; i++)
	{
		MinimaxEngine engine = MinimaxEngine(board);
		Board_Base* newMove = engine.getSuggestedMove(true);
		delete board;
		board = newMove;
		board->print();

		if (board->calculateHeuristic() != 0)
		{
			cout << "Game Over" << endl;
			break;
		}

		int newPos;
		cin >> newPos;

		board->setPiece(newPos + 1000);
		board->print();
	}

	delete board;

	int blah;
	cin >> blah;
};