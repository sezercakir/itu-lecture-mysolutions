/*	Talha Sezer Çakır
	150180027
*/
#include "Elves.h"
// constructor of inherited class
Elves::Elves(const string& name,int numOfUnits, int attackPoint, int healthPoint, int unitRegen)
										: Faction(name,numOfUnits,attackPoint,healthPoint,unitRegen,healthPoint*numOfUnits){
}


void Elves::Print() {
	cout << "\"You cannot reach our elegance.\"" << endl;
	cout<< "Faction Name: " << name <<endl;
	cout<< "Status: " << getStatus() <<endl;  // sonradan implement et
	cout<< "Number of Units: " << numOfUnits <<endl;
	cout<< "Attack Point: " << attackPoint<<endl;
	cout<< "Health Point: " <<  healthPoint <<endl;
	cout<< "Unit Regen Number: " << unitRegen <<endl;
	cout<< "Total Faction Health: " << totalHealth <<endl;
}


void Elves::PerformAttack() {
	if (secondEnemy->GetName() == "Dwarves" && !(firstEnemy->IsAlive()))
		secondEnemy->ReceiveAttack((numOfUnits), attackPoint * (1.5));			// attacking to Dwarves by Elves
	if (secondEnemy->GetName()=="Orcs" && !(firstEnemy->IsAlive()))	
		secondEnemy->ReceiveAttack((numOfUnits), attackPoint * (0.75)); 		// attacking to Orcs by Elves
	if (firstEnemy->GetName()=="Dwarves" && !secondEnemy->IsAlive())
		firstEnemy->ReceiveAttack((numOfUnits), attackPoint * (1.5));			// attacking to Dwarves by Elves
	if (firstEnemy->GetName() == "Orcs" && !secondEnemy->IsAlive())
		firstEnemy->ReceiveAttack((numOfUnits), attackPoint * (0.75));			// attacking to Orcs by Elves
	// when two enemy are alived
	else{
		if (firstEnemy->GetName()=="Orcs" && secondEnemy->GetName()=="Dwarves" && firstEnemy->IsAlive() && secondEnemy->IsAlive())
		{
			firstEnemy->ReceiveAttack((numOfUnits - (numOfUnits * 40)/100), attackPoint * (0.75)); 		// attacking to Orcs by Elves
			secondEnemy->ReceiveAttack((numOfUnits - (numOfUnits * 60)/100), (attackPoint * (1.5)));	// attacking to Dwarves by Elves
		}
		if (firstEnemy->GetName()=="Dwarves" && secondEnemy->GetName()=="Orcs" && firstEnemy->IsAlive() && secondEnemy->IsAlive())
		{
			firstEnemy->ReceiveAttack((numOfUnits - (numOfUnits * 60)/100), (attackPoint * (1.5)));
			secondEnemy->ReceiveAttack((numOfUnits - (numOfUnits * 40)/100), attackPoint * (0.75)); 
		}
	}
}

// end of the attack damaga is calculated in here
void Elves::ReceiveAttack(double incomingUnit, double incomingAttackPoint) {
	int deadUnit = (incomingUnit*incomingAttackPoint)/healthPoint;
	numOfUnits -= deadUnit;
}


int Elves::PurchaseWeapons(int Weaponamount)  {
	attackPoint += Weaponamount*2;
	return (Weaponamount*15);
}


int Elves::PurchaseArmors(int Armoramount)  {
	healthPoint += Armoramount*4;
	return (Armoramount*5);
}