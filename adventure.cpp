#include <iostream>
#include <string>
#include <cstdlib> //for the random number generator
#include <ctime> //for a different number generated based on the computers inner clock
#include <Windows.h> //sleep() function
using namespace std;

int main()
{

int playerHealth = 10; //player info
int enemyAttack;
int playerBlock;
int playerTurns = 0;

int randomNumber = rand() % 4 + 1; //generates random number

srand(static_cast<unsigned int>(time(0))); //seeding the random number

cout << "\nHi there! You're finally awake..uh. I'm sorry, my memory card doesn't hold your name. " << "What is it again?" << endl;

string playerName;
string helmetName; //gave the player a guide 

helmetName = "Solar 42";

cin >> playerName; //player can input their name

Sleep (1000);
cout << "\n~Ahh I knew it, welcome " << playerName << ". You're in the most dangerous place of the universe.~" << endl;
Sleep (3000);
cout << "I only say it casually so the new trainees don't get overwhelmed and puke. But, you did sign up for the Intergalactic Army.\n" << endl;
Sleep (5000);
cout << "Right now you are...pretty far out from where you started. Your unit is approximately 56 miles away from you." << endl;
Sleep (5000);
cout << "A terrible bomb wiped out the town you were defending, and after that havok spread. I am not quite sure how we wandered so far." << endl;
Sleep (5000);
cout << "Unfortunately, all of your weapons have been either destroyed or are missing, you are lucky to be alive." << endl;
Sleep (5000);
cout << "If your memory is forgotten, I am your helmet guide " << helmetName << ". I will be here to guide you through this war and back to your unit.\n" << endl;
Sleep (4000);
cout << "We don't have much time left to chit chat, I sense enemy forces coming up on the horizon." << endl;
Sleep (4000);
cout << "Right now we are going to have to defend ourselves, at least until more weapons come.\n" << endl;
Sleep (4000);
cout << "Are you ready young soldier? Yes or No?" << endl;

string readyAnswer;
cin >> readyAnswer;

if (readyAnswer == "Yes" || readyAnswer == "yes")
{
    cout << "\nThat's what I like to hear. Now ready yourself, an alien is closing in!" << endl;
}
else if (readyAnswer == "No" || readyAnswer == "no")
{
    cout << "\nWrong answer, you're going to defend yourself anyway. Come on!" << endl;
}
else
{
    cout << "What was that? Nevermind let's go." << endl;
}

string playConfirmation;

cout << "The enemy is now in front of you.\n" << endl;

do
{
    cout << "Will you block?\n" << "Yes or No?" << endl;
    cin >> playConfirmation;
    playerTurns++; //the player's turns are used each time player says yes or no.

if (playConfirmation == "Yes" || playConfirmation == "yes")
{
    playerBlock = (rand() % 4) + 1; //random numbers between 1-4 in the player's block
    cout << "\nYour block was equal to " << playerBlock << " protection." << endl;

    enemyAttack = (rand() % 4) + 1; //random numbers between 1-4 in enemy attack
    cout << "The enemy dealt " << enemyAttack << " hit points." << endl;
    
    if (playerBlock >= enemyAttack) 
    {
        cout << "\n~That was a successful block! Nice job!~" << endl;
    }
    else if (enemyAttack > playerBlock)
    {
        playerHealth -= enemyAttack;
        cout << "You have suffered damage, that block didn't work." << endl;
    }
}
else if (playConfirmation == "No" || playConfirmation == "no") //gave player a choice to say no
{
    enemyAttack = (rand() % 4) + 1;
    playerHealth -= enemyAttack;
    cout << "\nYou have taken " << enemyAttack << " damage." << endl; //ff player says no, then they suffer damage anyway
}

cout << "\n**Your health status is " << playerHealth << " HP.**\n" << endl; //health status given after each turn

if (playerHealth <= 3)
{
    cout << playerName << ", you are critically hurt, you need to see a doctor soon!\n" << endl;
}

} while (playerTurns++ <= 5 && playerHealth > 0);

if (playerHealth <= 0)
{
    cout << "You've been killed...Oh, the humanity." << endl;
}
else
{
    cout << "After that battle, the alien fled." << " Great job in protecting yourself!" << endl;
    Sleep (4000);
    cout << "Now, on we go. We have a long way to go to find your comrades." << endl;
}

return 0;
}