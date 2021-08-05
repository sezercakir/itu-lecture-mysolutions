/*	Talha Sezer Çakır
	150180027
*/
#include <iostream>
#include "Merchant.h"
using namespace std;


// constructor 
Merchant::Merchant(int startingWeaponPoints,int startingArmorPoints){
	this->startingWeaponPoints = startingWeaponPoints;
	this->startingArmorPoints = startingArmorPoints;
	this->revenue = 0;
	this->WeaponPoint = startingWeaponPoints;
	this->ArmorPoint = startingArmorPoints;
	this->firstFaction = NULL;
	this->secondFaction = NULL;
	this->thirdFaction = NULL;
}

void Merchant::AssignFactions(Faction* i,Faction* j, Faction* k){
	firstFaction = i;
	secondFaction = j;
	thirdFaction =k;
}

bool Merchant::SellWeapons(const string& name, int amount){
	bool flag = true;
	if (name == firstFaction->GetName())
	{
		if(firstFaction->getStatus() == "Alive" && amount <= WeaponPoint){					// if part for normal legal tradition	
			revenue += firstFaction->PurchaseWeapons(amount);
			WeaponPoint -= amount;
		}
		else if(amount > WeaponPoint){
			cout<<"You try to sell more weapons than you have in possession."<<endl;		// else if part checks amount of weapon
			return false;
		}
		else{
			cout<<"The faction you want to sell weapons is dead!"<<endl;					// checks player is dead or not
			return false;
		}
	}
	else if(name == secondFaction->GetName()){
		if(secondFaction->getStatus() == "Alive" && amount <= WeaponPoint){
			revenue += secondFaction->PurchaseWeapons(amount);
			WeaponPoint -= amount;
		}
		else if(amount > WeaponPoint){
			cout<<"You try to sell more weapons than you have in possession."<<endl;
			return false;
		}
		else{
			cout<<"The faction you want to sell weapons is dead!"<<endl;
			return false;
		}
	}
	else if(name == thirdFaction->GetName()){
		if(thirdFaction->getStatus() == "Alive" && amount <= WeaponPoint){
			revenue += thirdFaction->PurchaseWeapons(amount);
			WeaponPoint -= amount;
		}
		else if(amount > WeaponPoint){
			cout<<"You try to sell more weapons than you have in possession."<<endl;
			return false;
		}
		else{
			cout<<"The faction you want to sell weapons is dead!"<<endl;
			return false;
		}
	}
	cout << "Weapons sold!" << endl;
	return flag;
}
bool Merchant::SellArmors(const string& name, int amount){
	bool flag = true;;
	if (name == firstFaction->GetName())
	{
		if(firstFaction->getStatus() == "Alive" && amount <= ArmorPoint){						// if part for normal legal tradition	
			revenue += firstFaction->PurchaseArmors(amount);
			ArmorPoint -= amount;
		}
		else if (amount > ArmorPoint)															// else if part checks amount of armor
		{
			cout<<"You try to sell more armors than you have in possession."<<endl;
			return false;
		}
		else{																					// checks player is dead or not
			cout<<"The faction you want to sell armors is dead!"<<endl;
			return false;
		}
	}
	else if(name == secondFaction->GetName()){
		if(secondFaction->getStatus() == "Alive" && amount <= ArmorPoint){
			revenue += secondFaction->PurchaseArmors(amount);
			ArmorPoint -= amount;
		}
		else if (amount > ArmorPoint){
			cout<<"You try to sell more armors than you have in possession."<<endl;
			return false;
		}
		else{
			cout<<"The faction you want to sell armors is dead!"<<endl;
			return false;
		}
	}
	else if(name == thirdFaction->GetName()){
		if(secondFaction->getStatus() == "Alive" && amount <= ArmorPoint){
			revenue += secondFaction->PurchaseArmors(amount);
			ArmorPoint -= amount;
		}
		else if (amount > ArmorPoint){
			cout<<"You try to sell more armors than you have in possession."<<endl;
			return false;
		}
		else{
			cout<<"The faction you want to sell armors is dead!"<<endl;
			return false;
		}
	}
	cout << "Armors sold!" << endl;
	return flag;
}
void Merchant::EndTurn(){
	WeaponPoint = startingWeaponPoints;
	ArmorPoint = startingArmorPoints;
}







