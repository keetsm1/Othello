#include "Position.h"
#pragma once

bool Position::isValidMove(int row,int col, char symbol)
{
	if (row < 0 || row >= 8 || col < 0 || col >= 8) 
	{
		return false;
	}
	if (board.othelloboard[row][col] != '*') 
	{
		return false;
	}
    return true;
}





