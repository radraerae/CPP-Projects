/*What I know about pointers is they help me not need global variables, objects
like the tic-tac-toe board are passed as constant pointers instead of references.
The address of a tic-tac-toe board must be passed instead of the board itself*/

//I've removed all previous comments from the code and added comments that aided me in this assignment

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//global constant variables
/*I need the global constant variables, besides the 
assignment stated to only remove referenced code*/
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

void instructions(); //this stays the same
char askYesNo(string question); //this stays the same
int askNumber(string question, int high, int low = 0); //this stays the same
char humanPiece(); //this stays the same
char opponent(char piece); //this stays the same
int computerMove(vector<char> board, char computer); //this stays the same
void announceWinner(char winner, char computer, char human); //this stays the same

//the functions that are changed:
/*all of these functions had references removed. They are
constant vectors named pBoard which is a constant pointer*/
void displayBoard(const vector<char>* const pBoard); 
char winner(const vector<char>* const pBoard); 
bool isLegal(const vector<char>* const pBoard, int move);
int humanMove(const vector<char>* const pBoard, char human); 

int main()
{
    int move;
    const int NUM_SQUARES = 9;
    vector<char> board(NUM_SQUARES, EMPTY);
    /*the vector named board, passes the NUM_SQUARES and 
    EMPTY variables as needed into the function*/

    instructions();
    char human = humanPiece();
    char computer = opponent(human);
    char turn = X;
    displayBoard(&board); 
    //the address of board is passed through the displayBoard function

    while (winner(&board) == NO_ONE) 
    //the address of board is passed through the winner function
    {
        if (turn == human)
        {
            move = humanMove(&board, human); 
            //the address of board is passed through humanMove function
            board[move] = human;
            //this piece of code...
        }
        else
        {
            move = computerMove(board, computer); 
            /*the computerMove function manipulates a copy of the board,
            and needs this copy, I don't use the address of operator here for that reason.*/
            board[move] = computer;
            /*Again, the copy of the board is used with the computer's move here. I don't
            use the address of operator for this reason*/
        }
        displayBoard(&board); 
        //the address of the board is passed through displayBoard again
        turn = opponent(turn);
    }

    announceWinner(winner(&board), computer, human); 
    //the address of the board is passed through winner

    return 0;
}

void instructions() //this function isn't changed
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
}

//this function isn't changed
char askYesNo(string question) 
{
    char response;
    do
    {
        cout << question << " (y/n): ";
        cin >> response;
    } while (response != 'y' && response != 'n');

    return response;
}

//this function isn't changed
int askNumber(string question, int high, int low)
{
    int number;
    do
    {
        cout << question << " (" << low << " - " << high << "): ";
        cin >> number;
    } while (number > high || number < low);

    return number;
}

//the function isn't changed
char humanPiece()
{
    char go_first = askYesNo("Do you require the first move?");
    if (go_first == 'y')
    {
        cout << "\nThen take the first move.  You will need it.\n";
        return X;
    }
    else
    {
        cout << "\nYour bravery will be your undoing... I will go first.\n";
        return O;
    }
}

//the function isn't changed
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

/*the function passes a constant vector that holds characters
that are labeled a constant pointer which is named pBoard.*/
void displayBoard(const vector<char>* const pBoard)
{
    /*the pointer is being sent to cout, like iterators, I must
    dereference it to access the object it points to.*/
    cout << "\n\t" << (*pBoard)[0] << " | " << (*pBoard)[1] << " | " << (*pBoard)[2];
    cout << "\n\t" << "---------";
    cout << "\n\t" << (*pBoard)[3] << " | " << (*pBoard)[4] << " | " << (*pBoard)[5];
    cout << "\n\t" << "---------";
    cout << "\n\t" << (*pBoard)[6] << " | " << (*pBoard)[7] << " | " << (*pBoard)[8];
    cout << "\n\n";
}

/*the function passes a constant vector that holds characters
that are labeled a constant pointer which is named board.*/
char winner(const vector<char>* const pBoard)
{
    const int WINNING_ROWS[8][3] = { {0, 1, 2},
                                     {3, 4, 5},
                                     {6, 7, 8},
                                     {0, 3, 6},
                                     {1, 4, 7},
                                     {2, 5, 8},
                                     {0, 4, 8},
                                     {2, 4, 6} };
    const int TOTAL_ROWS = 8;

    for(int row = 0; row < TOTAL_ROWS; ++row)
    {
        /*Again, I must dereference the pointer to 
        access the object to which it points to.*/
        if ( ((*pBoard)[WINNING_ROWS[row][0]] != EMPTY) &&
             ((*pBoard)[WINNING_ROWS[row][0]] == (*pBoard)[WINNING_ROWS[row][1]]) &&
             ((*pBoard)[WINNING_ROWS[row][1]] == (*pBoard)[WINNING_ROWS[row][2]]) )
        {
            /*This code returns the piece in the first position of the
            winning row in the object with which pBoard points to.*/
            return (*pBoard)[WINNING_ROWS[row][0]];  
        }
    }

    /*The STL count() algorithm is used with the pointer vector board. 
    I didn't use -> because of no particular reason*/
    if (count((*pBoard).begin(), (*pBoard).end(), EMPTY) == 0)
    //pBoard is dereferenced for obvious reasons.
        
        return TIE;  

      
        return NO_ONE; 
}

/*the function passes a constant vector that holds characters
that are labeled a constant pointer, which is named board.*/
inline bool isLegal(int move, const vector<char>* const pBoard) 
{
    return ((*pBoard)[move] == EMPTY);
    //returns the object with which pBoard is pointing to with either a true or false
}

/*the function passes a constant vector that holds characters
that are labeled a constant pointer, which is named board.*/
int humanMove(const vector<char>* const pBoard, char human) 
{
    int move = askNumber("Where will you move?", ((*pBoard).size() - 1));
    /*the object with which the pointer points to, its size decreases 
    by one which in turn decreases the vector size.*/
    
    while (!isLegal(move, pBoard)) 
    //the pointer board is passed through isLegal
    {
        cout << "\nThat square is already occupied, foolish human.\n";
        move = askNumber("Where will you move?", ((*pBoard).size() - 1));
        /*the object with which the pointer points to, its size decreases 
        by one which in turn decreases the vector size.*/
    }
    cout << "Fine...\n";

    return move;
}

/*board isn't altered in the computerMove function because 
it needs to be changed and make copies*/
int computerMove(vector<char> board, char computer)
{ 
    unsigned int move = 0;
    bool found = false;

    while (!found && move < board.size())
    //no address of operator, board object's size is being used
    {
        if (isLegal(move, &board)) 
        //the address of the board is passed through isLegal
        {
            board[move] = computer;
            //copy of board is being used, no address of operator

            found = winner(&board) == computer; 
            //this test part passes the address of board into winner 

            board[move] = EMPTY;
            //copy of board is used, no address of operator
        }

        if (!found)
        {
            ++move;
        }
    }
  
    if (!found)
    {
        move = 0;
        char human = opponent(computer);

        while (!found && move < board.size())
        //no address of operator, board object's size is being used
        {
            if (isLegal(move, &board)) 
            //the address of the board is passed through isLegal
            { 
				board[move] = human;
                //copy of board is being used, no address of operator

				
                found = winner(&board) == human; 
                //this test part passes the address of board into winner 
 
	
				board[move] = EMPTY;  
                //copy of board is used, no address of operator
            }

            if (!found)
            {
                ++move;
            }
        }
    }

    if (!found)
    {
        move = 0;
        unsigned int i = 0;

        const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};

        while (!found && i < board.size())
        //no address of operator, board object's size is being used
        {
            move = BEST_MOVES[i];
            if (isLegal(move, &board)) 
            //the address of the board is passed through isLegal
            {
                found = true;
            }

            ++i;
        }
    }

    cout << "I shall take square number " << move << endl;
	return move;
}

void announceWinner(char winner, char computer, char human)
{
	if (winner == computer)
    {
        cout << winner << "'s won!\n";
        cout << "As I predicted, human, I am triumphant once more -- proof\n";
        cout << "that computers are superior to humans in all regards.\n";
    }

	else if (winner == human)
    {
        cout << winner << "'s won!\n";
        cout << "No, no!  It cannot be!  Somehow you tricked me, human.\n";
        cout << "But never again!  I, the computer, so swear it!\n";
    }

	else
    {
        cout << "It's a tie.\n";
        cout << "You were most lucky, human, and somehow managed to tie me.\n";
        cout << "Celebrate... for this is the best you will ever achieve.\n";
	}
}

