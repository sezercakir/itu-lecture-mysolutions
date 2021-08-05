/*	Talha Sezer Çakır
	150180027
*/

#include <iostream>
#include "Faction.h"
using namespace std;


// contructor
Faction::Faction(const string& name,int numOfUnits, int attackPoint,int healthPoint,int unitRegen, int totalHealth,bool flag){
	this->firstEnemy = NULL;
	this->secondEnemy = NULL;
	this->name = name;
	this->numOfUnits = numOfUnits;
	this->attackPoint = attackPoint;
	this->healthPoint = healthPoint;
	this->unitRegen = unitRegen;
	this->totalHealth = totalHealth;
	this->alive = flag;
	this->status = "Alive";
}

void Faction::Print(){
	cout<< "Faction Name: " << name <<endl;
	cout<< "Status: " << getStatus() <<endl;  
	cout<< "Number of Units: " << numOfUnits <<endl;
	cout<< "Attack Point: " << attackPoint<<endl;
	cout<< "Health Point: " <<  healthPoint <<endl;
	cout<< "Unit Regen Number: " << unitRegen <<endl;
	cout<< "Total Faction Health: " << totalHealth <<endl;
}

void Faction::AssignEnemies(Faction* firstEnemy,Faction* secondEnemy){
	(this->firstEnemy) = firstEnemy;
	(this->secondEnemy) = secondEnemy;
}


void Faction::EndTurn(){
	
	if (numOfUnits<0)			// checks contion of player 
	{
		numOfUnits = 0;
		totalHealth = 0;
		alive = false;
		status = "Defeated";
		return;
	}
	numOfUnits += unitRegen;
	totalHealth = numOfUnits * healthPoint;
}









