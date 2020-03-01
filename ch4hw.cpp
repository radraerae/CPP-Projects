#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
using namespace std;

int main()
{

    vector<string> names;
    names.push_back("Jesse"); //elements in the vector
    names.push_back("Walter");
    names.push_back("Saul");
    names.push_back("Skyler");
    names.push_back("Gustavo");
    names.push_back("Mike");

    vector<string> :: iterator changeIter; //iterator that can change an element's value
    vector<string> :: const_iterator readIter; //the safer constant iterator that will be used in the for loops and cout
    string playerInput; //the players input choice for what they want to do
    
    string changeInput; //change option 
    string changenameInput; //the option for what they want to change the old name to
   
    string addInput; //add a name option

    string removeInput; //remove a name option

    Sleep (2000);
    cout << "\nHere is a list of some interesting names:" << endl; //first list of names
    for (readIter = names.begin(); readIter != names.end(); ++readIter)
    {
        cout << "- " << *readIter << endl;
    }

    do
    {
        Sleep (2000);
        cout << "\n.:With this list of " << names.size() << " names, you can do many things:." << endl;
        Sleep (2000);
        cout << "You are able to: add names, change a name, remove a name, and list them again!\n" << endl;
        Sleep (2000);
        cout << "To add a name please type: \"Add.\"\nTo change a name please type: \"Change.\"\nTo remove a name please type: \"Remove.\"\nTo list the names please type: \"List\"\n" << endl;
        Sleep (2000);
        cout << "You have a choice to quit this activity as well. If you want to quit, please type: \"Quit.\"\n" << endl;

        cin >> playerInput;
        
        if (playerInput == "Add" || playerInput == "add")
        {
            Sleep (2000);
            cout << "\nOkay, what name would you like to add?" << endl;
            cin >> addInput; //the name the player wants to add
            
            names.insert(names.begin(), addInput); //inserts the name to the beginning of the list
            
            Sleep (2000);
            cout << "\nYou have selected to add " << addInput << " to the list.\n" << endl;
            
            Sleep (2000);
            cout << "Here is the list of names now:" << endl;
            for (readIter = names.begin(); readIter != names.end(); ++readIter) //lists the names
            {
                cout << "- " << *readIter << endl;
            }
        }
        else if (playerInput == "Change" || playerInput == "change")
        {
            Sleep (2000);
            cout << "\nWhat name would you like to change?\n" << endl;
            cin >> changeInput; //the name in the vector they want to change
            
            changeIter = find(names.begin(), names.end(), changeInput); //this finds the name they input
            
            for (readIter = names.begin(); readIter != names.end(); ++readIter) //this is a for loop for the finding of that name in the list
            {
                if (*changeIter == changeInput) //inside the loop the if statement tests if the readIter matches what the changeiter is finding
                {
                    Sleep (2000);
                    cout << "\nFound the name!\n" << endl;
                    Sleep (2000);
                    cout << "Okay what would you like to change " << changeInput << " to?\n" << endl;
                    cin >> changenameInput; //the new name for the old name they selected to change 
                   
                    *changeIter = changenameInput; //the changeIter equals the input for the new name
                    Sleep (2000);
                    cout << "You have chosen to change " << changeInput << " to " << changenameInput << ".\n" << endl;
                }   
            }
            if (*changeIter != changenameInput) //I took the 
            {
                Sleep (2000);
                cout << "\nI'm sorry, no name was found." << endl;
            }

            Sleep (2000);
            cout << "Here is the list of names:" << endl;
            for (readIter = names.begin(); readIter != names.end(); ++readIter)
            {
                cout << "- " << *readIter << endl;
            }
        }
        else if (playerInput == "Remove" || playerInput == "remove")
        {
            Sleep (2000);
            cout << "\nAlright, what name would you like to remove?\n" << endl;
            cin >> removeInput; //selects the name they would like to remove
            
            changeIter = find(names.begin(), names.end(), removeInput);
            if (changeIter != names.end())
            {
                names.erase(changeIter);
                Sleep (2000);
                cout << "\nOkay, you have selected to remove " << removeInput << "." << endl;
            }

            Sleep (2000);
            cout << "\nHere is the list now:" << endl;
            for (readIter = names.begin(); readIter != names.end(); ++readIter)
            {
                cout << "- " << *readIter << endl;
            }    
        }
        else if (playerInput == "List" || playerInput == "list")
        {
            Sleep (2000);
            cout << "\nYou have selected to " << playerInput << " the names out.\n" << endl; 
            Sleep (2000);
            cout << "Here is the list of names:" << endl;
            for (readIter = names.begin(); readIter != names.end(); ++readIter)
            {
                cout << "- " << *readIter << endl;
            }    
        }
        else if (playerInput == "Quit" || playerInput == "quit")
        {
            Sleep (2000);
            cout << "\n>You have selected to " << playerInput << ". Goodbye!<" << endl;
            break;
        }
        else 
        {
            Sleep (1000);
            cout << "That isn't an option!" << endl;
        }

    } while (playerInput != "Quit" || playerInput != "quit");

    Sleep (2000);
    cout << "\nThank you for participating! Have a nice day." << endl;
    
return 0;
}



