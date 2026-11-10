#include <stdio.h>
#include <stdlib.h>

//function to display the board
void display(char board[]) {
    printf("%c|%c|%c\n-+-+-\n%c|%c|%c\n-+-+-\n%c|%c|%c\n",board[0],board[1],board[2],board[3],board[4],board[5],board[6],board[7],board[8]);
}

int main()
{
    // numbering the squares
    char board[9] = {'0','1','2','3','4','5','6','7','8'};
    //where the player went
    int Current_Move = 0;
    int Move_History[9] = {9,9,9,9,9,9,9,9,9};
    //how many moves have been made
    int Move_Number = 0;
    //has the game finished naturally
    int finish = 0;
    display(board);
    do {
            //read in where the player wishes to go
            printf("Please input the number of the square you would like to place your X in.\n");
            scanf("%d", &Current_Move);
            //Check if the move is valid
        if ((Current_Move < 9)&&(Current_Move!=Move_History[0])&&(Current_Move!=Move_History[1])&&(Current_Move!=Move_History[2])&&(Current_Move!=Move_History[3])&&(Current_Move!=Move_History[4])&&(Current_Move!=Move_History[5])&&(Current_Move!=Move_History[6])&&(Current_Move!=Move_History[7])&&(Current_Move!=Move_History[8])) {
            //add it to the history
            board[Current_Move] = 'X';
            Move_History[Move_Number] = Current_Move;
            Move_Number++;
            // Check win condition
            if (((board[0]==board[1])&&(board[1]==board[2]))||((board[3]==board[4])&&(board[4]==board[5]))||((board[6]==board[7])&&(board[7]==board[8]))||((board[0]==board[3])&&(board[3]==board[6]))||((board[1]==board[4])&&(board[4]==board[7]))||((board[2]==board[5])&&(board[5]==board[8]))||((board[0]==board[4])&&(board[4]==board[8]))||((board[2]==board[4])&&(board[4]==board[6]))) {
                //display the winning move
                display(board);
                printf("You Win");
                finish++;
                break;
                }
            //loop until valid
            //don't do the ai's turn on draw
            if (Move_Number > 8) {
                break;
            }
            do {
                // The "AI" chooses a move randomly
                Current_Move = rand()%9;
                if ((Current_Move < 9)&&(Current_Move!=Move_History[0])&&(Current_Move!=Move_History[1])&&(Current_Move!=Move_History[2])&&(Current_Move!=Move_History[3])&&(Current_Move!=Move_History[4])&&(Current_Move!=Move_History[5])&&(Current_Move!=Move_History[6])&&(Current_Move!=Move_History[7])&&(Current_Move!=Move_History[8])) {
                    // display the moves and add it to the history
                    board[Current_Move] = 'O';
                    display(board);
                    Move_History[Move_Number] = Current_Move;
                    Move_Number++;
                    break;
                    }
                } while (1);
            // Check win condition
            if (((board[0]==board[1])&&(board[1]==board[2]))||((board[3]==board[4])&&(board[4]==board[5]))||((board[6]==board[7])&&(board[7]==board[8]))||((board[0]==board[3])&&(board[3]==board[6]))||((board[1]==board[4])&&(board[4]==board[7]))||((board[2]==board[5])&&(board[5]==board[8]))||((board[0]==board[4])&&(board[4]==board[8]))||((board[2]==board[4])&&(board[4]==board[6]))) {
                printf("You Lose");
                finish++;
                break;
                }
        } else {printf("Please input a valid number.");}
    } while (Move_Number < 9);
    //check for draw
    if ((finish == 0)&&(Move_Number > 8)) {
        display(board);
        printf("Draw");
    }
    //beep when done
    printf("%c",7);
    return 0;
}

