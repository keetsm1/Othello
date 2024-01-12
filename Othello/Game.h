#pragma once
#include <iostream>
#include "Player.h"

class Game {
private:
	Player first;
	Player current;
	Player second;
public:
	Game(Player p1, Player p2);
	Game() { };
	void savePlayers(std::string, Player&, Player&);

	
	
};