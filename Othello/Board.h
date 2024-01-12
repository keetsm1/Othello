#pragma once
#include <iostream>
#include "Game.h"

class Board {
public:
	Board() {};
	void drawboard();
	char othelloboard[8][8];

	void startOne();
	void startTwo();
	void startThree();
	void startFour();
	void setUnplayable();

	void replaceElement(int row, int col, char symbol);

	void takeTurn(Player& current, Player& second);
	bool isBoardFull();

	void DetermineWinner(Board&,Player&,Player&);

	void saveBoard();

	void load();
};