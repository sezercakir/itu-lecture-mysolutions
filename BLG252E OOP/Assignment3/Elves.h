/*	Talha Sezer Çakır
	150180027
*/
#pragma once
#include "Faction.h"

class Elves : public Faction
{
public:
	Elves(const string&,int,int,int,int);
	void PerformAttack() override;
	void ReceiveAttack(double,double) override;
	int PurchaseWeapons(int) override; 
	int PurchaseArmors(int) override ;
	void Print() override;
	
};