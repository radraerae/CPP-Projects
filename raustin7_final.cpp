#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
//---------------------------------------------------------------------

enum en_DIRS {NORTH, EAST, SOUTH, WEST};

enum en_ROOMS 
{DININGHALL, OFFICE, INFIRMARY, RECCENTER, COUNSELORLODGE, NORTHWESTPATH, SHOP, 
GIRLSCABIN, BOYSCABIN, LAKE, ARCHERY, WESTPATH, SOUTHWESTPATH, SOUTHEASTPATH, 
NORTHEASTHALL, BOYSHALLWAY, MENSRESTROOM, WOMENSRESTROOM, SOUTHPATH, LAKESUPPLIES, 
GARDEN, LIFEGUARDHUT, BOYSSHOWER, GIRLSSHOWER, MAILHOUSE, FLAGPOLE, ARTHOUSE, LAUNDRYHOUSE, 
PICNICAREA, BONFIRE, DOCK, BACKPACK /*backpack is a room for inventory*/};

enum en_VERBS {GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK, COMBINE, EAT,}; //combine and use not enabled

enum en_NOUNS {SHOP_DOOR, CHIPS, STETHOSCOPE, FOUNATAIN_PEN, GYMBAG, LADLE, 
FLASHLIGHT, COOKIES, LIFEJACKET, BOAT, WARMCOAT, LIPSTICK, SCISSORS, PAPER, 
COMPASS, SHOVEL, BATTERIES};
//--------------------------------------------------------------------

//bool debug = true; 
//debug is used throughout the code to find any possilbe issues in certain places

const int NONE = -1;

const int DIRS = 4; 

const int ROOMS = 32; //over 30 rooms

const int VERBS = 10; //+2 verbs

const int NOUNS = 17; //over 15 nouns
//--------------------------------------------------------------------

class words //words is a class
{
    public: //public data members 
    string word;
    int code;

    //no data members can be private as they would be inaccessable 
};

class room //room is a class
{
    public: //public data members 
    string description;
    int exits_to_room[DIRS];

    //no data members can be private as they would be inaccessable 
};

class noun //noun is a class
{
    public: //public data members 
    string word;
    string description;
    int code;
    int location;
    bool can_carry;
    string examination;
    
    //no data members can be private as they would be inaccessable 
};
//---------------------------------------------------------

void set_rooms(room *rms)
{
    rms[COUNSELORLODGE].description.assign("in the counselor lodge");
    rms[COUNSELORLODGE].exits_to_room[NORTH] = NONE;
    rms[COUNSELORLODGE].exits_to_room[EAST] = NORTHWESTPATH;
    rms[COUNSELORLODGE].exits_to_room[SOUTH] = WESTPATH;
    rms[COUNSELORLODGE].exits_to_room[WEST] = NONE;
    
    rms[WESTPATH].description.assign("on a dark dirt path");
    rms[WESTPATH].exits_to_room[NORTH] = COUNSELORLODGE;
    rms[WESTPATH].exits_to_room[EAST] = NONE;
    rms[WESTPATH].exits_to_room[SOUTH] = NONE;
    rms[WESTPATH].exits_to_room[WEST] = NONE;

    rms[SHOP].description.assign("in the shop room");
    rms[SHOP].exits_to_room[NORTH] = NONE;
    rms[SHOP].exits_to_room[EAST] = SOUTHWESTPATH;
    rms[SHOP].exits_to_room[SOUTH]  = SOUTHPATH;
    rms[SHOP].exits_to_room[WEST] = NONE;

    rms[SOUTHWESTPATH].description.assign("on a lonely dirt path");
    rms[SOUTHWESTPATH].exits_to_room[NORTH] = NONE;
    rms[SOUTHWESTPATH].exits_to_room[EAST] = SHOP;
    rms[SOUTHWESTPATH].exits_to_room[SOUTH] = NONE;
    rms[SOUTHWESTPATH].exits_to_room[WEST] = ARCHERY;

    rms[ARCHERY].description.assign("in a archery field");
    rms[ARCHERY].exits_to_room[NORTH] = NONE;
    rms[ARCHERY].exits_to_room[EAST] = SOUTHEASTPATH;
    rms[ARCHERY].exits_to_room[SOUTH] = NONE;
    rms[ARCHERY].exits_to_room[WEST] = SOUTHWESTPATH;

    rms[SOUTHEASTPATH].description.assign("on a forboding dirt path");
    rms[SOUTHEASTPATH].exits_to_room[NORTH] = NONE;
    rms[SOUTHEASTPATH].exits_to_room[EAST] = NONE;
    rms[SOUTHEASTPATH].exits_to_room[SOUTH] = DOCK;
    rms[SOUTHEASTPATH].exits_to_room[WEST] = ARCHERY;

    rms[DOCK].description.assign("on a dock, near a bottomless lake");
    rms[DOCK].exits_to_room[NORTH] = SOUTHEASTPATH;
    rms[DOCK].exits_to_room[EAST] = LAKE;
    rms[DOCK].exits_to_room[SOUTH] = LAKE;
    rms[DOCK].exits_to_room[WEST] = LAKE;

    rms[LAKE].description.assign("in a bottomless lake, it is very cold");
    rms[LAKE].exits_to_room[NORTH] = DOCK;
    rms[LAKE].exits_to_room[EAST] = NONE;
    rms[LAKE].exits_to_room[SOUTH] = NONE;
    rms[LAKE].exits_to_room[WEST] = NONE;

    rms[SOUTHPATH].description.assign("on a secluded dirt path");
    rms[SOUTHPATH].exits_to_room[NORTH] = SHOP;
    rms[SOUTHPATH].exits_to_room[EAST] = LAKESUPPLIES;
    rms[SOUTHPATH].exits_to_room[SOUTH] = ARTHOUSE;
    rms[SOUTHPATH].exits_to_room[WEST] = MAILHOUSE;

    rms[ARTHOUSE].description.assign("in the art house");
    rms[ARTHOUSE].exits_to_room[NORTH] = SOUTHPATH;
    rms[ARTHOUSE].exits_to_room[EAST] = NONE;
    rms[ARTHOUSE].exits_to_room[SOUTH] = NONE;
    rms[ARTHOUSE].exits_to_room[WEST] = NONE;

    rms[MAILHOUSE].description.assign("in the mail house");
    rms[MAILHOUSE].exits_to_room[NORTH] = NONE;
    rms[MAILHOUSE].exits_to_room[EAST] = SOUTHPATH;
    rms[MAILHOUSE].exits_to_room[SOUTH] = NONE;
    rms[MAILHOUSE].exits_to_room[WEST] = NONE;

    rms[LAKESUPPLIES].description.assign("in the lake supplies house");
    rms[LAKESUPPLIES].exits_to_room[NORTH] = GARDEN;
    rms[LAKESUPPLIES].exits_to_room[EAST] = NONE;
    rms[LAKESUPPLIES].exits_to_room[SOUTH] = NONE;
    rms[LAKESUPPLIES].exits_to_room[WEST] = SOUTHPATH;

    rms[GARDEN].description.assign("in a tranquil garden"); 
    rms[GARDEN].exits_to_room[NORTH] = NONE;
    rms[GARDEN].exits_to_room[EAST] = LIFEGUARDHUT;
    rms[GARDEN].exits_to_room[SOUTH] = LAKESUPPLIES;
    rms[GARDEN].exits_to_room[WEST] = NONE;

    rms[LIFEGUARDHUT].description.assign("in the lifeguard hut");
    rms[LIFEGUARDHUT].exits_to_room[NORTH] = NONE;
    rms[LIFEGUARDHUT].exits_to_room[EAST] = NONE;
    rms[LIFEGUARDHUT].exits_to_room[SOUTH] = NONE;
    rms[LIFEGUARDHUT].exits_to_room[WEST] = GARDEN;

    rms[NORTHWESTPATH].description.assign("on a long dirt path");
    rms[NORTHWESTPATH].exits_to_room[NORTH] = NONE;
    rms[NORTHWESTPATH].exits_to_room[EAST] = OFFICE;
    rms[NORTHWESTPATH].exits_to_room[SOUTH] = NONE;
    rms[NORTHWESTPATH].exits_to_room[WEST] = COUNSELORLODGE; 

    rms[OFFICE].description.assign("in a desolate office");
    rms[OFFICE].exits_to_room[NORTH] = FLAGPOLE;
    rms[OFFICE].exits_to_room[EAST] = DININGHALL;
    rms[OFFICE].exits_to_room[SOUTH] = NONE;
    rms[OFFICE].exits_to_room[WEST] = NORTHWESTPATH;    

    rms[FLAGPOLE].description.assign("near the flagpole");
    rms[FLAGPOLE].exits_to_room[NORTH] = NONE;
    rms[FLAGPOLE].exits_to_room[EAST] = NONE;
    rms[FLAGPOLE].exits_to_room[SOUTH] = OFFICE;
    rms[FLAGPOLE].exits_to_room[WEST] = NONE;

    rms[DININGHALL].description.assign("in the dining hall");
    rms[DININGHALL].exits_to_room[NORTH] = NONE;
    rms[DININGHALL].exits_to_room[EAST] = NORTHEASTHALL; 
    rms[DININGHALL].exits_to_room[SOUTH] = INFIRMARY;
    rms[DININGHALL].exits_to_room[WEST] = OFFICE;

    rms[PICNICAREA].description.assign("near a picnic area");
    rms[PICNICAREA].exits_to_room[NORTH] = NONE;
    rms[PICNICAREA].exits_to_room[EAST] = BONFIRE;
    rms[PICNICAREA].exits_to_room[SOUTH] = DININGHALL;
    rms[PICNICAREA].exits_to_room[WEST] = NONE;

    rms[BONFIRE].description.assign("near a bonfire");
    rms[BONFIRE].exits_to_room[NORTH]= NONE;
    rms[BONFIRE].exits_to_room[EAST] = NONE;
    rms[BONFIRE].exits_to_room[SOUTH] = NONE;
    rms[BONFIRE].exits_to_room[WEST] = PICNICAREA;

    rms[NORTHEASTHALL].description.assign("in a hallway");
    rms[NORTHEASTHALL].exits_to_room[NORTH] = NONE;
    rms[NORTHEASTHALL].exits_to_room[EAST] = LAUNDRYHOUSE;
    rms[NORTHEASTHALL].exits_to_room[SOUTH] = RECCENTER;
    rms[NORTHEASTHALL].exits_to_room[WEST] = DININGHALL;

    rms[LAUNDRYHOUSE].description.assign("in the laundry house");
    rms[LAUNDRYHOUSE].exits_to_room[NORTH] = NONE;
    rms[LAUNDRYHOUSE].exits_to_room[EAST] = NONE;
    rms[LAUNDRYHOUSE].exits_to_room[SOUTH] = NONE;
    rms[LAUNDRYHOUSE].exits_to_room[WEST] = NORTHEASTHALL;

    rms[RECCENTER].description.assign("in the recreation center");
    rms[RECCENTER].exits_to_room[NORTH] = NORTHEASTHALL; 
    rms[RECCENTER].exits_to_room[EAST] = NONE;
    rms[RECCENTER].exits_to_room[SOUTH] = GIRLSCABIN;
    rms[RECCENTER].exits_to_room[WEST] = INFIRMARY;

    rms[GIRLSCABIN].description.assign("in the girls cabin");
    rms[GIRLSCABIN].exits_to_room[NORTH] = RECCENTER;
    rms[GIRLSCABIN].exits_to_room[EAST] = WOMENSRESTROOM;
    rms[GIRLSCABIN].exits_to_room[SOUTH] = NONE;
    rms[GIRLSCABIN].exits_to_room[WEST] = NONE;

    rms[WOMENSRESTROOM].description.assign("in the womens restroom");
    rms[WOMENSRESTROOM].exits_to_room[NORTH] = GIRLSSHOWER;
    rms[WOMENSRESTROOM].exits_to_room[EAST] = NONE;
    rms[WOMENSRESTROOM].exits_to_room[SOUTH] = NONE;
    rms[WOMENSRESTROOM].exits_to_room[WEST] = GIRLSCABIN;

    rms[GIRLSSHOWER].description.assign("in the girls shower");
    rms[GIRLSSHOWER].exits_to_room[NORTH] = NONE;
    rms[GIRLSSHOWER].exits_to_room[EAST] = NONE;
    rms[GIRLSSHOWER].exits_to_room[SOUTH] = WOMENSRESTROOM;
    rms[GIRLSSHOWER].exits_to_room[WEST] = NONE;

    rms[INFIRMARY].description.assign("in the infirmary");
    rms[INFIRMARY].exits_to_room[NORTH] = DININGHALL;
    rms[INFIRMARY].exits_to_room[EAST] = BOYSCABIN;
    rms[INFIRMARY].exits_to_room[SOUTH] = NONE;
    rms[INFIRMARY].exits_to_room[WEST] = RECCENTER;

    rms[BOYSCABIN].description.assign("in the boys cabin");
    rms[BOYSCABIN].exits_to_room[NORTH] = NONE;
    rms[BOYSCABIN].exits_to_room[EAST] = INFIRMARY;
    rms[BOYSCABIN].exits_to_room[SOUTH] = NONE;
    rms[BOYSCABIN].exits_to_room[WEST] = BOYSHALLWAY;

    rms[BOYSHALLWAY].description.assign("in the boys hallway");
    rms[BOYSHALLWAY].exits_to_room[NORTH] = MENSRESTROOM;
    rms[BOYSHALLWAY].exits_to_room[EAST] = BOYSCABIN;
    rms[BOYSHALLWAY].exits_to_room[SOUTH] = NONE;
    rms[BOYSHALLWAY].exits_to_room[WEST] = NONE;

    rms[MENSRESTROOM].description.assign("in the mens restroom");
    rms[MENSRESTROOM].exits_to_room[NORTH] = NONE;
    rms[MENSRESTROOM].exits_to_room[EAST] = BOYSSHOWER;
    rms[MENSRESTROOM].exits_to_room[SOUTH] = BOYSHALLWAY;
    rms[MENSRESTROOM].exits_to_room[WEST] = NONE;

    rms[BOYSSHOWER].description.assign("in the boys shower");
    rms[BOYSSHOWER].exits_to_room[NORTH] = NONE;
    rms[BOYSSHOWER].exits_to_room[EAST] = NONE;
    rms[BOYSSHOWER].exits_to_room[SOUTH] = NONE;
    rms[BOYSSHOWER].exits_to_room[WEST] = MENSRESTROOM; 

    rms[BACKPACK].description.assign("your inventory");
    rms[BACKPACK].exits_to_room[NORTH] = NONE;
    rms[BACKPACK].exits_to_room[EAST] = NONE;
    rms[BACKPACK].exits_to_room[SOUTH] = NONE;
    rms[BACKPACK].exits_to_room[WEST] = NONE;      
}
//---------------------------------------------------------

void set_directions(words *dir) 
{
    dir[NORTH].code = NORTH;
    dir[NORTH].word = "NORTH";
    
    dir[EAST].code = EAST;
    dir[EAST].word = "EAST";
    
    dir[SOUTH].code = SOUTH;
    dir[SOUTH].word = "SOUTH";
    
    dir[WEST].code = WEST;
    dir[WEST].word = "WEST";
}
//----------------------------------------------------------

void set_verbs(words *vbs) 
{
    vbs[GET].code = GET;
    vbs[GET].word = "GET";
    
    vbs[DROP].code = DROP;
    vbs[DROP].word = "DROP";
    
    vbs[USE].code = USE; //not activated
    vbs[USE].word = "USE";
    
    vbs[OPEN].code = OPEN;
    vbs[OPEN].word = "OPEN";
    
    vbs[CLOSE].code = CLOSE;
    vbs[CLOSE].word = "CLOSE";
    
    vbs[EXAMINE].code = EXAMINE;
    vbs[EXAMINE].word = "EXAMINE";
    
    vbs[INVENTORY].code = INVENTORY;
    vbs[INVENTORY].word = "INVENTORY";
    
    vbs[LOOK].code = LOOK;
    vbs[LOOK].word = "LOOK";

    vbs[EAT].code = EAT;
    vbs[EAT].word = "EAT";

    vbs[COMBINE].code = COMBINE; //not activated
    vbs[COMBINE].word = "COMBINE";
}
//---------------------------------------------------------

void set_nouns(noun *nns)
{
    nns[SHOP_DOOR].word = "DOOR";
    nns[SHOP_DOOR].code = SHOP_DOOR;
    nns[SHOP_DOOR].description = "a closed shop room door";
    nns[SHOP_DOOR].can_carry = false;
    nns[SHOP_DOOR].location = WESTPATH;
    nns[SHOP_DOOR].examination = "The door has a small window on it, you can't see much inside.";
    
    nns[CHIPS].word = "CHIPS";
    nns[CHIPS].code = CHIPS;
    nns[CHIPS].description = "a bag of chips";
    nns[CHIPS].can_carry = true;
    nns[CHIPS].location = COUNSELORLODGE;
    nns[CHIPS].examination = "This bag of chips is almost expired.";
    
    nns[STETHOSCOPE].word = "STETHOSCOPE";
    nns[STETHOSCOPE].code = STETHOSCOPE;
    nns[STETHOSCOPE].description = "a stethoscope";
    nns[STETHOSCOPE].can_carry = true;
    nns[STETHOSCOPE].location = INFIRMARY;
    nns[STETHOSCOPE].examination = "It is shiny, and looks slightly old.";
    
    nns[FOUNATAIN_PEN].word = "FOUNTAINPEN";
    nns[FOUNATAIN_PEN].code = FOUNATAIN_PEN;
    nns[FOUNATAIN_PEN].description = "a fountain pen";
    nns[FOUNATAIN_PEN].can_carry = true;
    nns[FOUNATAIN_PEN].location = OFFICE;
    nns[FOUNATAIN_PEN].examination = "The pen appears to be filled with ink.";

    nns[GYMBAG].word = "GYMBAG";
    nns[GYMBAG].code = GYMBAG;
    nns[GYMBAG].description = "some gymbag";
    nns[GYMBAG].can_carry = true;
    nns[GYMBAG].location = RECCENTER;
    nns[GYMBAG].examination = "The bag smells like feet, but is empty.";
    
    nns[LADLE].word = "LADLE";
    nns[LADLE].code = LADLE;
    nns[LADLE].description = "a ladle";
    nns[LADLE].can_carry = true;
    nns[LADLE].location = DININGHALL;
    nns[LADLE].examination = "This ladle has spaghetti sauce on it.";
    
    nns[COOKIES].word = "COOKIES";
    nns[COOKIES].code = COOKIES;
    nns[COOKIES].description = "a chocolate cookie";
    nns[COOKIES].can_carry = true;
    nns[COOKIES].location = PICNICAREA;
    nns[COOKIES].examination = "The cookie is pretty tempting, very chocolaty.";
    
    nns[FLASHLIGHT].word = "FLASHLIGHT";
    nns[FLASHLIGHT].code = FLASHLIGHT;
    nns[FLASHLIGHT].description = "a dead flashlight";
    nns[FLASHLIGHT].can_carry = true;
    nns[FLASHLIGHT].location = SHOP;
    nns[FLASHLIGHT].examination = "The flashlight is old, nothing like today's flashlight.";

    nns[LIFEJACKET].word = "LIFEJACKET";
    nns[LIFEJACKET].code = LIFEJACKET;
    nns[LIFEJACKET].description = "a life jacket";
    nns[LIFEJACKET].can_carry = true;
    nns[LIFEJACKET].location = LIFEGUARDHUT;
    nns[LIFEJACKET].examination = "This life jacket is very bulky.";

    nns[BOAT].word = "BOAT";
    nns[BOAT].code = BOAT;
    nns[BOAT].description = "a boat";
    nns[BOAT].can_carry = false;
    nns[BOAT].location = DOCK;
    nns[BOAT].examination = "The boat looks like it could fit two people.";

    nns[WARMCOAT].word = "WARMCOAT";
    nns[WARMCOAT].code = WARMCOAT;
    nns[WARMCOAT].description = "a warm coat";
    nns[WARMCOAT].can_carry = true;
    nns[WARMCOAT].location = LAUNDRYHOUSE;
    nns[WARMCOAT].examination = "This coat is made of wool, it looks it could retain heat.";

    nns[LIPSTICK].word = "LIPSTICK";
    nns[LIPSTICK].code = LIPSTICK;
    nns[LIPSTICK].description = "lipstick";
    nns[LIPSTICK].can_carry = true;
    nns[LIPSTICK].location = WOMENSRESTROOM;
    nns[LIPSTICK].examination = "The color of the lip stick is red.";

    nns[SCISSORS].word = "SCISSORS";
    nns[SCISSORS].code = SCISSORS;
    nns[SCISSORS].description = "a pair of scissors";
    nns[SCISSORS].can_carry = true;
    nns[SCISSORS].location = ARTHOUSE;
    nns[SCISSORS].examination = "The scissors are sharp.";

    nns[PAPER].word = "PAPER";
    nns[PAPER].code = PAPER;
    nns[PAPER].description = "a piece of paper";
    nns[PAPER].can_carry = true;
    nns[PAPER].location = SOUTHPATH;
    nns[PAPER].examination = "The paper is a roll list of all the campers who were here.";

    nns[COMPASS].word = "COMPASS";
    nns[COMPASS].code = COMPASS;
    nns[COMPASS].description = "a rusty compass";
    nns[COMPASS].can_carry = true;
    nns[COMPASS].location = BOYSCABIN; 
    nns[COMPASS].examination = "It tells the directions right.";

    nns[SHOVEL].word = "SHOVEL";
    nns[SHOVEL].code = SHOVEL;
    nns[SHOVEL].description = "a dirty shovel";
    nns[SHOVEL].can_carry = true;
    nns[SHOVEL].location = GARDEN;
    nns[SHOVEL].examination = "It is pretty rusted and covered in dirt.";

    nns[BATTERIES].word = "BATTERIES";
    nns[BATTERIES].code = BATTERIES;
    nns[BATTERIES].description = "a box of batteries";
    nns[BATTERIES].can_carry = true;
    nns[BATTERIES].location = LAKESUPPLIES;
    nns[BATTERIES].examination = "The batteries are Energizer, only the best brand!.";
}
//-------------------------------------------------------------

void section_command(string Cmd, string &wd1, string &wd2)
{
    //debug signals that this function has started
    // if (debug) 
    // {
    //     cout << "Starting section_command().\n";
    // }

    // if (debug) 
    // {
    //     cout << "Cmd = " << Cmd << ", wd1 = " << wd1 << ", wd2 = " << wd2 << endl;
    // }

    string sub_str;
    vector<string> words;
    char search = ' ';
    size_t i, j;

    for (i = 0; i < Cmd.size(); i++)
    {
        if (Cmd.at(i) != search)
        {
            sub_str.insert(sub_str.end(), Cmd.at(i));
        }
        if (i == Cmd.size() - 1)
        {
            words.push_back(sub_str);
            sub_str.clear();
        }
        if (Cmd.at(i) == search)
        {
            words.push_back(sub_str);
            sub_str.clear();
        }
    }

    for (i = words.size() - 1; i > 0; i--)
    {
        if (words.at(i) == "")
        {
            words.erase(words.begin() + i);
        }
    }

    for (i = 0; i < words.size(); i++)
    {
        for (j = 0; j < words.at(i).size(); j++)
        {
            if (islower(words.at(i). at(j)))
            {
                words.at(i).at(j) = toupper(words.at(i).at(i));
            }
        }
    }

    if (words.size() == 0)
    {
        cout << "No command given" << endl;
    }
    if (words.size() == 1)
    {
        wd1 = words.at(0);
    }
    if (words.size() == 2)
    {
        wd1 = words.at(0);
        wd2 = words.at(1);
    }
    if (words.size() > 2)
    {
        cout << "Command is too long. Only type one, two, or three words (direction or verb and noun)" << endl;
    }
}
//---------------------------------------------------------------

void look_around(int loc, room *rms, words *dir, noun *nns)
{
    //debug signals that this function has began
    // if (debug) 
    // {
    //     cout << "Starting look_around().\n";
    // }

    int i = 0;
    cout << "I am " << rms[loc].description << "." << endl;

    for (i = 0; i < DIRS; i++)
    {
        if (rms[loc].exits_to_room[i] != NONE)
        {
            cout << "There is an exit " << dir[i].word << " to a " << 
            rms[rms[loc].exits_to_room[i]].description << "." << endl;
        }
    }

    for (i = 0; i < NOUNS; i++)
    {
        if (nns[i].location == loc)
        {
            cout << "I see " << nns[i].description << "." << endl;
        }
    }
}
//---------------------------------------------------------------

bool parser(int &loc, string wd1, string wd2, words *dir, words *vbs, room *rms, noun *nns)
{
    //if (debug) cout << "Starting parcer().\n"; 
    //debug signals that parcer function began

    static bool door_state = false; //false is a closed door.

    int i;
    for (i = 0; i < DIRS; i++)
    {
        if (wd1 == dir[i].word)
        {
            if (rms[loc].exits_to_room[dir[i].code] != NONE)
            {
                loc = rms[loc].exits_to_room[dir[i].code];
                cout << "I am now " << rms[loc].description << "." << endl;

                //Added code. A special case for the WESTPATH SHOP door.
                if (loc == SHOP || loc == WESTPATH)
                {
                    nns[SHOP_DOOR].location = loc;
                }
                return true;
            }
            else
            {
                cout << "No exit that way." << endl;
                return true;
            }   
        }
    }

    int NOUN_MATCH = NONE;
    
    int VERB_ACTION = NONE;

    for (i = 0; i < VERBS; i++)
    {
        if (wd1 == vbs[i].word)
        {
            VERB_ACTION = vbs[i].code;
            break;
        }
    }

    if (wd2 != "")
    {
        for (i = 0; i < NOUNS; i++)
        {
            if (wd2 == nns[i].word)
            {
                NOUN_MATCH = nns[i].code;
                break;
            }
        }
    }

    if (VERB_ACTION == NONE)
    {
        cout << "No valid command entered." << endl;
        return true;
    }
    if (VERB_ACTION == LOOK)
    {
        look_around(loc, rms, dir, nns);
        return true;
    }

    if (VERB_ACTION == OPEN)
    {
        if (NOUN_MATCH == SHOP_DOOR)
        {
            if (loc == WESTPATH || loc == SHOP)
            {
                if (door_state == false)
                {
                    door_state = true;
                    rms[WESTPATH].exits_to_room[SOUTH] = SHOP;
                    rms[SHOP].exits_to_room[NORTH] = WESTPATH;
                    nns[SHOP_DOOR].description.clear(); 
                    nns[SHOP_DOOR].description.assign("an open store room door");
                    
                    cout << "I have opened the door." << endl;
                    return true;
                }
                else if (door_state == true)
                {
                    cout << "The door is already open." << endl;
                    return true;
                }
            }
            else
            {
                cout << "There is no door to open here." << endl;
                return true;
            }  
        }
        else
        {
            cout << "Opening that is not possible." << endl;
            return true;
        }  
    }

    if (VERB_ACTION == CLOSE) //verb action for close
    {
        if (NOUN_MATCH == SHOP_DOOR)
        {
            if (loc == WESTPATH || loc == SHOP)
            {
                if (door_state == true)
                {
                    door_state = false;
                    rms[WESTPATH].exits_to_room[SOUTH] = NONE;
                    rms[SHOP].exits_to_room[NORTH] = NONE;
                    nns[SHOP_DOOR].description.clear(); 
                    nns[SHOP_DOOR].description.assign("a closed store room door");

                    cout << "I have closed the door." << endl;
                    return true;
                }
                else if (door_state == false)
                {
                    cout << "The door is already closed." << endl;
                    return true;
                }
            }
            else
            {
                cout << "There is no door to close here." << endl;
                return true;
            }    
        }
        else
        {
            cout << "Closing that is not possible." << endl;
            return true;
        }  
    }

    if (VERB_ACTION == GET) //verb action for get
    {
        if (NOUN_MATCH != NONE)
        {
            if (nns[NOUN_MATCH].can_carry == true)
            {
                if (nns[NOUN_MATCH].location == loc)
                {
                    nns[NOUN_MATCH].location = BACKPACK; 
                    cout << "You have grabbed " << nns[NOUN_MATCH].word << "." << endl;
                }
                else
                {
                    cout << "Error, that item is not in this room." << endl;
                }    
            }
            else
            {
                cout << "Error, you cannot pick up that item." << endl;
            }
        }
        else
        {
            cout << "Error, you did not type anything to get." << endl;
        }
    }

    if (VERB_ACTION == DROP) //verb action for drop
    {
        if (NOUN_MATCH != NONE)
        {
            if (nns[NOUN_MATCH].location == BACKPACK)
            {
                nns[NOUN_MATCH].location = NONE;

                cout << "You have dropped the " << nns[NOUN_MATCH].word << endl;
            }
            else
            {
                cout << "Error, that item is not in your inventory." << endl;
            }  
        }
        else
        {
            cout << "Error, you did not type anything to drop." << endl;
        }     
    }

    if (VERB_ACTION == INVENTORY) //verb action for inventory
    {
        look_around(BACKPACK, rms, dir, nns);
        return true;
    }

    if (VERB_ACTION == EAT) //verb action for eat
    {
        if (NOUN_MATCH == CHIPS || NOUN_MATCH == COOKIES)
        {
            if (nns[NOUN_MATCH].location == BACKPACK) 
            {
                nns[NOUN_MATCH].location = NONE;

                cout << "You have eaten the " << nns[NOUN_MATCH].word << endl; 
            }
            else
            {
                cout << "Error, that item is not in your inventory." << endl;
            }
            
        }
        else
        {
            cout << "Error, you cannont eat that item!" << endl;
        } 
    } 

    if (VERB_ACTION == EXAMINE) //verb action for examine
    {
       if (NOUN_MATCH != NONE)
       {
           if (nns[NOUN_MATCH].location == BACKPACK)
            {
                
                cout << "You have chosen the " << nns[NOUN_MATCH].word <<":" <<  endl;
                cout << nns[NOUN_MATCH].examination << endl;
            }
            else
            {
                cout << "Error, that item is not in your inventory." << endl;
            }  
        }
        else
        {
            cout << "Error, you did not type anything to drop." << endl;
        }
    }
    
    return false;
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------

int main()
{
    //if (debug) cout << "Starting main().\n"; 
    //debug signals that int main has began
    
    string command;
    string word_1;
    string word_2;

    room rooms[ROOMS];
    set_rooms(rooms);

    words directions[DIRS];
    set_directions(directions);

    words verbs[VERBS];
    set_verbs(verbs);

    noun nouns[NOUNS];
    set_nouns(nouns);

    //Begin in office
    int location = OFFICE;
    
    cout << "\tWelcome to the abandoned Camp Chippewa\t" << endl;
    cout << "<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>" << endl;
    cout << "\nYou can do a myriad of things, such as:\n" << endl;
    cout << "eat, get, look, open, examine, drop, close, and inventory." << endl;
    cout << "You are also able to select the option to quit." << endl;
    cout << "\nPlease type all commands in CAPITAL LETTERING, and enjoy your exploration." << endl;
  
    while (word_1 != "QUIT")
    {
        command.clear();
        cout << "\nWhat shall I do?\n";
        getline(cin, command);
        
        word_1.clear();
        word_2.clear();

        section_command(command, word_1, word_2);

        if (word_1 != "QUIT")
        {
            parser(location, word_1, word_2, directions, verbs, rooms, nouns);
        }
    }
    cout << "\nOkay, bye!" << endl;

    return 0;
}