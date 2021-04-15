#include<stdio.h>

#include "game.h"

int isLegalMove(int column, board *currGame)
{
    int row = currGame->currRowPlaceCoin[(column-1)];

    //column number given by the player is not between 1 and 7, hence it is invalid
    if (!((column>=1) && (column<=7)))
    return 0;

    //the column in which the player is adding the his coin is already full
    if (row < 0)
    return 0;

    //returns one if there is no illegality in the move
    return 1;
}

void dropPiece(int column, board *currGame)
{
    int row = currGame->currRowPlaceCoin[(column-1)];
    int currPlayer = currGame->currentPlayer;

    currGame->boardContents[row][(column-1)] = currGame->playerColour[(currPlayer-1)];

    //decrementing the row index, to make it ready for the next coin to be placed in that column 
    currGame->currRowPlaceCoin[(column-1)] = currGame->currRowPlaceCoin[(column-1)] - 1;
}

int evaluateConnect(board *currGame, int row, int column)
{
    //int totalRows = 6;
    //int totalColumns = 7;
    int r,c, i,j;
    int directions[8][2] = { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1} };
    for( i=0; i<8; i++)
    {
        for( j=1; j<=4; j++)
        {
            r = row + directions[i][0]*j;
            c = column + directions[i][1]*j;
            if ( (!((r>=0) && (r<=5))) || (!((c>=0) && (c<=6))) )
            return 0;
            if ( currGame->boardContents[r][c] != currGame->boardContents[row][column] )
            return 0; 
        }
        return 1;
    }
    return 1;
}

int playerMove(board *currGame)
{
    int currPlay = currGame->currentPlayer;
    int col, row, legal, full, connectOccurred;

    printf("Turn of player %d\n",currGame->currentPlayer);
    printf("Player name: %s Colour: %c\n",currGame->playerName[(currPlay-1)],currGame->playerColour[(currPlay-1)]);
    
    printf("The current board is\n");
    printBoard(currGame);

    printf("Enter the column in which you want to place your coin\n");
    scanf("%d",&col);

    row = currGame->currRowPlaceCoin[(col-1)];

    legal = isLegalMove(col, currGame);

    if(legal)
    {
        dropPiece(col,currGame);

        col--; 

        connectOccurred = evaluateConnect(currGame,row,col);
        
        if(connectOccurred)
        {
            printf("\n THE WINNER IS: %s !!!!!!\n\nGAME OVER\n",currGame->playerName[(currPlay-1)]);
            return 1; //returns 1 to main function to indicate that game is over
        }

        full = boardFull(currGame);

        if (full)
        {
            printf("\nBOARD FULL!\nGAME OVER!\n");
            return 1; //returns 1 to main function to indicate game is over
        }

        else
        {
            if(currPlay == 1)
            currGame->currentPlayer = 2;
            else if(currPlay == 2)
            currGame->currentPlayer = 1;
            return 0; //returns 0 to main function to indicate that game is not yet over
        }
    }
    else
    {
        printf("Invalid move, try again.");
        return 0; //returns 0 to main function to indicate that game is not yet over
    }
    
}

int boardFull(board *currGame)
{
    int i;
    for( i=0; i<7; i++)
    {
        if (!(currGame->currRowPlaceCoin[i] < 0))
        return 0;
    }
    return 1;
}

void printBoard(board *currGame)
{
    int i,j;
    printf("\n 1 2 3 4 5 6 7\n");
    for( i=0; i<6; i++)
    {
        printf(" - - - - - - -\n");
        for ( j=0; j<7; j++)
        printf("|%c",currGame->boardContents[i][j]);
        printf("|\n");
    }
    printf(" - - - - - - -\n\n");
}