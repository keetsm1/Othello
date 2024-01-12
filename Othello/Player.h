#pragma once
#include <iostream>
class Player {
private:
	std::string name;
	char symbol;
public:
	Player() {};
	Player(std::string& pname, char pSymbol);

	std::string getName();
	char getChar();
};