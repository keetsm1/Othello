#include <iostream>
#include "Game.h"
#include "Board.h"
#include "Position.h"
#include "UnplayablePosition.h"

int main() 
{
	int option;
	std::cout << "Welcome to the Othello game!" << "Selection an option: " << std::endl;
	std::cout << "1. Quit" << std::endl << "2. Load a game" << std::endl << "3. Start new game" << std::endl;
	std::cout << "Enter the option: ";
	std::cin >> option;
	Game g;
	Board b;
	if (option == 1){
		exit(0);
	}
	else if (option == 2)
	{
		b.load();
		std::string player1;
		std::string player2;
		std::cout << "Please enter your names:" << std::endl << "Player 1 enter your name: ";
		std::cin >> player1;
		std::cout << "Player 2: ";
		std::cin >> player2;
		Player playerOne(player1, 'B');
		Player playerTwo(player2, 'W');
		while (true) {
			b.drawboard();
			b.takeTurn(playerOne, playerTwo);

			if (b.isBoardFull()) {
				Game game(playerOne, playerTwo);
				b.DetermineWinner(b, playerOne, playerTwo);
				g.savePlayers("savefile.txt", playerOne, playerTwo);
				b.saveBoard();
				exit(0);
			}
		}
	}
	else if (option == 3)
	{
		std::string player1;
		std::string player2;
		std::cout << "Please enter your names:" << std::endl << "Player 1 enter your name: ";
		std::cin >> player1;
		std::cout << "Player 2: ";
		std::cin >> player2;
		Player playerOne(player1, 'B');
		Player playerTwo(player2, 'W');
		int start;
		std::cout << "Please enter a starting position(1-4): ";
		std::cin >> start;
		system("cls");

			switch (start)
			{
			case 1:
				b.setUnplayable();
				b.startOne();
			
				break;
			case 2:
				b.setUnplayable();
				b.startTwo();
				
				break;
			case 3:
				b.setUnplayable();
				b.startThree();
			
				break;
			case 4:
				b.setUnplayable();
				b.startFour();
				break;
			default:
				std::cout << "Invalid input. Input again: " << std::endl;
				std::cin >> start;
			}
			while (true) {
				b.drawboard();
				b.takeTurn(playerOne, playerTwo);

				if (b.isBoardFull()) {
					Game game(playerOne, playerTwo);
					b.DetermineWinner(b, playerOne, playerTwo);
					g.savePlayers("savefile.txt", playerOne, playerTwo);
					b.saveBoard();
					exit(0);
				}
			}
		
	}
	else {
		std::cout << "Invalid option. Enter again." << std::endl;
		std::cout << "Enter the option: ";
		std::cin >> option;
	}
	
}