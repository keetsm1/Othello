#include "Board.h"
#include <fstream>
#include <iostream>

Game::Game(Player p1, Player p2)
{
	first = p1;
	second = p2;
}

void Game::savePlayers( std::string filename, Player& first, Player& second) {
    std::ofstream saveFile(filename);

    if (saveFile.is_open()) {
        saveFile << first.getName() << std::endl;
        saveFile << second.getName() << std::endl;
        saveFile << std::endl;
        std::cout << "Names saved successfully." << std::endl;
    }

    saveFile.close();
}

