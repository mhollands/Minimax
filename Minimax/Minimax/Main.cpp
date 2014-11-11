#include <iostream>
#include "NnC_Board.cpp"

using namespace std;

int main()
{

	NnCBoard board = NnCBoard(1, 0);
	cout << board.calculateHeuristic() << endl;
	board.print();
	cout << endl;
	MinimaxEngine engine = MinimaxEngine(&board);
	Board_Base* newMove = engine.getSuggestedMove(true);
	newMove->print();


	int blah;
	cin >> blah;
};