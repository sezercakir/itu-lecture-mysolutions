//////////////////////////////////
/*      Talha Sezer ÇAkır       */
/*          150180027           */
//////////////////////////////////
#include <iostream>

#include <stdbool.h>
using namespace std;



Land::Land(){									// default constructor of Land
	landName = "";
	holding = "";
	next = NULL;
}

Land::Land(string landname,string holdingT){	//  constructor with parameters of land
	landName = landname;
	holding = holdingT;
    next = NULL;
}
Land::Land(const Land& inLand){					// copy constructor of Land
    landName = inLand.landName; 
    holding = inLand.holding;
    next = inLand.next;
}

Character::Character(){							// default constructor of character
	head = NULL;	
	name = "";
    manpower = 0;
    gold = 0;
    numOfLands = 0;
}
Character::~Character(){						// destructure of character
    Land * traverse;
    while (head != NULL) {
        traverse = head;
        head = head->next;
        delete traverse;
    }
}


Character::Character(Character& character_in){	// copy constructor of character
	name = character_in.name;
	numOfLands = character_in.numOfLands;
	manpower = character_in.manpower;
	gold = character_in.gold;
	head=NULL;
	Land* traverse = character_in.head;    // used to iterate over the original list
	
	while(traverse != NULL){

		this->addLand(traverse->getter_landname(),traverse->getter_holding());		// assign to lands of character_in to my character
		traverse = traverse->next;
	}
}

Character::Character(const string& name,int numOfLands,int manpower, int gold){
	this->name = name;
	this->numOfLands = numOfLands;					//  constructor with parameters 
	this->manpower = manpower;
	this->gold = gold;
	head = NULL;
}
Character::Character(const string& name,const string& landN,int numOfLands,int manpower,int gold){
	this->name = name;
	this->numOfLands = numOfLands;
	this->manpower = manpower;
	this->gold = gold;								//  constructor with parameters for my player and my general
	Land temp = Land(landN,"village");	
    Land *tempLand = new Land(temp);
    head = tempLand;
}

void Character::addLand(string landname,string holding){		// adding land to character with traverse method
	numOfLands++;
	Land templand = Land(landname,holding);
	Land* newLandadd = new Land(templand);
    if(head == NULL)
    {
        head = newLandadd;
        return;
    }
    else{	
        Land *traverse = head;
        while(traverse){
            if(traverse->next == NULL){
                traverse->next = newLandadd;
                break;
            }
            traverse = traverse->next;
            
        }
    }

}

void Character::removeLand(const string& target,bool controller){
	
 	// bool controller "true" means that "war" has happened and program execute operations according to this
 	// bool controller "false" means that "rebellions" has happend and program execute operations according to this
	if (controller==true)
	{	
		
		if(head == NULL){
        	
        	return;
    	}
    	Land *traverse = head;
    	
    	if(head->getter_landname() == target){
    	    head=head->next;
    	    numOfLands--;
    	    return;
    	   
    	}else{
    	    Land *previous = head;
    	    while(traverse){
    	        if(traverse->getter_landname() == target){
    	            previous->next = traverse->next;
    	            numOfLands--;
    	           
    	        }
    	        previous = traverse;
    	        traverse = traverse->next;
    	    }
    	}
	}

	
 	else{								// means that no war happened however rebellions occurs
 		if (head!=NULL)
 		{	
 			Land* tmpl = head;			
 			head = head->next;			// result of rebellion first land of my player are removed
 			delete tmpl;
 		}
 	} 	
 }
 	

string Character::find_holding_type(const string& inLand){	// this func are called at the end of the war.
	Land *iterator = head;									//     if my player win the war, this funciton execute 
															//     in order to find correct landing type of the land which will be added to my player

	string  holdingtype;
	if (iterator->next==NULL)
	{
		holdingtype = iterator->getter_holding();
	}
	else{
		while(iterator!=NULL){
		if (iterator->getter_landname()==inLand){
			holdingtype = iterator->getter_holding();
			break;
		}
		iterator = iterator->next; 
		}
	}
	return holdingtype;
}

int Character::getter_numOfLands(){return numOfLands;}
int Character::getter_gold(){ return gold; }
string Character::getter_name(){ return name; }
void Character::setter_gold(const int amount){
	gold = amount;
}
void Character::setter_numOfLands(bool flagnum,int numof,bool flag){
 	if (flag==false){											
 		numOfLands = numof;
 		return;										// flag is defaultly true otherwise false.
 	}												// flagnum represent wheter wat has happened or not. if it is false was has been lost or 
 													//		rebellion has occured contrarily war has been won by the player.
 	else if(flagnum) 								
 		numOfLands++;
 	else
 		numOfLands--;
};
int Character::getter_manpower(){return manpower;}
string Character::getter_general_name()const{return name;}
void Character::setter_manpower(const int numOfman,bool lost){		// if bool lost is true means that war has been lost.
	if (lost==false){
		manpower = manpower + numOfman;
	}
	else if (lost==true)
	{
		manpower = manpower - numOfman;
	}	
}	

void Character::getTaxes(){
	if (head==NULL)
	{	
		return;
	}
	Land* temp = head;
	for (int i = 0; i < numOfLands; i++)
	{
		if (temp->getter_holding()=="village")
			gold+=5;
		else if (temp->getter_holding()=="castle")
			gold+=7;
		else if(temp->getter_holding()=="city")
			gold+=10;
		temp=temp->next;
	}

}
Land* Character::getter_head(){							
	return head;
}
CharacterList::CharacterList(){						// constructor character list and allocate memory
	list = new Character[5];	
	size = 0;
	arr_length = 5;
	
}
CharacterList::~CharacterList(){
	delete[] list;		
}
Character* CharacterList::getter_list(){
	return list;
}
bool CharacterList::isValidLand(const string& inLandname){		// isValidLand checks input landname that has been attacked 
	
	bool flag = false;
	for (int i = 0; i < size-1; i++)							// size-1 provide player cannot attack his/her land.
    {   
    	if (flag==false)
    	{
    		Land *iterator = list[i].getter_head();				// scans all lands with traverse method
       		while(iterator!=NULL)
       		{   
       			if (iterator->getter_landname() == inLandname)
       			{
       				flag=true;
       				break;
       			}
       		    iterator = iterator->next;
        	}
    	}
    }
    return flag;
}

Character& CharacterList::getPlayer(const string& target){			// return player that is searched 
    int j = 0;
    for(int i = 0; i < size; i++){
        if(list[i].getter_name() == target){
            break; 
        }
        j++;
    }
    return list[j];
}
Character& CharacterList::getLandOwner(const string& inLandname){	// scan all lands and search owner of target land
	bool flag = true;
	int i = 0;
	for (; i < size-1; i++)
	{	
		
		Land* iterator = list[i].getter_head();
		while(iterator!=NULL){
			if (iterator->getter_landname() == inLandname)
       		{	
       			flag = false;
       		}
       		iterator = iterator->next;
		}
		// delete iterator??
		if (flag==false)
			break;
	}
	if (flag==true)
	{
		cout<<"Cannot finded";
	}
	return list[i];
	
}
void CharacterList::resize(){									// resize() copies character list and extand size of it
	arr_length *=2;
	Character *temp = new Character[arr_length+1];
	for (int i = 0; i < size; i++)
		temp[i] = list[i];		//no match for 'operator=' (operand types are 'CharacterList' and 'Character')
	list = temp;
}
bool CharacterList::need_to_resize(){
	
	return size == arr_length;
}
void CharacterList::addCharacter(Character& character_in){		
	if (need_to_resize()){
		resize();
	}
	list[size] = character_in;
	size++;
}

void CharacterList::delCharacter(Character& character_in){
	Character* templist = new Character[size-1];
	int j = 0;
	for (int i = 0; i < size; i++)
	{	
		if (list[i].getter_name() != character_in.getter_name())
		{
			templist[j] = list[i];
			j++;
		}
	}
	size--;
	list = templist;
}
int CharacterList::getter_size(){return size;}
