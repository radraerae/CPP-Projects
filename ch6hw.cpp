#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//the global constants
const char X = 'X';
const char O = 'O';
const char EMPTY = ' '; //this const char is for the empty space
const char TIE = 'T'; //this const char is for when there is a tie game
const char NO_ONE = 'N';; //this const char is for when no one wins

//the function prototypes
void instructions(); //no parameters
char askYesNo(string question); //question string parameter
int askNumber(string question, int high, int low = 0); //question string, high int and low range parameters
char humanPiece(); //no parameters
char opponent(char piece); //piece char parameter
void displayBoard(const vector<char>& board); //referenced vector board parameter
char winner(const vector<char>& board); //referenced vector board parameter
bool isLegal(const vector<char>& board, int move); //referenced vector board & move int parameter 
int humanMove(const vector<char>& board, char human); //referenced vector board & human char parameters
int computerMove(vector<char> board, char computer); //vector board & computer char parameters
void announceWinner(char winner, char computer, char human); // winner, computer, and human char parameters

int main()
{
    int move; //the int variable named "move" from the is legal function
    const int NUM_SQUARES = 9; //the board has 9 spaces in it
    vector<char> board(NUM_SQUARES, EMPTY); 
    //the board vector includes the NUM_SQUARES const int and the EMPTY const char

    instructions(); //calls instructions
    char human = humanPiece(); //the human is connected to the human piece function 
    char computer = opponent(human); //the computer is connected to the opponent function which contains human, this is called
    char turn = X; //creates a char variable turn that equals the global variable X
    displayBoard(board); //displays the board

    while (winner(board) == NO_ONE) //while loop for when the board returned shows no one as the winner
    {
        if (turn == human) //if the turn is the human's
        {
            //the move is the humanMove function, this is called, the parameters are the board vector and the human char
            move = humanMove(board, human); 
            board[move] = human; //board vector is assigned the human's move
        }
        else
        {
            //the move is the computerMove function, this is called, the parameters are the board vector and the computer char
            move = computerMove(board, computer); 
            board[move] = computer; //board vector is assigned the computer's move
        }
        displayBoard(board); //the board is displayed again
        turn = opponent(turn); //the turn is connected to the opponent function which has the global variable in it
    }

    announceWinner(winner(board), computer, human); //announceWinner function is called

    return 0;
}

//the functions
void instructions() //displays the game instructions and what the board looks like
{
    cout << "Welcome to the ultimate man-machine showdown: Tic-Tac-Toe.\n";
    cout << "--where human brain is pit against silicon processor\n\n";

    cout << "Make your move known by entering a number, 0 - 8. The number\n";
    cout << "corresponds to the desired board position, as illustrated:\n\n";

    cout << "       0 | 1 | 2\n";
    cout << "       ---------\n";
    cout << "       3 | 4 | 5\n";
    cout << "       ---------\n";
    cout << "       6 | 7 | 8\n\n";

    cout << "Prepare yourself, human. The battle is about to begin.\n\n";

    //returns nothing
}

//asks a yes or no question. receives a question, and returns either a 'y' or 'n'*
char askYesNo(string question)
{
    char response; //the players response to the question
    do //do while loop continues until the player either says yes or no
    {
        cout << question << " (y/n): "; //outputs the question and a y or n?
        cin >> response;
    } while (response != 'y' && response != 'n');

    return response; //returns whatever the response is
}

/*asks for a number within a range. receives a question, a low number,
and a high number. returns a number within the range from low to high*/
int askNumber(string question, int high, int low)
{
    int number; //player's number response
    do //do while loop continues as long as number reply is less than the high and more than the low
    {
        cout << question << " (" << low << " - " << high << "): ";
        cin >> number;
    } while (number > high || number < low);

    return number; //returns whatever the number ranges between the high and the low
}

//determines the human's piece returns either an 'X' or an 'O'
char humanPiece()
{
    //char go first connects to the askYesNo function, we finally type the actual question
    char go_first = askYesNo("Do you require the first move?");
    if (go_first == 'y') //if go first equals y then human goes first
    {
        cout << "\nThen take the first move. You will need it.\n";
        return X; //the first move in tic-tac-toe is traditionally X
    }
    else 
    {
        cout << "\nYour bravery will be your undoing... I will go first.\n";
        return O;
    }
}

/*calculates the opposing piece given a piece. receives either an 
'X' or an 'O', returns either an 'X' or an 'O'*/
char opponent(char piece)
{
    if (piece == X)
    {
        return O;
    }
    else
    {
        return X;
    }
}

//displays the board on the screen, receives a board
//this is passed through a constant reference, the vector is passed efficiently; it's not copied
void displayBoard(const vector<char>& board) //displays in a grid like form
{
    cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
    cout << "\n\t" << "---------";
    cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
    cout << "\n\t" << "---------";
    cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
    cout << "\n\n";
}

//determines the game winner. receives a board. returns an 'X','O', 'T', or 'N'
//this is passed through a constant reference, the vector is passed efficiently; it's not copied
char winner (const vector<char>& board)
{
    //2-D array; eight by three
    const int WINNING_ROWS[8][3] = { {0, 1, 2}, //all the possible winning rows
                                     {3, 4, 5},
                                     {6, 7, 8},
                                     {0, 3, 6},
                                     {1, 4, 7},
                                     {2, 5, 8},
                                     {0, 4, 8},
                                     {2, 4, 6} };
    const int TOTAL_ROWS = 8; //a constant integer is made, the total rows of possible wins are 8 

//if any winning row has three values that are the same (and not EMPTY), then we have a winner
    /*for loop loops through each possible way a player can win, this is done 
    so we can see whether either player has three in a row*/
    for (int row = 0; row < TOTAL_ROWS; ++row) 
    {
        /*if statement checks to see whether the three squares in question all contain the same value
        and are not EMPTY. If so, it means that the row either has 3 X's or 3 O's, one side has won.*/
        if ( (board[WINNING_ROWS[row][0]] != EMPTY) &&
             (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
             (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]) )
        {
            return board [WINNING_ROWS[row][0]]; //returns the piece in the first position of the winning row
        }
    }

    //since no one has won, we check for a tie game (no empty squares left)
    /*The STL count() algorithm is used, it counts the number of times a given value appears in
    a group of container elements. For this it counts the number of EMPTY elements in board.
    If the number is equal to 0, the function returns a TIE.*/
    if (count(board.begin(), board.end(), EMPTY) == 0)

        return TIE; //returns the TIE game 

        //since no one has won yet and it isn't a tie, the game isn't over
        return NO_ONE; //returns the NO_ONE has one game

}

//determines whether a move is legal. receives a board and a move. returns either true or false
//this vector is passed through a constant reference it's passed efficiently and not copied
//bool is also inlined for efficiency
inline bool isLegal(int move, const vector<char>& board)
{
    return (board[move] == EMPTY); //returns the board vector with either a true or false 
}

//get's the human's move. receives a board and the human's piece. returns the human's move
//the vector is passed through a constant reference, passed efficiently, not copied
int humanMove(const vector<char>& board, char)
{
    /*the int move is connected to askNumber function, the size is decreased by one
    because of the move being made*/
    int move = askNumber("Where will you move?", (board.size() - 1));
    while (!isLegal(move, board)) //while loop for when the boolean move and board is NOT legal
    {
        //if it's not legal, then:
        cout << "\nThat square is already occupied, foolish human.\n"; 
        move = askNumber("Where will you move?", (board.size() - 1));
        //move is connected to askNumber, question is in there, the size is decreased by one
    }

    //if the move is legal then the size has decreased and the move is set
    cout << "Fine...\n";

    return move; //returns the move the human has made
}

//calculuates the computer's move. receives a board and the computer's piece. returns the computer's move
//this is passed by value, this is because the copy of the board needs to be copied
int computerMove(vector<char> board, char computer)
{
    unsigned int move = 0; //an integer move is made that can only store positive values
    bool found = false; //a boolean called found is made, it is set to false

    //if the computer can win on the next move. that's the move to make
    while (!found && move < board.size()) //while found is not false, it loops through all the possible moves (0-8)
    {
        if (isLegal(move, board)) //if makes sure that those possible moves are legal
        {
            //this is the try move for that spot
            board[move] = computer;
            //this tests for the winner
            found = winner(board) == computer;
            //this is the undo move for that same spot
            board[move] = EMPTY;
        }
        if (!found) //if found is not false (found is true), the move is done again to find another
        {
            ++move;
        }
    }

    //otherwise, if opponent can win on next move, that's the move to make
    /*if the computer hasn't found a move yet (found is false), 
    then it checks to see whether the human can win on their next move.*/
    if (!found) 
    {
        move = 0; //with this one the move is set to zero as well
        char human = opponent(computer); //human is connected to the opponent function which contains computer, this is called

        while(!found && move < board.size()) //while loops through all of the possible moves (0-8)
        {
            if (isLegal(move, board)) //tests whether each move is legal
            {
                //the try move of the human
                board[move] = human;
                //this tests for winner from the human move
                found = winner(board) == human;
                //this undoes that move
                board[move] = EMPTY;
            }
            /*If the move didn't give the human a win, then the loop ends, and the computer's found 
            the move (found is true), that it wants to make to bloxk the human from winning the next move*/
            if (!found) 
            {
                ++move;
            }
        }
    }

    /*If the computer hasn't found a move yet (found is false) then it looks through the list of best moves,
    in order or desirability, and takes the first legal one.*/
    //otherwise, moving to the best open square is the move to make that's legal
    if (!found) //if found is still false
    {
        move = 0;
        unsigned int i = 0; //an integer named i is equal to zero that can only store positie values

        const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7}; //an integer array is made that holds the best moves
        //picks best open square
        while (!found && i < board.size()) //while loop for when found is still false and i is < the size of the board
        {
            move = BEST_MOVES[i]; //move is assigned the best_moves array
            if (isLegal(move, board)) //if the move is legal, then the found is true
            {
                found = true;
            }

            ++i; //the best moves is cycled through until the computer chooses the one that is best
        }
    }

    cout << "I shall take the square number " << move << endl;

    return move; //returns the computers move (square number) 
}

/*congratulates the winner or declares a tie. receives the winning side,
the computer's piece, the human's piece and receives the winner of the game*/
void announceWinner(char winner, char computer, char human)
{
    if (winner == computer) //if the computer has won
    {
        cout << winner << "'s won!\n";
        cout << "As I predicted, human, I am triumphant once more -- proof\n";
        cout << "that computers are superior to humans in all regards.\n";
    }
    else if (winner == human) //if the human has won
    {
        cout << winner << "'s won!\n";
        cout << "No, no!  It cannot be!  Somehow you tricked me, human.\n";
        cout << "But never again!  I, the computer, so swear it!\n"; 
    }
    else //if there is a tie game
    {
        cout << "It's a tie.\n";
        cout << "You were most lucky, human, and somehow managed to tie me.\n";
        cout << "Celebrate... for this is the best you will ever achieve.\n";
    }

    //returns nothing
}