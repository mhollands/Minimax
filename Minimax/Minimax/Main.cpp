#include <iostream>
//#include "NnC_Board.cpp"
#include "Othello_Board.cpp"

int main()
{
	
	Board_Base* b = new Othello_Board();
	b->print();

	for (int i = 0; i < 10; i++)
	{
		MinimaxEngine engine = MinimaxEngine(b);
		Board_Base* newMove = engine.getSuggestedMove(0, true);

		delete b;
		b = newMove;
		b->print();
		std::cout << endl;

		int newPos;
		cin >> newPos;

		b->setPiece(newPos + 1000);
		b->print();
		std::cout << endl;
	}

	std::cout << "Game Over" << endl;
	delete b;

	int a;
	cin >> a;
	
	/*
	int spaces[9] = { 1, 1, -1, -1, -1, 1, 1, 0, 0 };
	Board_Base* board = new NnCBoard();
	board->print();
	std::cout << endl;

	for (int i = 0; i < 10; i++)
	{
		MinimaxEngine engine = MinimaxEngine(board);
		Board_Base* newMove = engine.getSuggestedMove(9, true);

		if (newMove == board)
		{
			break;
		}
		
		delete board;
		board = newMove;
		board->print();
		std::cout << endl;

		if (board->calculateHeuristic() != 0 || board->countPossibleMoves(false) == 0)
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
	*/
};