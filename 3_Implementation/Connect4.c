/**
 * @file Connect4.c
 * @author Jayasri Vaidyaraman
 * @brief Program to play the game Connect4
 * @version 0.1
 * @date 2021-04-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include<stdlib.h>

#include "connect_four.h"

///Global variable board that contains the details of the ongoing board game
board currentGame;

int main()
{
    int choice, status;
    char name1[100], name2[100];
    //pointer to the global game object is initialized
    board *currGame = &currentGame;

    do 
    {
        displayMenu();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
                    printf("Enter the following details to start the game\n");
                    
                    printf("Enter the name of first player\n");
                    scanf("%s",name1);
                    
                    printf("Enter the name of the second player\n");
                    scanf("%s",name2);

                    initializeBoard(currGame, name1, name2);
                    decideFirstPlayer(currGame);
                    do
                    {
                        status = playerMove(currGame);
                    }while(status == 0);
                    break;

            case 2: printf("Goodbye, terminating the game!\n");
                    exit(0);
                    break;
                    
            default: printf("Wrong Choice\n");
                    choice = 1;
                    break;
        }
    } while( choice == 1);
}