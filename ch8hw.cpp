#include <iostream>
using namespace std;

//class definition of Critter
class Critter
{
public:
    //constructor prototype
    Critter(int hunger = 0, int boredom = 0);
    
    //public member function prototypes
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 5);
   
    //a function that gets the exact value of data members Hunger and Boredom
    void GetHunger_Boredom();
    
private:
    //data members
    //independent hunger and boredom levels
    int m_Hunger; 
    int m_Boredom; 
    
    //private member function that that calculates the critter's mood
    int GetMood() const;

    //private member function that simulates the passage of time
    void PassTime(int time = 1); 
};

//constructor definition
Critter::Critter(int hunger, int boredom):
    //m_Hunger and m_Boredom are initialized to hunger and boredom
    m_Hunger(hunger) , 
    m_Boredom(boredom)
{}

inline int Critter::GetMood() const
{
    return (m_Hunger + m_Boredom);
    //the return value represents the critter's mood. The mood gets worse as the number increases
}

void Critter::PassTime(int time)
{
    m_Hunger += time;
    m_Boredom += time;
    //the critter's hunger and boredom levels increase by the amount of time has passed, by 1
}

void Critter::Talk() //critter mention's how hungry it is and how it is feeling overall
{
    cout << "\nI'm a critter and I feel ";
    int mood = GetMood(); //GetMood() is called for the critter
    int hungry = m_Hunger; //hungry is initialized to m_Hunger and grabs that value from it
    
    if (mood > 15)
    {
        cout << "mad.\n";
        
        if (hungry > 6) //nested if statement has critter give a responce if its hunger level is above 6
        {
            cout << "I am starving!\n";
        }
    }
    else if (mood > 10)
    {
        cout << "frustrated.\n";
        
        if (hungry > 4) //nested if statement that serves the same purpose as above
        {
            cout << "I am very hungry!\n";
        }
    }
    else if (mood > 5)
    {
        cout << "okay.\n";
        
        if (hungry > 3) //nested if statement that is the same purpose as above
        {
            cout << "I am a little bit hungry.\n";
        }
    }
    else
    {
        cout << "happy.\n";

        if (hungry < 2) //if the critter's hunger level is under 2, then it isn't feeling hungry
        {
            cout << "I am not feeling hungry.\n";
        }
    }

    PassTime(); //PassTime() is called to simulate the passage of time 
}

void Critter::Eat(int food)
{
    cout << "Brruppp,\n";
    
    //hunger level is reduced by the amount passed to parameter food
    m_Hunger -= food;

    //ensures that the critter's hunger level does not go below zero
    if (m_Hunger < 0)
    {
        m_Hunger = 0;
    }

    PassTime(); //PassTime() is called to simulate the passage of time
}

void Critter::Play(int fun)
{
    cout << "Wheee!\n";

    //boredom level is reduced by the amount passed to parameter fun
    m_Boredom -= fun;

    //ensures that the critter's boredom level doesn't go below zero
    if (m_Boredom < 0)
    {
        m_Boredom = 0;
    }

    PassTime(); //PassTime() is called to simulate the passage of time
}

void Critter::GetHunger_Boredom()
{
    cout << "\n*The hunger level of the critter is: " << m_Hunger << "*\n";
    cout << "*The boredom level of the critter is: " << m_Boredom << "*\n";
}

int main()
{
    Critter crit; //a new critter object is instantiated
    crit.Talk(); //calls crit Talk() member function

    int choice;
    do
    {
        cout << "\n-Critter Caretaker Menu-\n\n";
        cout << "0 - Quit\n";
        cout << "1 - Listen to your critter\n";
        cout << "2 - Feed your critter\n";
        cout << "3 - Play with your critter\n";

        cout << "\nChoice: ";
        cin >> choice;

        switch(choice)
        {
            case 0:
                cout << "Good-bye.\n";
                break;
            case 1:
                crit.Talk();
                break;
            case 2:
                crit.Eat();
                break;
            case 3:
                crit.Play();
                break;
            case 4:
                //the unlisted option to see the exact value of m_Hunger and m_Boredom
                crit.GetHunger_Boredom(); 
                break;
            default:
                cout << "\nSorry, but " << choice << " isn't a valid choice.\n";              
        }
    } while (choice != 0);

    return 0;
}