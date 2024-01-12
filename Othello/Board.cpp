#include "Board.h"
#include "Position.h"
#include "UnplayablePosition.h"
#include <iostream>
#include <fstream>

void Board::drawboard()
{

    char topLabels[] = { ' ' ,'0', '1', '2', '3', '4', '5', '6', '7' };

    for (int i = 0; i < 9; ++i)
    {
        std::cout << topLabels[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 8; ++i)
    {
        std::cout << i << " ";

        for (int j = 0; j < 8; ++j)
        {
            if (othelloboard[i][j] == 'B' || othelloboard[i][j] == 'W')
            {
                std::cout << othelloboard[i][j] << " ";
            }
            else if (othelloboard[i][j] == 'X')
            {
std::cout << othelloboard[i][j] << " ";
            }
            else
            {
                std::cout << "* ";
            }
        }
        std::cout << std::endl;
    }
}

void Board::startOne()
{
    othelloboard[2][2] = 'W';
    othelloboard[3][2] = 'B';
    othelloboard[2][3] = 'B';
    othelloboard[3][3] = 'W';
}

void Board::startTwo()
{
    othelloboard[2][4] = 'W';
    othelloboard[2][5] = 'B';
    othelloboard[3][4] = 'B';
    othelloboard[3][5] = 'W';
}

void Board::startThree()
{
    othelloboard[4][2] = 'W';
    othelloboard[4][3] = 'B';
    othelloboard[5][2] = 'B';
    othelloboard[5][3] = 'W';
}

void Board::startFour()
{
    othelloboard[4][4] = 'W';
    othelloboard[5][4] = 'B';
    othelloboard[4][5] = 'B';
    othelloboard[5][5] = 'W';
}

void Board::setUnplayable()
{
    othelloboard[0][0] = 'X';
    othelloboard[7][0] = 'X';
    othelloboard[0][7] = 'X';
    othelloboard[7][7] = 'X';
}

void Board::replaceElement(int row, int col, char symbol)
{
    if (row >= 0 && row < 8 && col >= 0 && col < 8)
    {
        othelloboard[row][col] = symbol;
    }
}

void Board::takeTurn(Player& current, Player& second)
{
    UnplayablePosition* u = new UnplayablePosition();
    int row, col;
    char symbol = current.getChar();
    int input;
    std::cout << "If you would like to concede, make a move or save. Choose an option below:" << std::endl;
    std::cout << "1. Concede" << std::endl << "2. Make a Move" << std::endl << "3. Save" << std::endl;
    std::cin >> input;

    if (input ==1) {
        std::cout << current.getName() <<" conceded the game." << second.getName() << " wins!";
        Player first= current;
        current = second;
        second = first;
        exit(0);
    }
    else if (input == 2)
    {
        std::cout << "Player: " << current.getName() << std::endl << "Enter a row number: ";
        std::cin >> row;

        std::cout << "Enter column number: ";
        std::cin >> col;
        std::cout << std::endl;

        if (!u->canPlay(*this, row, col, symbol)) {
            std::cout << "Invalid move. Please choose a different position." << std::endl;
            delete u;
            return;
        }
        if (row >= 0 && row < 8 && col >= 0 && col < 8)
        {
            replaceElement(row, col, symbol);

        }
        else
        {
            std::cout << "Invalid input. Please enter valid row and column numbers: " << std::endl;
            std::cout << "Player " << current.getName() << "Enter a row number: ";
            std::cin >> row;

            std::cout << "Player " << current.getName() << "Enter a column number:";
            std::cin >> col;
            std::cout << std::endl;
        }
    }
    else if (input == 3) 
    {
        Game g;
        g.savePlayers("savefile.txt", current, second);
        saveBoard();
        
       
        exit(0);
       
    }
    else {
        std::cout << "Invalid Input";
    }
    
    Player first = current;
    current = second;
    second = first;
  
}

bool Board::isBoardFull()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j) 
        {
            if (othelloboard[i][j] = '*') {
                return false;
            }
        }
    }
    return true;
}

void Board::DetermineWinner(Board& board, Player& current, Player &second)
{
    int countB = 0;
    int countW = 0;

    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col) {
            char piece = board.othelloboard[row][col];

            if (piece == current.getChar()) {
                countB++;
            }
            else if (piece == second.getChar())
            {
                countW++;
            }
        }
    }

    if (countB > countW)
    {
        std::cout << current.getName() << "is the winner!" << std::endl;
    }
    else if (countB < countW)
    {
        std::cout << second.getName() << "is the winner!" << std::endl;
    }
    else {
        std::cout << "It's a tie!";
    }
}

void Board::saveBoard()
{
    std::ofstream saveFile("savefile.txt", std::ios::app); // ios::app makes it that in the takeTurn() function it will print both the board and the names

    if (saveFile.is_open()) {
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                if (othelloboard[i][j] == 'B' || othelloboard[i][j] == 'W' || othelloboard[i][j] == 'X')
                    saveFile << othelloboard[i][j] << " ";
                else
                    saveFile << "* ";
            }
            saveFile << std::endl;
        }
        std::cout << "Board saved";
    }

    saveFile.close();
}

void Board::load()
{
    std::string filename;
    std::cout << "Enter a filename: ";
    std::cin >> filename;

    std::ifstream File(filename);

    if (File.is_open() )
    {
        std::string playername1, playername2;
        File >> playername1 >> playername2;
    }

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            File >> othelloboard[i][j];
        }
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            std::cout << othelloboard[i][j]<< " ";
        }
        std::cout << std::endl;
    }

    File.close();
}





