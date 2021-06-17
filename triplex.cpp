#include <iostream>
#include <ctime> //this is part of seeding rand, you access the computer's time so that the answers are randomized depending on the time of day


/*Because the operator can throw an exception. (When you compile) 
You will need to add /EHsc when compiling e.g. "cl triplex.cpp /EHsc*/

//the print introduction function comes before the playgame because it must be declared
void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nWelcome back to the world Agent. You are in level \n" << Difficulty; //this is the introduction with the game difficulty or level being inputted into that
    std::cout << " of the underground defense tunnel. The base has been destroyed, you need to enter the correct codes to continue on...\n";
}

bool PlayGame(int Difficulty) //this playgame function has the level difficulty so that the introduction function can be introduced with the difficulty
{
    PrintIntroduction(Difficulty);
    
    /*because we don't want our numbers to be the same when they are outputted, we use rand, but we don't want crazily large numbers that rand puts out
    so, I included a modulus operator for its division usage and its result in a small number. We set it modulus difficulty because the difficulty is off
    setting the range by its own value*/
    const int CodeA = rand() % Difficulty + Difficulty; 
    const int CodeB = rand() % Difficulty + Difficulty; 
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC; //code sum and product are the three digit numbers added or multiplied together
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << std::endl;
    std::cout << "-There are three numbers in the code \n"; //this is the explanation of the game
    std::cout << "-The codes add up to: " << CodeSum << std::endl;
    std::cout << "-The codes multiply to give: " << CodeProduct << std::endl;
    
    int GuessA, GuessB, GuessC; //this is the declaration of the players 3 digit guess
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "\nYou entered: " << GuessA << GuessB << GuessC << std::endl;

    int GuessSum = GuessA + GuessB + GuessC; //this is the initialzation of that sum and product from the user's input
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct) //an if statement reguarding if the user's guess equals the right number
    {
        std::cout << "\n**Excellent work, you have passed this level, hurry and continue on.**";
        return true;
    }
    else
    {
        std::cout << "\n**Error! You have entered the wrong combination, please try again.**";
        return false;
    }
}

int main() //within the main function holds the level complete boolian alongside the playgame fuction with the level difficulty
{   
    srand(time(NULL)); //this creates a new random sequence of numbers based on the time of day

    int LevelDifficulty = 1; //this is the declaration of the beginning level difficulty

    const int MaxLevel = 5; //with the max level that can not be changed

    while (LevelDifficulty <= MaxLevel) //this will loop the game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //clears any errors with reguards to the user input
        std::cin.ignore(); //this discards the buffer

        if (bLevelComplete) //this shows that if the level is complete, then the level difficulty increases by one
        { 
             ++LevelDifficulty; 
        }   
    }

    std::cout << "\n**Congratulations, you have passed all of the missions and have continued on.**"; //the main function returns the final message before ending
    
    return 0;
}