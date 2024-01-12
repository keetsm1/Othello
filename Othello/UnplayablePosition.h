#pragma once
#include <iostream>
#include "Position.h"

class UnplayablePosition : public Position 
{
public:
	UnplayablePosition() {};
	bool flipChar(Board& board, int row, int col, int deltaRow, int deltaCol, char symbol);
	virtual bool canPlay(Board&, int, int, char) override;
	
	
};
