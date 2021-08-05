//////////////////////////////////
/*      Talha Sezer ÇAkır       */
/*          150180027           */
//////////////////////////////////
#pragma once
#include <iostream>

using namespace std;

class Land
{
public:
	Land();
	Land(string name,string holding);
	Land(const Land& inLand);
	inline string getter_landname(){return landName; }
	inline string getter_holding(){ return holding; }	
	Land *next;
private:
	string landName;
	string holding;
	
};


class Character
{
public:
	Character();
	Character(const string&,int, int,int);
	Character(const string&,const string&,int = 1,int = 3,int = 20);
	Character(Character&);
	~Character();
	void addLand(string landname,string holding);			
	void removeLand(const string&,bool = false);
	string find_holding_type(const string&);
	int getter_numOfLands();
	int getter_gold();
	int getter_manpower();
	string getter_name();
	string getter_general_name()const; 
	Land* getter_head();
	void setter_gold(int);
	void setter_manpower(int,bool lost);
	void setter_numOfLands(bool flagnum,int = 0,bool = true);
	void getTaxes();
private:
	string name;
	int manpower;
	int gold;
	int numOfLands;
	Land *head;
};

class CharacterList
{
public:
	CharacterList();
	~CharacterList();
	bool isValidLand(const string&);
	friend void ListCharacters(CharacterList&);
	friend void listLands(CharacterList&);
	void resize();
	bool need_to_resize();
	void addCharacter(Character&);
	int getter_size();
	void delCharacter(Character&);
	Character* getter_list();
	Character& getPlayer(const string&);
	Character& getLandOwner(const string&); // https://stackoverflow.com/questions/1815643/how-to-properly-return-reference-to-class-member
private:
	int size;
	int arr_length;
	Character *list;	
};

