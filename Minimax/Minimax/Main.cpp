#include <iostream>
//#include "NnC_Board.cpp"
#include "Othello_Board.cpp"

int main()
{
	Board_Base* b = new Othello_Board();
	b->print();
	
	while (!b->isLastBoard())
	{
		MinimaxEngine engine = MinimaxEngine(b);
		Board_Base* newMove = engine.getSuggestedMove(6, true);

		delete b;
		b = newMove;
		b->print();
		std::cout << endl;

		if (b->isLastBoard())
		{
			break;
		}

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
};