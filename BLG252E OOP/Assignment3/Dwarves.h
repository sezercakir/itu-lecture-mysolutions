/*	Talha Sezer Çakır
	150180027
*/
#pragma once
#include "Faction.h"

class Dwarves : public Faction
{
public:
	Dwarves(const string&,int,int,int,int);
	void PerformAttack()override;
	void ReceiveAttack(double,double) override;
	int PurchaseWeapons(int)override; 
	int PurchaseArmors(int) override;
	void Print() override;
};
