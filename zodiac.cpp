#include <iostream>
#include <string>
#include <Windows.h>
#include <stdlib.h>
using namespace std;

void zodiacintro();

int month, date; //global variables for the month and date number

void zodiac_sign(int month, int date)
{
    zodiacintro();

    string astro_sign = "";
	
    cout << "\n- Enter your numerical month: \n"; 
    cin >> month; 

    cout << "\n- Enter your numerical date: "; 
    cin >> date; 

	// checks month and date within the valid range of a specified zodiac

	if (month == 1)
    {
		if (date < 20)
		astro_sign = "Capricorn";

		else
		astro_sign = "Aquarius";
	}
		
	else if (month == 2)
    {
		if (date < 19)
		astro_sign = "Aquarius";

		else
		astro_sign = "Pisces";
	}
		
	else if(month == 3)
    {
		if (date < 21)
		astro_sign = "Pisces";

		else
		astro_sign = "Aries";
	}

	else if (month == 4)
    {
		if (date < 20)
		astro_sign = "Aries";

		else
		astro_sign = "Taurus";
	}
		
	else if (month == 5)
    {
		if (date < 21)
		astro_sign = "Taurus";

		else
		astro_sign = "Gemini";
	}
		
	else if( month == 6)
    {
		if (date < 21)
		astro_sign = "Gemini";

		else
		astro_sign = "Cancer";
	}
		
	else if (month == 7)
    {
		if (date < 23)
		astro_sign = "Cancer";

		else
		astro_sign = "Leo";
	}
		
	else if( month == 8)
    {
		if (date < 23)
		astro_sign = "Leo";

		else
		astro_sign = "Virgo";
	}
		
	else if (month == 9)
    {
		if (date < 23)
		astro_sign = "Virgo";
		else
		astro_sign = "Libra";
	}
		
	else if (month == 10)
    {
		if (date < 23)
		astro_sign = "Libra";
		else
		astro_sign = "Scorpio";
	}
		
	else if (month == 11)
    {
		if (date < 22)
		astro_sign = "Scorpio";

		else
		astro_sign = "Sagittarius";
	}

    else if (month == 12)
    {
		if (date < 22)
		astro_sign = "Sagittarius";

		else
		astro_sign = "Capricorn";
	}
    else
    {
        cout << "\n- I'm sorry, that is an invalid input." << endl;
        cout << "- Please, restart the program and try again.\n" << endl; 

        exit(1); //full stop
    }
		
	cout << "Your zodiac sign is " << astro_sign << "!";
}

int main() 
{
    //this is establishing the month and date numbers
    zodiac_sign(month, date);
    
    exit( 1 ); //exit code for the loops who need to not move forward
    return 1;
}

void zodiacintro() //prompts the intro
{
    //----------------------------------------------------------------------------

    cout << "\n- Hello, would you like to know your ~zodiac sign?~ (Please type: Yes/No)" << endl;
    
    string zodiacAnswer; //original answer
    cin >> zodiacAnswer;

    //----------------------------------------------------------------------------

    if (zodiacAnswer == "Yes" || zodiacAnswer == "yes" || zodiacAnswer == "YES") //if yes then 
    {
        cout << "\n- Alright! -> " << zodiacAnswer  << " <- is a good answer!\n";
        Sleep (2000);
        cout << "\n- I need you to tell me the month and day that your birthday falls on"; 
        Sleep (1000); cout << "."; Sleep (1000); cout << "."; Sleep (1000); cout << ".";

    }
    
    //----------------------------------------------------------------------------

    else if (zodiacAnswer == "No" || zodiacAnswer == "no" || zodiacAnswer == "NO") //if no then
    {
        cout << "\n- Oh, okay then :(" << endl;
        Sleep (2000);
        cout << "\n- Are you sure? It will be really quick and fun, what do you say?\n" << endl; //maybe the player changed their mind?

        string sureAnswer; //their answer to give if they changed their mind
        cin >> sureAnswer;

        if (sureAnswer == "yes" || sureAnswer == "Yes"|| sureAnswer == "YES") //if mind has been changed
        {
            cout << "\n- Okay, great!" << endl;
            
                Sleep (2000);
                cout << "\n- I need you to tell me the month and day that your birthday falls on"; 
                Sleep (1000); cout << "."; Sleep (1000); cout << "."; Sleep (1000); cout << ".";

        }

        else if (sureAnswer == "no" || sureAnswer == "No"|| sureAnswer == "NO") //if mind has not been changed
        {
            cout << "\n- Alright then, bye forever." << endl;

            exit(1); //full stop 
        }

        else //if they mistype yes or no
        {
            cout << "\n- I'm sorry, I didn't understand what you said. Maybe I should ask you again." << endl;
            cout << "\n- Are you sure that you don't want your zodiac sign?" << endl;
            
            string firstagain; //gives them a chance to retype

	        do
            {
                cin >> firstagain;

                if (firstagain == "yes" || firstagain == "Yes" || firstagain == "YES") //if they are sure, loop breaks and game ends once and for all
                {
                    cout << "\n- Ah, finally a straight answer! Thank you for that, goodbye.\n" << endl; //if yes, Yes, or YES is successfully typed, game signals end.
                    
                    exit(1); //full stop
                }

                else if (firstagain == "no" || firstagain == "No" || firstagain == "NO") //if for some reason 'unsure' the computer gets puzzled
                {
                    cout << "\n- H-how are you NOT sure?\n" << endl;
                    Sleep (1000); cout << "- ."; Sleep (1000); cout << "."; Sleep (1000); cout << ".";
                    cout << "I don't understand.\n" << endl;
                }

                else //the loop continues if player continuously mistypes
                {
                    cout << "\n- What? " << "'" << firstagain << "'" << "?\n" << "\n- Are you sure you don't want your zodiac sign?\n" << endl;
                }

            } while (firstagain != "no" || firstagain != "No" || firstagain != "NO"); //all happening in a loop while the answers don't = no, No, or NO

        }   

    }

    //----------------------------------------------------------------------------

    else
    {
        cout << "\n- I am SO sorry what did you say?\n" << endl; //the event that someone mistypes yes or no in the very beginning.

        string secondagain;

        do
        {
            cin >> secondagain;

            if (secondagain == "yes" || secondagain == "Yes" || secondagain == "YES") //if yes, loop breaks
            {
                cout << "\n- Alright! -> " << secondagain  << " <- is a good answer!\n"; //from yes, Yes, or YES answer. Computer continues on 
                    
                Sleep (2000);
                cout << "\n- I need you to tell me the month and day that your birthday falls on"; 
                Sleep (1000); cout << "."; Sleep (1000); cout << "."; Sleep (1000); cout << ".";
                break;
            }

            else if (secondagain == "no" || secondagain == "No" || secondagain == "NO") //if no, loop breaks and game ends
            {
                cout << "\nOh, okay then. Goodbye!\n" << endl;
                
                exit(1); //full stop
            }

            else
            {
                cout << "\n- I am SO sorry what did you say?\n" << endl; //if they continuously mistype the computer must continue to ask
            }

        } while (secondagain != "no" || secondagain != "No" || secondagain != "NO");    
    }
    //----------------------------------------------------------------------------
}

/* STAR SIGN DATES :

Aries (March 21-April 19)
Taurus (April 20-May 20)
Gemini (May 21-June 20)
Cancer (June 21-July 22)
Leo (July 23-August 22)
Virgo (August 23-September 22)
Libra (September 23-October 22)
Scorpio (October 23-November 21)
Sagittarius (November 22-December 21)
Capricorn (December 22-January 19)
Aquarius (January 20-February 18)
Pisces (February 19-March 20) */