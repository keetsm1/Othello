#include "Player.h"

Player::Player(std::string& pname, char pSymbol)
{
	name = pname;
	symbol = pSymbol;
}

std::string Player::getName()
{
	return name;
}

char Player::getChar()
{
	return symbol;
}
