#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//functions
void story(); //prompts the story 
void ending(); //prompts the story ending
void adventure(); //holds the entire adventure and dieroll chance of the player winning gold or not, can be exited
string askYesNo(string question); //string type that asks if they would like to continue adventuring
int rollDie(int sides = 6); //the function that randomizes the die roll

//global variables
int health = 30;
int totalTreasure;
int stop; //this is part of a loop in main that will end 

void story()
{
    cout << "You are awoken by the rumble of the horse carriage stopping." << endl;
    cout << "As you look outside and you see you have arrived at your destination." << endl;
    cout << "You are on a journey to explore a newely opened part of your country!" << endl;
    cout << "It's a wild stretch of land with many different environments and people." << endl;
    cout << "This quest comes with great risk, enemies will be prevalent, but an abundance of reward will follow." << endl;
}
int main()
{
    story();
    stop = 1;
    string answer;
    do
    {   
        answer = askYesNo("\nWould you like to go on this adventure?"); //this is a looping of the question 
        if (answer == "Yes" || answer == "yes")
        {
            adventure();
        }
        else if (answer == "No" || answer == "no") 
        {
            ending();
            break;  //the loop is broken out of after prompting ending
        }
        else
        {
           cout << "\nI'm sorry, I don't understand you." << endl;
        }
        
    } while(stop > 0); //loop will continue as long as int stop is over 0

    return 0;
}
int rollDie(int sides)
{
    
    int dieroll = (rand() % sides) + 1; //limiting the dieroll to be 1-6
    
    srand(static_cast<unsigned int>(time(0))); //randomizing the number generator
    
    return dieroll;
}
void adventure()
{
    int playerBlock;
    int enemyAttack;
    totalTreasure; //the sum of the total treasure
    int gain; //this shows the random number of coins you gain each turn

    playerBlock = rollDie(); //player block range is 1-6
    enemyAttack = rollDie(); //the enemy attack is randomized 1-6
    
    cout << "\nLet's embark on this adventure." << endl; //if they say yes then adventure starts
    if (playerBlock >= enemyAttack) 
    {
        totalTreasure += playerBlock * 2;
        gain = playerBlock * 2;
        cout << "\nYou have blocked successfully!" << endl;
        cout << "You have gained " << gain << " gold coins!" << endl;

    }
    else if (enemyAttack > playerBlock)
    {
        health -= enemyAttack;
        cout << "\nYour block didn't work!" << endl;
        cout << "You have lost " << enemyAttack << "HP." << endl;
        cout << "\n-Your health status is " << health << " HP.-\n" << endl; 
    }
    if (health <= 0) //if the player dies, ending is prompted
    {
        ending();
    }
    
    cout << "Your total treasure amount is " << totalTreasure << " coins." << endl;

}
string askYesNo(string question) 
{
    string responce;
    
    cout << question << endl;
    cout << "(Yes/No)?" << endl;
    cin >> responce;

    return responce;
}
void ending()
{
    if (health <= 0)
    {
        cout << "You have died! What a shame!" << endl;
    }
    else //the caance that they end the adventure early
    {
        cout << "You returned home with " << totalTreasure << " coins in total." << endl;
        cout << "\n-Your final health status is " << health << "HP!-\n" << endl;
    }
    
    stop = -1; //ends the loop entirely
}