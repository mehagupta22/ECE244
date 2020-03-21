//+
//  playMove.cpp
//  TicTacTo
//
//  Updated by Tarek Abdelrahman on 2019-06-07.
//  Created by Tarek Abdelrahman on 2018-05-15.
//  Copyright © 2018-2019 Tarek Abdelrahman. All rights reserved.
//

#include "tictactoe.h"
#include "gameState.h"
#include "displayServer.h"

void playMove(gameState& game_state) {
    
    //Getting coordinates of played position
    int row_played=game_state.get_clickedRow(); 
    int col_played=game_state.get_clickedColumn();
    
    //Checking if played position is valid (unoccupied)
    int valueAtPosition=game_state.get_gameBoard(row_played, col_played);
        
    //If position played is valid (unoccupied)
    if (valueAtPosition==Empty){
        game_state.set_moveValid(true);
        
        if((game_state.get_turn())==true){
            game_state.set_gameBoard(row_played, col_played, X);
            game_state.set_turn(false);
        }
        else{
            game_state.set_gameBoard(row_played, col_played, O);
            game_state.set_turn(true);
        }
   
        //Setting winCode after last click
        if((game_state.get_gameBoard(0,0))==(game_state.get_gameBoard(0,1)) && (game_state.get_gameBoard(0,0))==(game_state.get_gameBoard(0,2)) && (game_state.get_gameBoard(0,0))!=Empty){
            game_state.set_winCode(1);
        }
        
        else if((game_state.get_gameBoard(1,0))==(game_state.get_gameBoard(1,1)) && (game_state.get_gameBoard(1,0))==(game_state.get_gameBoard(1,2)) && (game_state.get_gameBoard(1,0))!=Empty){
            game_state.set_winCode(2);
        }
        
        else if((game_state.get_gameBoard(2,0))==(game_state.get_gameBoard(2,1)) && (game_state.get_gameBoard(2,0))==(game_state.get_gameBoard(2,2)) && (game_state.get_gameBoard(2,0))!=Empty){
            game_state.set_winCode(3);
        }
        
        else if((game_state.get_gameBoard(0,0))==(game_state.get_gameBoard(1,0)) && (game_state.get_gameBoard(0,0))==(game_state.get_gameBoard(2,0)) && (game_state.get_gameBoard(0,0))!=Empty){
            game_state.set_winCode(4);
        }
        
        else if((game_state.get_gameBoard(0,1))==(game_state.get_gameBoard(1,1)) && (game_state.get_gameBoard(0,1))==(game_state.get_gameBoard(2,1)) && (game_state.get_gameBoard(0,1))!=Empty){
            game_state.set_winCode(5);
        }
        
        else if((game_state.get_gameBoard(0,2))==(game_state.get_gameBoard(1,2)) && (game_state.get_gameBoard(0,2))==(game_state.get_gameBoard(2,2)) && (game_state.get_gameBoard(0,2))!=Empty){
            game_state.set_winCode(6);
        }
        
        else if((game_state.get_gameBoard(0,2))==(game_state.get_gameBoard(1,1)) && (game_state.get_gameBoard(0,2))==(game_state.get_gameBoard(2,0)) && (game_state.get_gameBoard(0,2))!=Empty){
            game_state.set_winCode(8);
        }
        
        else if((game_state.get_gameBoard(0,0))==(game_state.get_gameBoard(1,1)) && (game_state.get_gameBoard(0,0))==(game_state.get_gameBoard(2,2)) && (game_state.get_gameBoard(0,0))!=Empty){
            game_state.set_winCode(7);
        }
   
        else{
            game_state.set_winCode(0);//No Win- Draw or Empty positions still remaining for game to continue
        }
        
            
        if((game_state.get_winCode())==0){ //Draw or Empty positions still remaining for game to continue
            
            //Game Over- Draw Situation
            if((game_state.get_gameBoard(0,0))!=Empty && (game_state.get_gameBoard(0,1))!=Empty && (game_state.get_gameBoard(0,2))!=Empty && (game_state.get_gameBoard(1,0))!=Empty && (game_state.get_gameBoard(1,1))!=Empty && (game_state.get_gameBoard(1,2))!=Empty && (game_state.get_gameBoard(2,0))!=Empty && (game_state.get_gameBoard(2,1))!=Empty && (game_state.get_gameBoard(2,2))!=Empty){
                game_state.set_gameOver(true);;
            }
            //Empty positions remaining on the board
            else{
               game_state.set_gameOver(false); 
            }
        }
        
        //Game Over-Some Player Won
        else{
            game_state.set_gameOver(true);
        }
    }
    
    //If position played is invalid occupied)
    else{
        game_state.set_moveValid(false);
        game_state.set_gameOver(false);
    } 
}


