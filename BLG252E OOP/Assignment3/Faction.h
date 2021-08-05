/*	Talha Sezer Çakır
	150180027
*/
#pragma once
#include <iostream>
using namespace std;


class Faction
{
protected:
	string name;
	Faction* firstEnemy;
	Faction* secondEnemy;
	string status;
	int numOfUnits;
	int attackPoint;
	int healthPoint;
	int unitRegen;
	int totalHealth;
	bool alive;
public:
	Faction(){};										// constructors
	Faction(const string&,int,int,int,int,int,bool = true);

	string GetName(){return name;};						//getters
	string getStatus(){return status;};

	void AssignEnemies(Faction*,Faction*);
	void EndTurn();
	bool IsAlive(){ return alive;};
														// pure virtual and virtual functions
	virtual void PerformAttack() = 0;					//pure v.
	virtual void ReceiveAttack(double,double) = 0;		//pure v.
	virtual int PurchaseWeapons(int) = 0; 				//pure v.
	virtual int PurchaseArmors(int) = 0;				//pure v.
	virtual void Print();								//v.
			
};


