#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#include "create_game.h"

void initializeBoard(board *currGame, char name1[], char name2[])
{
    currGame->numberOfRows = 6;
    currGame->numberOfColumns = 7;
    currGame->numToConnect = 4;

    strcpy(currGame->playerName[0],name1);
    strcpy(currGame->playerName[1],name2);
    
    printf("Player 1 is assigned the colour black denoted by B\n");
    printf("Player 2 is assigned the colour red denoted by R\n");
    currGame->playerColour[0] = 'B';
    currGame->playerColour[1] = 'R';

    currGame->currentPlayer = 0;
    currGame->winner = 0;

    //initializing the contents of the board to empty spaces and the current row in which the coin will fall for a column selected by the user
    int i,j;
    for( i=0; i<6; i++)
    {
        currGame->currRowPlaceCoin[i] = 5;
        for( j=0; j<7; j++)
        currGame->boardContents[i][j] = ' ';
    }
   
}

void decideFirstPlayer(board *currGame)
{
    printf("Deciding which player will be the first to play........\n");
    srand(time(0));

    //generating a random number which is either 1 or 2 
    int player = (rand()%2)+1;

    //setting the current player in the board object as 1
    if(player == 1)
    currGame->currentPlayer = 1;

    //setting the current player in the board object as 2
    else
    currGame->currentPlayer = 2;
}
