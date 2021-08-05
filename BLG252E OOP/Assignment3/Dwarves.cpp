/*	Talha Sezer Çakır
	150180027
*/
#include "Faction.h"
#include "Dwarves.h"

//constructor
Dwarves::Dwarves(const string& name,int numOfUnits, int attackPoint, int healthPoint, int unitRegen)
										: Faction(name,numOfUnits,attackPoint,healthPoint,unitRegen,healthPoint*numOfUnits){
}

void Dwarves::Print() {
	cout << "\"Taste the power of our axes!\"" << endl;
	cout<< "Faction Name: " << name <<endl;
	cout<< "Status: " << getStatus() <<endl;  
	cout<< "Number of Units: " << numOfUnits <<endl;
	cout<< "Attack Point: " << attackPoint<<endl;
	cout<< "Health Point: " <<  healthPoint <<endl;
	cout<< "Unit Regen Number: " << unitRegen <<endl;
	cout<< "Total Faction Health: " << totalHealth <<endl;
}
void Dwarves::PerformAttack() {

	if (secondEnemy->GetName()== "Elves" && !(firstEnemy->IsAlive()))
		secondEnemy->ReceiveAttack((numOfUnits), (attackPoint * (0.75)));		// attacking to Elves by Dwarves
	if (secondEnemy->GetName()=="Orcs" && !(firstEnemy->IsAlive()))	
		secondEnemy->ReceiveAttack((numOfUnits), (attackPoint * 0.8)); 			// attacking to Orc by Dwarves
	if (firstEnemy->GetName()=="Elves" && !secondEnemy->IsAlive())
		firstEnemy->ReceiveAttack((numOfUnits), (attackPoint * (0.75)));
	if (firstEnemy->GetName() == "Orcs" && !secondEnemy->IsAlive())
		firstEnemy->ReceiveAttack((numOfUnits), (attackPoint * 0.8)); 	
	else{																	// when two enemies are alived

		if (firstEnemy->GetName()=="Orcs" && secondEnemy->GetName()=="Elves" && firstEnemy->IsAlive() && secondEnemy->IsAlive())
		{
			firstEnemy->ReceiveAttack((numOfUnits - (numOfUnits * 50)/100), (attackPoint * 0.8)); 	// attacking to Orc by Dwarves
			secondEnemy->ReceiveAttack((numOfUnits - (numOfUnits * 50)/100), (attackPoint * 0.75));	// attacking to Elves by Dwarves
		}
		if (firstEnemy->GetName()=="Elves" && secondEnemy->GetName()=="Orcs" && firstEnemy->IsAlive() && secondEnemy->IsAlive())
		{
			firstEnemy->ReceiveAttack((numOfUnits - (numOfUnits * 50)/100), (attackPoint * 0.75));		// attacking to Elves by Dwarves
			secondEnemy->ReceiveAttack((numOfUnits - (numOfUnits * 50)/100), (attackPoint * 0.8));		// attacking to Orc by Dwarves
		}
	}
}
void Dwarves::ReceiveAttack(double incomingUnit, double incomingAttackPoint)  {
	int deadUnit = (incomingUnit*incomingAttackPoint)/healthPoint;
	numOfUnits -= deadUnit;
}
int Dwarves::PurchaseWeapons(int Weaponamount) {
	attackPoint += Weaponamount;
	return (Weaponamount*10);
}
int Dwarves::PurchaseArmors(int Armoramount) {
	healthPoint += Armoramount*2;
	return (Armoramount*3);
}