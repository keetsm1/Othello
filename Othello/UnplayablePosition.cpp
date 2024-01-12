#include "UnplayablePosition.h"
#include <iostream>

bool UnplayablePosition::canPlay(Board& board, int row, int col, char piece) {
	if (board.othelloboard[row][col] == 'X' || board.othelloboard[row][col] == 'B' || board.othelloboard[row][col] == 'W')
	{
		std::cout << "Already a value there." << std::endl;
		return false;
	}
	char opponentPiece;
	if (piece == 'B') {
		opponentPiece = 'W';
	}
	else {
		opponentPiece = 'B';
	}
	//to Check left
	int left = col - 1;



	while (left >= 0 && board.othelloboard[row][left] == opponentPiece)
	{
		left--;
	}
	if (left >= 0 && left < col - 1 && board.othelloboard[row][left] == piece)
	{
		for (int i = col - 1; i > left; --i)
		{
			board.othelloboard[row][i] = piece;
		}
		return true;
	}


	//check right
	int right = col + 1;
	while (right < 8 && board.othelloboard[row][right] == opponentPiece)
	{
		right++;
	}
	if (right < 8 && board.othelloboard[row][right] == piece)
	{
		for (int i = col + 1; i < right; ++i)
		{
			board.othelloboard[row][i] = piece;
		}
		return true;
	}

	//ccheck top
	int top = row - 1;
	while (top >= 0 && board.othelloboard[top][col] == opponentPiece)
	{
		top--;
	}
	if (top >= 0 && top < row - 1 && board.othelloboard[top][col] == piece)
	{
		for (int i = row - 1; i > top; --i)
		{
			board.othelloboard[i][col] = piece;
		}
		return true;
	}

	//check bottom
	int bottom = row + 1;
	while (bottom < 8 && board.othelloboard[bottom][col] == opponentPiece)
	{
		bottom++;
	}
	if (bottom < 8 && bottom > row + 1 && board.othelloboard[bottom][col] == piece)
	{
		for (int i = row + 1; i < bottom; ++i)
		{
			board.othelloboard[i][col] = piece;
		}
		return true;
	}

    //checking diagonals
    if (flipChar(board, row, col, -1, -1, piece) ||
        flipChar(board, row, col, -1, 1, piece) ||  
        flipChar(board, row, col, 1, -1, piece) ||  
        flipChar(board, row, col, 1, 1, piece)) {    
        return true;
    }

    return false;
}

bool UnplayablePosition::flipChar(Board& board, int row, int col, int row2, int col2, char piece) {
	int newRow = row + row2;
	int newCol = col +col2;

	char opponentPiece;
	if (piece == 'B') {
		opponentPiece = 'W';
	}
	else {
		opponentPiece = 'B';
	}

	if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8 && board.othelloboard[newRow][newCol] == opponentPiece) {
		while (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8 && board.othelloboard[newRow][newCol] == opponentPiece) {
			newRow =newRow +row2;
			newCol = newCol+ col2;
		}

		if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8 && board.othelloboard[newRow][newCol] == piece) {

			while (row != newRow || col != newCol) {
				row = row+row2;
				col = col+col2;
				board.othelloboard[row][col] =piece;
			}
			return true;
		}
	}

	return false;
}