#include <iostream>
#include "NnC_Board.cpp"

using namespace std;

int main()
{
	Board_Base board = NnCBoard();
	MinimaxEngine engine(&board);

	Board_Base newMove = engine.getSuggestedMove(true);

	int a;
	cin >> a;
}	