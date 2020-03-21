//
//  gameState.cpp
//  TicTacTo
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Copyright © 2019 Tarek Abdelrahman. All rights reserved.

#include "tictactoe.h"
#include "gameState.h"
#include "displayServer.h"

//Accessor and Mutator Functions to get the coordinates of played position
int gameState::get_clickedRow(){
    return clickedRow;
}

void gameState::set_clickedRow(int value){
    if(value <= 2 && value>=0){
        clickedRow=value;
    }
}

int gameState::get_clickedColumn(){
    return clickedColumn;
}

void gameState::set_clickedColumn(int value){
    if(value <= 2 && value>=0){
        clickedColumn=value;
    }
}


//Accessor and Mutator functions to check if game is over
bool gameState::get_gameOver(){
    return gameOver;
}

void gameState::set_gameOver(bool value){
        gameOver=value;
}


//Accessor and Mutator functions to check the validity of played move
bool gameState::get_moveValid(){
    return moveValid;
}

void gameState::set_moveValid(bool value){
        moveValid=value;
}


//Accessor and mutator function to set the win code for appropriate display
int gameState::get_winCode(){
    return winCode;
}

void gameState::set_winCode(int value){
    if(value <= 8 && value >= 0){
        winCode=value;
    }
}


//Accessor and mutator functions to check who is the current player
bool gameState::get_turn(){
    return turn;
}

void gameState::set_turn(bool value){
       turn=value;
}


//Accessor and Mutator function for values at a particular position of game board
int gameState::get_gameBoard(int row, int col){
    return gameBoard[row][col];
}

void gameState::set_gameBoard(int row, int col, int value){
    if(row <= 2 && row >= 0 && col <= 2 && col >= 0){
        gameBoard[row][col]=value;
    }
}




