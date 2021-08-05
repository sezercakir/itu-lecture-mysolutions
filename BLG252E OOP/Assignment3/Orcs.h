/*	Talha Sezer Çakır
	150180027
*/
#pragma once
#include "Faction.h"

class Orcs : public Faction
{
public:
	Orcs(const string&,int,int,int,int);
	void PerformAttack() override;
	void ReceiveAttack(double,double) override;
	int PurchaseWeapons(int) override; 
	int PurchaseArmors(int) override;
	void Print() override;
	
};