#include "Board.h"
#include <stdio.h>

	Board::Board(){
		table = new int* [10];
		for (int i = 0; i < 10; i++){
			table[i] = new int[10];
			for (int j = 0; j < 10; j++)
				table[i][j] = 0;
		}
	}
	Board::~Board(){
		for (int i = 0; i < 10; i++)
			delete table[i];
		delete table;
	}

	char Board::getChar(int sign){
		if (sign == X)
			return 'X';
		if (sign == dot)
			return '.';
		if (sign == O)
			return 'O';
		return '-';
	}

	char Board::getCell(int x, int y){
		if (table[x][y] == X)
			return 'X';
		if (table[x][y] == dot)
			return '.';
		return 'O';
	}

    void Board::move(int x, int y, int sign){
    	table[x][y] = sign;
    }; 
    bool Board::canMove(int x, int y, char sign) {
    	if ((x >= 0 && x < 10) && 
    		(y >= 0 && y < 10) && 
    		(sign == 'O' || sign == 'X') && 
    		(getCell(x, y) == '.'))
    		return true;
    	return false;
    }

    Board::state Board::isWin(){
    	int sum = 0;
    	for (int i = 0; i < 10; i++){
    		for (int j = 0; j < 10; j++){
    			if (table[i][j] == dot || (sum < 0 && table[i][j] == X) || (sum > 0 && table[i][j] == O))
    				sum = 0;
    			else
    				sum += table[i][j];
    			if (sum == 4) return x_wins;
    			if (sum == -4) return y_wins;
    		}
    		sum = 0;
    	}
    	for (int j = 0; j < 10; j++){
    		for (int i = 0; i < 10; i++){
    			if (table[i][j] == dot || (sum < 0 && table[i][j] == X) || (sum > 0 && table[i][j] == O))
    				sum = 0;
    			else
    				sum += table[i][j];
    			if (sum == 5) return x_wins;
    			if (sum == -5) return y_wins;
    		}
    		sum = 0;
    	}
    	for (int i = 0; i < 10; i++)
    		for (int j = 0; j < 10; j++)
    			if (table[i][j] == dot)
    				return GAME_IN_PROCESS;
    	return draw;
    }; 