/*	Talha Sezer Çakır
	150180027
*/
#pragma once
#include "Faction.h"

class Merchant
{
	Faction* firstFaction;
 	Faction* secondFaction;
 	Faction* thirdFaction;
 	int startingWeaponPoints;
 	int startingArmorPoints;
 	int revenue;
 	int WeaponPoint;
 	int ArmorPoint;

public:
	Merchant(int num,int num1);
	//getters 
	int GetRevenue(){			return revenue;};
	int GetWeaponPoints(){		return WeaponPoint;};
	int GetArmorPoints(){		return ArmorPoint;};
	//functions
	void AssignFactions(Faction* i,Faction* j,Faction* k);
	bool SellWeapons(const string&,int);
	bool SellArmors(const string&,int);
	void EndTurn();
	
};


