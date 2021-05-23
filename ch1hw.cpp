#include <iostream>
#include <string>
using namespace std;

int main()
{
cout << "\nHello you seem new here, what is your name?\n" << endl;

// 1. Variables
string playerFirstname, playerLastname;

float wingPrice;
wingPrice = 6.99;

int wingNumber;
wingNumber = 10;

int choice;

string answer;

string enter;

// 6. cin
cin >> playerFirstname;
cin >> playerLastname;


// 8. constants
const int prizeNumber = 1000;

cout << "\nWell it's nice to meet you " << playerFirstname << " " << playerLastname << "!" << endl;

cout <<"\nPress E to continue.." << endl << endl;
cin >> enter; // 6. cin

cout << "\n~Welcome to Sauce Palace, your place for chicken wings!~" << endl;
cout << "We are having a deal right now on " << wingNumber << " wings for " << "$" << wingPrice << "!" << endl;

cout <<"\nPress E to continue.." << endl << endl;
cin >> enter; // 6. cin

cout << "\nNow what would you like to see? We have various sauce options for ordering." << endl;
cout << "Each sauce is different level of spiciness, we range from level 0 to level 5! We have:" << endl;
cout << "\n-Mild, Hot, Burning, Spitfire, and last but not least Lava!-\n" << endl;

cout <<"\nPress E to continue.." << endl << endl;
cin >> enter; // 6. cin

cout << "\nRemember, each sauce is spicier than the other, but I recommend to know your spice limits before ordering." << endl;

cout <<"\nPress E to continue..\n" << endl << endl;
cin >> enter; // 6. cin

cout << "\nNow, before you order, I would like to tell you congrats on being our " << prizeNumber << "th customer!" << endl;

cout <<"\nPress E to continue.." << endl << endl;
cin >> enter; // 6. cin

cout << "\nThis means that you get an extra wing and 1 dollar knocked off your final price!" << endl;

cout <<"\nPress E to continue.." << endl << endl;
cin >> enter; // 6. cin

cout << "\nAlright so what will your order be? Just input your preferred level numerically and I will take care of the rest.\n" << endl;

// 7. Enumerator
enum spiciness {Mild = 1, Hot, Burning, Spitfire, Lava};

cin >> choice; // 6. cin
switch (choice)
{
case Mild:
    cout << "\nMild is very tasty sauce, great choice!" << endl;
    break;
case Hot:
    cout << "\nLooks like someone wants a little spice in their life!" << endl;
    break;
case Burning:
    cout << "\nAh, Burning, I always recommend this one for our casual spice fans." << endl;
    break;
case Spitfire:
    cout << "\nThis is pretty intense, my advice is that you just breathe through the pain." << endl;
    break;
case Lava:
    cout << "\nWow! It isn't very often someone orders that props to you for being brave." << endl;
    break;

default:
    cout << "I'm sorry, I didn't quite understand you." << endl;
}

// 3. Increment Operator
int extraWing;
extraWing = ++wingNumber;

// 4. Decrement Operator
float discountPrice;
discountPrice = --wingPrice;

cout << "That will be $" << discountPrice << " for " << extraWing << " wings!" << endl;
cout << "\nPay " << discountPrice << "?" << endl;
cout << "\nYes or no?\n" << endl;

cin >> answer; // 6. cin

bool check; // 1. Variables
if (answer == "Yes")
{
    cout << "\nThank you, here is your food!\n" << endl;
    check = true;

int donation; // 1. Variables
donation = 7 % 3; // 2. Modulus operator

float points = 0; // 1. Variables
points += discountPrice * 10; // 5. Combined Assignment Operator

cout << "The amount of " << donation << " dollar from your payment has been donated to charity, you have also gained " << points << " points through buying from us today." << endl;

points -= discountPrice + 51.91; // 5. Combined Assignment Operator

cout << "You will be able to use that for discounts like a $" << points << " drink for free!" << endl;
cout << "\nThank you for shopping with us today and enjoy your wings!" <<  endl;
}
else
{
    cout << "Sorry that is not enough money, please pay the correct amount." << endl;
    check = false;
}

return 0;

}
