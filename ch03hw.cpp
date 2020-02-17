#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

int main()
{
    const int MAX_ITEMS = 10;
    string inventory[MAX_ITEMS];

    int backpackItems = 0;
    inventory[backpackItems++] = "Spellbook";
    inventory[backpackItems++] = "TownMap";
    inventory[backpackItems++] = "Cookies";
 
    Sleep (2000);
    cout << "\n\t\t*~Welcome to the town of Bluecastle!~*\n\n";
    Sleep (2000);
    cout << "You are a new student beginning to attend Bluecastle high school." << endl;
    Sleep (3000);
    cout << "Your 17th birthday had just passed and lately you have noticed some...strange things." << endl;
    Sleep (3000);
    cout << "You found yourself able to turn objects into other things, such as turning a book into a pizza.\n" << endl;
    Sleep (3000);
    cout << "You have to admit, the power was fun for a while, until you found out how to levitate objects." << endl;
    Sleep (3000);
    cout << "Your parents weren't so happy with the dog being stuck 10 feet in the air, but things worked out." << endl;
    Sleep (3000);
    cout << "They are proud to see that your powers have finally come in, and after that fiasco, " << endl;
    Sleep (3000);
    cout << "they sat you down and explained to you who you are..." << endl;
    Sleep (4000);
    cout << "\nYou are a witch!" << endl;
    Sleep (2000);

    cout << "\nNow, before we begin let's start with your name, what is your name?" << endl;
    
    string witchName;
    cin >> witchName;

    cout << "\nGreat! " << witchName << ", what an interesting name." << endl;
    Sleep (2000);
    cout << "\nToday is the morning of your first day at Bluecastle high." << endl;
    Sleep (3000);
    cout << "Your backpack is right by the front door and as you wave goodbye to your parents, you grab that and walk out of the door." << endl;
    Sleep (3000);
    cout << "School is pretty far away from here, looks like getting to school will be a bit of an adventure." << endl;
    cout << "\n-Before you begin walking, you look inside your backpack.-" << endl;

    Sleep (5000);
    cout << "\nYour backpack contains: " << endl;
    for (int i = 0; i < backpackItems; ++i)
    {
        cout << i + 1 << ". " << inventory[i] << endl;
    }

    Sleep (5000);
    cout << "\nThe map looks like a nice choice to look at right now. Grab the map from the protective sling that it's being held in." << endl;
    Sleep (5000);

    inventory [1] = "EmptyMapSling";

    cout << "\n-You grab the map.-\n" << endl;
    Sleep (2000);

    cout << "Your inventory is now: " << endl;
    for (int i = 0; i < backpackItems; ++i)
    {
        if (inventory[i] != "")
        {
            cout << i + 1 << ". " << inventory[i] << endl;
        } 
    }

    Sleep (3000);
    cout << "\nAfter looking at the map you see that you must turn right on this street and follow a trail of bushes." << endl;
    Sleep (3000);
    cout << "\n-You turn right and begin following the trail of bushes.-\n" << endl;
    Sleep (3000);
    cout << "You approach great old oak tree on the opposite side of the trail of bushes. Looking up at it, you see it towers above almost every tree around." << endl;
    Sleep (3000);
    cout << "There is an interesting hole in the tree, there seems to be something glimmering in the hole." << endl;
    Sleep (3000);
    cout << "\n-You reach up and pick out the item from the hole in the tree.-" << endl;
    Sleep (3000);
    cout << "\nIt is a silver and blue pen! This looks very expensive, I wonder who would leave this here?\n" << endl;
    Sleep (3000);
    cout << "What would you like to name the pen? The name must one word, en example would be like: MysteriousPen." << endl;
    
    cin >> inventory[backpackItems++];

    Sleep (3000);
    cout << "\nYour inventory is now: " << endl;
    for (int i = 0; i < backpackItems; ++i)
    {
        if (inventory[i] != "")
        {
            cout << i + 1 << ". " << inventory[i] << endl;
        }
    }

    Sleep (4000);
    cout << "\nYou continue walking for a while after you encounter the mysterious tree." << endl; 
    Sleep (4000);
    cout << "The map takes you throughout this forest path and out into a more populated area." << endl;
    Sleep (3000);
    cout << "\nAs you leave the heavily forested area, you trip on something small!" << endl;
    Sleep (4000);
    cout << "That something happens to be a frog! He is very upset and has a lot to say!" << endl;
    Sleep (4000);
    cout << "\n-The frog: \"Hey watch where you are going you manic! You could have killed me!\"" << endl;
    Sleep (5000);
    cout << "\nWait, you understood what he said! The frog spoke! How is this possible? It takes you a bit to remember that you are a witch." << endl;
    Sleep (4000);
    cout << "You can understand animals. You do feel bad that you hurt the frog and say your apologies. The frog is surprised and relaxes a bit." << endl;
    Sleep (4000);
    cout << "\nThe frog decides that you are trustworthy, only witches can understand animals." << endl;
    Sleep (3000);
    cout << "\n-The frog: \"Will you take me with you? It is very lonely in the wild and I am looking for a friend.\"" << endl;
    Sleep (3000);
    cout << "\nWell isn't this an interesting day? You oblige and pick the frog up.\n" << endl;
    Sleep (3000);
    cout << "It appears he doesn't have a name, what is his name?" << endl;
    
    cin >> inventory[backpackItems++];
   
    Sleep (2000);
    cout << "\nYour inventory is now: " << endl;
    for (int i = 0; i < backpackItems; ++i)
    {
        if (inventory[i] != "")
        {
            cout << i + 1 << ". " << inventory[i] << endl;
        }
    }

    Sleep (4000);
    cout << "\nYou now have a new companion tucked safely in your backpack." << endl;
    Sleep (4000);
    cout << "Frog care isn't too complicated and it's nice to have someone to talk to about witchery." << endl;
    Sleep (4000);  
    cout << "\nAfter the run in with the forest amphibian, you continue to follow the map. The town of Bluecastle sure is large." << endl;
    Sleep (4000);
    cout << "It has been quite a while since you left. Good thing that you set out an hour early so you won't be late for school." << endl;
    Sleep (4000);
    cout << "\nThe map takes you into an area where food vendors are out selling their product." << endl;
    Sleep (4000);
    cout << "The aroma of the delicious burgers and barbeque caused you to grow hungry!" << endl;
    Sleep (4000);
    cout << "Thankfully you rememberd the snack you left in your backpack." << endl;
    Sleep (3000);
    cout << "\nWhat would you like to search for in your backpack?" << endl;
    
    string playerInput;
    cin >> playerInput;

    if(inventory[2] == playerInput || playerInput == "cookies")
        {
            Sleep (2000);
            cout << "\nYou have selected " << playerInput << "!" << endl;
            Sleep (3000);
            cout << "You eat the " << playerInput << " and savor the taste of them!" << endl;
            Sleep (3000);
            cout << "\nNow, you have more energy to go on, you must finish this little adventure." << endl;
            inventory [2] = "";
        }
        else
        {
            cout << "\nOh so you decided to do nothing. It's no problem let's continue on." << endl;
        }

    cout << "\nHere is your inventory now: " << endl;
    for (int i = 0; i < backpackItems; i++)
    {
        if (inventory[i] != "")
        {
            cout << i + 1 << ". " << inventory[i] << endl;
        }
    }

    Sleep (4000);
    cout << "\nAlright, let's see what is left on this route to the high school." << endl;
    Sleep (4000);
    cout << "The map states that school is only a bit past downtown Bluecastle, and then you have to turn left at the bronze statue." << endl; 
    Sleep (3000);
    cout << "\n-You follow the directions and find yourself being suddenly hit in the head!-\n" << endl;
    Sleep (3000);
    cout << "Ouch, what was that? You hear a shrill voice say, \"Heads up bud,\" and you look up and see a black crow flying overhead." << endl;
    Sleep (5000);
    cout << "A peculiar rock bounced on to the ground by your feet, it is glimmering and the colors seem to change every few seconds." << endl;
    Sleep (3000);
    cout << "This doesn't seem coincidental." << endl;
    Sleep (4000);
    cout << "\n-You pick up the rock and notice that it's carved into a specific shape. Weird." << endl;
    Sleep (3000);
    cout << "\nWould you like to name this rock?" << endl;

    cin >> inventory[backpackItems++];

    Sleep (2000);
    cout << "\nYour inventory is now: " << endl;
    for (int i = 0; i < backpackItems; ++i)
    {
        if (inventory[i] != "")
        {
            cout << i + 1 << ". " << inventory[i] << endl;
        }
    }

    Sleep (4000);
    cout << "\nYour head hurts only a little bit, but you know that you must continue on. The first day of school is always important." << endl;
    Sleep (4000);
    cout << "You look around and see your high school with busses of kids piled up inside them. Everyone looks just as bored as the next." << endl;
    Sleep (3000);
    cout << "\nSince you now know where your school is, you could put the map back in your backpack." << endl;
    Sleep (3000);
    cout << "\n-You place the map back inside its protective sling.-" << endl;
    
    inventory [1] = "TownMap";

    Sleep (2000);
    cout << "\nYour inventory is now: " << endl;
    for (int i = 0; i < backpackItems; ++i)
    {
        if (inventory[i] != "")
        {
            cout << i + 1 << ". " << inventory[i] << endl;
        }
    }

    Sleep (3000);
    cout << "\nAs you walk towards the school, you notice a menacing person walking toward you...Uh oh." << endl;
    Sleep (4000);
    cout << "They look large, as if they were over 6ft tall. Their face is hidden by the dark hood over their head." << endl;
    Sleep (3000);
    cout << "\nYou wonder why bullies exist and how you can get out of this situation. Think, " << witchName << "." << endl;
    Sleep (6000);
    cout << "\n-The bully: \"Hey loser, you look new here, there's a policy in Bluecastle for newbies. You know what that is?\"" << endl;
    Sleep (4000);
    cout << "\nYou don't reply, maybe they will get bored." << endl;
    Sleep (5000);
    cout << "\n-Bully: \"I'm talking to you kid! You need to give up something in order to come in, or else you will get a bad beat-down. You get what I'm sayin'?\"" << endl;
    Sleep (6000);
    cout << "\nThis is a very difficult decision, what is there to give up? You don't want your first day to end in you getting hurt." << endl;
    Sleep (4000);
    cout << "This first day is starting off rather unfortunate." << endl;
    Sleep (3000);
    cout << "\nWhat would you be willing to give up?" << endl;
    Sleep (3000);
    cout << "\nWhat would you like to search for in your backpack?" << endl;

    string playerInput2;
    cin >> playerInput2;

    for (int i = 0; i < backpackItems; ++i)
    {
        if(inventory[i] == playerInput2)
        {
            Sleep (2000);
            cout << "\nYou have selected " << playerInput2 << "." << endl;
            Sleep (2000);
            cout << "\nYou hand over " << playerInput2 << " and avert your eyes away from the bully." << endl;
            inventory [i] = "";
        }
    }
    for (int i = 0; i < backpackItems; i++)
    {
        if (inventory[i] != "")
        {
            cout << i + 1 << ". " << inventory[i] << endl;
        }
    }

    Sleep (3000);
    cout << "\nThe greasy bully snatches the " << playerInput2 << " out of your hands and leers down at it." << endl;
    Sleep (3000);
    cout << "\n-Bully: \"Thanks loser, remember who I am, you don't want to cross me.\"\n" << endl;
    Sleep (5000);
    cout << "You roll your eyes and push by the large person. You look down at your watch and thankfully see that you are on time." << endl;
    Sleep (4000);
    cout << "That sitaution wasn't very fun but thankfully you can practice your newfound powers throughout this school year." << endl;
    Sleep (5000);
    cout << "\nMaybe you can think of a plan to get the bully back for what they did. As you enter the school you are already pondering ideas." << endl;
    Sleep (6000);
    cout << "A smile inches onto your face when you remember that after school your parents mentioned giving you resources to other witches in the community that could help in any way." << endl; 
    Sleep (4000);
    cout << "\nMaybe all of the trouble was worth it." << endl;

return 0;
}