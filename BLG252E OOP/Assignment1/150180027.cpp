//////////////////////////////////
/*      Talha Sezer ÇAkır       */
/*          150180027           */
//////////////////////////////////

#include <iostream>
#include <fstream>
#include "GreatWarrior.h"
#include "GreatWarrior.cpp"
using namespace std;

/*  Define necessary classes and attributes in GreatWarrior.h and GreatWarrior.cpp */

/*  = Fill in the blanks in this main.cpp file. The parts that you need to implemented are specified below.
    = Please write your code between ///// FILL HERE ///// lines.
    = The expressions you need to print out with cout operation are given in necessary format.
    = You can use them directly by filling the variable parts.
*/

void listCharacters(CharacterList& );
void listLands(CharacterList&);
void readData(string, CharacterList&);
void printGameMenu();
bool endOfTurn(Character&, int);

int main() {
    cout << "Welcome to the Great Warriors. Create your character and attack other lands to be a great warrior.\n" << endl;

    CharacterList charList;             // list object to store the characters

    string fileName = "characters.txt"; // read characters.txt file
    readData(fileName, charList);

    /* creating player's character */
    string name, land, general;
    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter name of your capital: ";
    cin >> land;

    cout << "Enter name of your general: ";
    cin >> general;
    
    const Character General(general,land);
    Character* characterr = new Character(name,land,1,3,20);    
    charList.addCharacter(*characterr);
    Character &player = charList.getPlayer(name);
    // In-game loop 
    
    bool controller;                    // bool controller exist for checking whether round must increase or not
    int choice = 0, round = 0;
    while (choice != 6) {
        printGameMenu();

        cin >> choice;
        
        switch (choice) {
        case 1: {
            cout << "You have rested in your palace." << endl;
            cout << "You've talked with your general " << General.getter_general_name() << "." << endl;
            controller = true;
            round++;
            break;
        }
        case 2: {
            listLands(charList);
            cout << "Enter name of the land to attack." << endl;
            controller = true;
            string land;
            cin >> land;

            if (charList.isValidLand(land))             // checking valid land name
            {
                Character &CharatWar = charList.getLandOwner(land);     // getting target character
                int counter_manpower = CharatWar.getter_manpower();     //getting target manpower
                int my_manpower = player.getter_manpower();
                string holdingType = CharatWar.find_holding_type(land); // finding holding type of target land
                
                if (my_manpower >= counter_manpower)
                {   
                    CharatWar.setter_manpower(counter_manpower,true);   // bool true means that war has been happened and manpower must decrease
                    player.setter_manpower(counter_manpower,true);      // bool true means that war has been happened and manpower must decrease
                    player.addLand(land,holdingType);              
                    CharatWar.removeLand(land,true);                    // true means that rebellions of war on condition
                    CharatWar.setter_numOfLands(false);                 // false means that war has been lost
                    
                    cout << "You've won the battle and conquered " << land << "." << endl;
                    if (CharatWar.getter_numOfLands()==0)
                    {   
                        charList.delCharacter(CharatWar);
                    }
                }
                else{
                    player.setter_manpower(my_manpower,true);           // bool true means that war has been happened and manpower must decrease
                    cout << "You've lost the battle and " << my_manpower << " manpower." << endl;
                }
            }
            else{
                cout << "You entered an invalid value. Try again." << endl;
                controller = false;
            }
            
            round++;
            break;
        }
        case 3:
            cout << "How much manpower do you need? (1 manpower=5 gold)" << endl;
            controller = false;
            int order;
            cin >> order;
            
            if (player.getter_gold() >= order*5 )
            {
                player.setter_gold(player.getter_gold()- 5*order);      // set the gold after buying
                player.setter_manpower(order,false);                    // false means that war has not happende, buying mode active, increase manpower
                cout << "Order successful. You have " << player.getter_manpower() << " manpower." << endl;
            }
            else
                cout << "You do not have enough money." << endl;
            continue; 
            
        case 4:
            listCharacters(charList);
            controller = false;
            break;
        case 5:
            listLands(charList);
            controller = false;
            break;
        case 6:
            return 0;
        default:
            cout << "You entered an invalid value. Try again." << endl;
        }
        if(controller==true){
            bool flag = endOfTurn(player, round);           // if flag false means that gameover and terminate the program
            if (charList.getter_size()==1)
            {
                cout << player.getter_name()<< " is the only great warrior now." << endl;
                choice = 6;                      // terminates the program
                break;
            }
            if (flag==false)
            {
                choice = 6;             // terminates the program as gameover
            }
            else
                continue;
        } 
    }
}

void readData(string fileName, CharacterList& charList) {

    fstream dataFile(fileName.c_str());

    if (dataFile.is_open()) {

        string word;
        while (dataFile >> word) {

            string name, title;
            int money, manpower, numOfLands;

            name = word;
            dataFile >> manpower;
            dataFile >> money;
            dataFile >> numOfLands;

            Character* characterr = new Character(name,numOfLands,manpower,money);
           
            string landName, holding;

            for (int i = 0; i < numOfLands; i++) {
                dataFile >> landName;
                dataFile >> holding;

                characterr->addLand(landName,holding);
                
                /* Create a new land object with read data and assign the land to the character you have created */
                
               
            }
            
            charList.addCharacter(*characterr);

        }

        dataFile.close();                                                       
    }
    else cout << "Unable to open the file" << endl;

    return;
}

void printGameMenu() {
    cout << endl;
    cout << "1. Stay in your palace" << endl;
    cout << "2. Attack to a land" << endl;
    cout << "3. Buy manpower" << endl;
    cout << "4. List characters" << endl;
    cout << "5. List lands" << endl;
    cout << "6. Exit" << endl;
    cout << endl;
}

void listCharacters(CharacterList& charList) {
    cout << endl;
    
    for (int i = 0; i < charList.getter_size(); i++)
    {   
        
        cout<<charList.getter_list()[i].getter_name()<<endl;    // list all character
    }
}

void listLands(CharacterList& charList) {
    cout << endl;
   
    for (int i = 0; i < charList.getter_size(); i++)
    {   
        Land *tempToprint = charList.getter_list()[i].getter_head();
        while(tempToprint!=NULL)
        {                               // list all lands
            cout << tempToprint->getter_landname() << " " <<  tempToprint->getter_holding() << " owned by " << charList.getter_list()[i].getter_name() <<endl;
            tempToprint = tempToprint->next;                // list all character
        }     
    }
    
    cout << endl;
}

bool endOfTurn(Character& player, int round) { //return a bool value that indicates if the game is over or not.

    player.getTaxes();
    
    if (player.getter_numOfLands() == 0)
    {
        cout << "You are no longer a great warrior. You survived " << round << " turns." << endl;
        cout << endl;
        cout << "GAME OVER." << endl;
        return false;      
    }
    else{
        if(player.getter_manpower()==0)
        {   
            player.removeLand("",false);            // false means that war has not been happened but rebbelion has been happened
            player.setter_numOfLands(false);        // false decrease lands num
            cout << "You lost one of your lands to rebellions since you don't have enough army." << endl;
        }
        if (player.getter_gold() < player.getter_manpower())
        {      
            player.setter_manpower((player.getter_gold()),true); // assign soldiers as much as she/he has gold
            cout << player.getter_manpower() << " soldiers run away from your army because you don't have enough gold to feed them." << endl;
            player.setter_gold(0);                  // set gold as 0
        }
        else{
            player.setter_gold(player.getter_gold()-player.getter_manpower()); // set gold as much as gold - numof manpower
        }
    }
    cout << "Turn " << round << ": " << " " << player.getter_name() << " has " << player.getter_numOfLands()
    << " land(s), " << player.getter_manpower() << " manpower and " << player.getter_gold() << " golds." << endl;
    
    return true;

}
