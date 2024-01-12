#pragma once
#include "Board.h"
class Position{
private:
	Board board;
public:
	virtual bool canPlay(Board&, int, int, char) = 0;

	bool isValidMove(int,int,char);
	
	
};