#include <iostream>
#include "NnC_Board.cpp"

int main()
{
	Board_Base* board = new NnCBoard(0, 0);
	board->print();
	std::cout << endl;

	for (int i = 0; i < 10; i++)
	{
		MinimaxEngine engine = MinimaxEngine(board);
		Board_Base* newMove = engine.getSuggestedMove(9);

		if (newMove == board)
		{
			break;
		}
		
		delete board;
		board = newMove;
		board->print();
		std::cout << endl;

		if (board->calculateHeuristic() != 0)
		{
			break;
		}

		int newPos;
		cin >> newPos;

		board->setPiece(newPos + 1000);
		board->print();
		std::cout << endl;
	}

	std::cout << "Game Over" << endl;
	delete board;

	int blah;
	cin >> blah;
};