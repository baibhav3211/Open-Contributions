#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char arr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int choice, player;

int checkForWin();
void displayBoard();
void markBoard(char mark, int choice);

int main()
{
    int gameStatus;
    char mark;
    player = 1;
    do
    {
        displayBoard();

        // change of players done here
        player = (player % 2 == 0) ? 2 : 1;

        // printing the change
        printf("Player %d enter a number: ", player);
        // getting input
        scanf("%d", &choice);

        // set the correct character based on players turn
        mark = (player == 1) ? 'X' : 'O';

        markBoard(mark, choice);

        gameStatus = checkForWin();

        player++;
    } while (gameStatus != 1 && gameStatus != 0);

    displayBoard();
    if (gameStatus == 1)
        printf("\n\n-->Player %d won\n\n", --player);
    else
        printf("\n\n-->Game drawn\n\n");
    return 0;
}

/***********************************************************
 * Function to check the game status
 * Return 1 if the game has finished and has a winner
 * Return 0 if the game is over and does not return anything
 * Return -1 if the is still ongoing
 * **********************************************************/
int checkForWin()
{
    int returnValue;
    if (arr[1] == arr[4] && arr[4] == arr[7])
        returnValue = 1;
    else if (arr[2] == arr[5] && arr[5] == arr[8])
        returnValue = 1;
    else if (arr[3] == arr[6] && arr[6] == arr[9])
        returnValue = 1;
    else if (arr[1] == arr[2] && arr[2] == arr[3])
        returnValue = 1;
    else if (arr[4] == arr[5] && arr[5] == arr[6])
        returnValue = 1;
    else if (arr[7] == arr[8] && arr[8] == arr[9])
        returnValue = 1;
    else if (arr[1] == arr[5] && arr[5] == arr[9])
        returnValue = 1;
    else if (arr[3] == arr[5] && arr[5] == arr[7])
        returnValue = 1;
    else if (arr[1] != '1' && arr[2] != '2' && arr[3] != '3' && arr[4] != '4' && arr[5] != '5' && arr[6] != '6' && arr[7] != '7' && arr[8] != '8' && arr[9] != '9')
        returnValue = 0;
    else
        returnValue = -1;

    return returnValue;
}

/*******************************************************
 * Displays the matrix after updation
 * *****************************************************/
void displayBoard()
{
    system("cls");

    printf("\n\n=======Tic-Tac-Toe======\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

    printf("   |   |   \n");
    printf(" %c | %c | %c \n", arr[1], arr[2], arr[3]);
    printf("___|___|___\n");
    printf("   |   |   \n");

    printf(" %c | %c | %c \n", arr[4], arr[5], arr[6]);
    printf("___|___|___\n");
    printf("   |   |   \n");

    printf(" %c | %c | %c \n", arr[7], arr[8], arr[9]);
    printf("___|___|___\n");
}

/*****************************************************
 * Marks the X and O on the array
 * ***************************************************/

void markBoard(char mark, int choice)
{
    if (arr[1] == '1' && choice == 1)
        arr[1] = mark;
    else if (arr[2] == '2' && choice == 2)
        arr[2] = mark;
    else if (arr[3] == '3' && choice == 3)
        arr[3] = mark;
    else if (arr[4] == '4' && choice == 4)
        arr[4] = mark;
    else if (arr[5] == '5' && choice == 5)
        arr[5] = mark;
    else if (arr[6] == '6' && choice == 6)
        arr[6] = mark;
    else if (arr[7] == '7' && choice == 7)
        arr[7] = mark;
    else if (arr[8] == '8' && choice == 8)
        arr[8] = mark;
    else if (arr[9] == '9' && choice == 9)
        arr[9] = mark;
    else
    {
        printf("Invalid input\n");
        player--;
        getch();
    }
}