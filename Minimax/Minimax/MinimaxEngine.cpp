#include "MinimaxEngine.h"
#include <iostream>
#include <vector>
#include "Board.h"

using namespace std;

MinimaxEngine::MinimaxEngine(Board_Base* initialBoard)
{
	board = initialBoard;
}

Board_Base* MinimaxEngine::getSuggestedMove(int depth, bool alphaBetaPruning)
{
	moveCount = 0;
	pathCount = 0;
	vector<Board_Base*> possibleMoves = board->listPossibleMoves(true);

	int maxValue = INT_MIN;
	Board_Base* suggestedMove = board->clone();

	for (int i = 0; i < possibleMoves.size(); i++)
	{
		moveCount++;
		int childValue = 0;

		if (alphaBetaPruning)
		{
			childValue = getBoardValueAB(possibleMoves[i], depth, false, INT_MIN, INT_MAX);
		}
		else
		{
			childValue = getBoardValue(possibleMoves[i], depth, false);
		}

		if (childValue > maxValue)
		{
			delete suggestedMove;
			suggestedMove = possibleMoves[i];
			maxValue = childValue;
			continue;
		}

		delete possibleMoves[i];
	}

	cout << "Visited " << moveCount << " moves." << endl;
	cout << "Visited " << pathCount << " paths." << endl;
	return suggestedMove;
}

bool MinimaxEngine::applyMove(Board_Base* newMove)
{
	//need to check legal here here
	board = newMove;
	return false;
}

int MinimaxEngine::getBoardValueAB(Board_Base* board, int depth, bool player, int a, int b)
{
	moveCount++;
	vector<Board_Base*> childMoves = board->listPossibleMoves(player);
		
	if (depth == 0 || childMoves.size() == 0)
	{
		for (int i = 0; i < childMoves.size(); i++)
		{
			moveCount++;
			delete childMoves[i];
		}

		pathCount++;
		return board->calculateHeuristic();
	}

	bool assigned = false;
	int value = 0;
	for (int i = 0; i < childMoves.size(); i++)
	{
		int childValue = getBoardValueAB(childMoves[i], depth - 1, !player, a, b);
		delete childMoves[i];

		if (player && (childValue > a || !assigned))
		{
			a = childValue;
			assigned = true;
		}
			
		if (!player && (childValue < b || !assigned))
		{
			b = childValue;
			assigned = true;
		}

		if (b <= a)
		{
			for (int j = i + 1; j < childMoves.size(); j++)
			{
				delete childMoves[j];
			}
			break;
		}
	}

	if (player)
	{
		return a;
	}

	return b;
}

int MinimaxEngine::getBoardValue(Board_Base* board, int depth, bool player)
{
	moveCount++;
	vector<Board_Base*> childMoves = board->listPossibleMoves(player);

	if (depth == 0 || childMoves.size() == 0)
	{
		for (int i = 0; i < childMoves.size(); i++)
		{
			delete childMoves[i];
		}

		pathCount++;
		return board->calculateHeuristic();
	}

	bool assigned = false;
	int value = 0;
	for (int i = 0; i < childMoves.size(); i++)
	{
		int childValue = getBoardValue(childMoves[i], depth - 1, !player);
		delete childMoves[i];

		if ((player &&  childValue > value) || !assigned)
		{
			value = childValue;
			assigned = true;
			continue;
		}

		if (!player && childValue < value)
		{
			value = childValue;
		}
	}

	return value;
}