/*	Talha Sezer Çakır
	150180027
*/
#include "Faction.h"
#include "Orcs.h"

//constructor
Orcs::Orcs(const string& name,int numOfUnits, int attackPoint, int healthPoint, int unitRegen):Faction(name,numOfUnits,attackPoint,
																healthPoint,unitRegen,healthPoint*numOfUnits){
										
}

void Orcs::Print() {
	cout<< "\"Stop running, you'll only die tired!\"" << endl;
	cout<< "Faction Name: " << name <<endl;
	cout<< "Status: " << getStatus() <<endl;  
	cout<< "Number of Units: " << numOfUnits <<endl;
	cout<< "Attack Point: " << attackPoint<<endl;
	cout<< "Health Point: " <<  healthPoint <<endl;
	cout<< "Unit Regen Number: " << unitRegen <<endl;
	cout<< "Total Faction Health: " << totalHealth <<endl;
}
void Orcs::PerformAttack()  {
	if (secondEnemy->GetName()== "Dwarves" && !(firstEnemy->IsAlive()))
		secondEnemy->ReceiveAttack((numOfUnits) , (attackPoint));				// attacking to Dwarves by Orcs
	if (secondEnemy->GetName()=="Elves" && !(firstEnemy->IsAlive()))	
		secondEnemy->ReceiveAttack((numOfUnits) , attackPoint * 1.25);			// attacking to Elves by Orsc
	if (firstEnemy->GetName()=="Dwarves" && !secondEnemy->IsAlive())
		firstEnemy->ReceiveAttack((numOfUnits) , (attackPoint));				// attacking to Dwarves by Orcs
	if (firstEnemy->GetName() == "Elves" && !secondEnemy->IsAlive())	
		firstEnemy->ReceiveAttack((numOfUnits) , attackPoint * 1.25);			// attacking to Elves by Orsc
	else{
		if (firstEnemy->GetName()=="Elves" && secondEnemy->GetName()=="Dwarves" && firstEnemy->IsAlive() && secondEnemy->IsAlive())
		{
			firstEnemy->ReceiveAttack(numOfUnits - ((numOfUnits * 30)/100) , (attackPoint * (1.25))); 	// attacking to Elves by Orsc
			secondEnemy->ReceiveAttack(numOfUnits - ((numOfUnits * 70)/100) , (attackPoint));			// attacking to Elves by Dwarves
		}
		if (firstEnemy->GetName()=="Elves" && secondEnemy->GetName()=="Orcs" && firstEnemy->IsAlive() && secondEnemy->IsAlive())
		{
			firstEnemy->ReceiveAttack(numOfUnits - ((numOfUnits * 70)/100) , (attackPoint));	
			secondEnemy->ReceiveAttack(numOfUnits - ((numOfUnits * 30)/100) , (attackPoint * (1.25))); 	
		}
	}

}
void Orcs::ReceiveAttack(double incomingUnit, double incomingAttackPoint)  {
	int deadUnit = (incomingUnit*incomingAttackPoint)/healthPoint;
	numOfUnits -= deadUnit;
}
int Orcs::PurchaseWeapons(int Weaponamount) {
	attackPoint += Weaponamount*2;
	return (Weaponamount*20);
}
int Orcs::PurchaseArmors(int Armoramount)  {
	healthPoint += Armoramount*3;
	return (Armoramount);
}