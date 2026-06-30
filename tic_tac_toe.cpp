#include <iostream>

using namespace std;

char board[3][3];

void createBoard()
{
    char value = '1';

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = value;
            value++;
        }
    }
}

void displayBoard()
{
    cout << endl;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << board[i][j];

            if(j < 2)
            {
                cout << " | ";
            }
        }

        cout << endl;

        if(i < 2)
        {
            cout << "--|---|--" << endl;
        }
    }

    cout << endl;
}

bool checkWin()
{
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] &&
           board[i][1] == board[i][2])
        {
            return true;
        }

        if(board[0][i] == board[1][i] &&
           board[1][i] == board[2][i])
        {
            return true;
        }
    }

    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2])
    {
        return true;
    }

    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0])
    {
        return true;
    }

    return false;
}

bool checkDraw()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != 'X' &&
               board[i][j] != 'O')
            {
                return false;
            }
        }
    }

    return true;
}

void playerMove(char symbol)
{
    int choice;

    cout << "Player " << symbol
         << " Enter Position : ";

    cin >> choice;

    if(choice == 1 && board[0][0] == '1')
        board[0][0] = symbol;

    else if(choice == 2 && board[0][1] == '2')
        board[0][1] = symbol;

    else if(choice == 3 && board[0][2] == '3')
        board[0][2] = symbol;

    else if(choice == 4 && board[1][0] == '4')
        board[1][0] = symbol;

    else if(choice == 5 && board[1][1] == '5')
        board[1][1] = symbol;

    else if(choice == 6 && board[1][2] == '6')
        board[1][2] = symbol;

    else if(choice == 7 && board[2][0] == '7')
        board[2][0] = symbol;

    else if(choice == 8 && board[2][1] == '8')
        board[2][1] = symbol;

    else if(choice == 9 && board[2][2] == '9')
        board[2][2] = symbol;

    else
    {
        cout << endl;
        cout << "Invalid Move. Try Again." << endl;

        playerMove(symbol);
    }
}

int main()
{
    char playAgain;

    do
    {
        createBoard();

        char currentPlayer = 'X';

        while(true)
        {
            displayBoard();

            playerMove(currentPlayer);

            if(checkWin())
            {
                displayBoard();

                cout << "Player "
                     << currentPlayer
                     << " Wins!" << endl;

                break;
            }

            if(checkDraw())
            {
                displayBoard();

                cout << "Match Draw!" << endl;

                break;
            }

            if(currentPlayer == 'X')
            {
                currentPlayer = 'O';
            }
            else
            {
                currentPlayer = 'X';
            }
        }

        cout << endl;
        cout << "Play Again? (Y/N) : ";
        cin >> playAgain;

    }
    while(playAgain == 'Y' || playAgain == 'y');

    cout << endl;
    cout << "Game Closed Successfully." << endl;

    return 0;
}
