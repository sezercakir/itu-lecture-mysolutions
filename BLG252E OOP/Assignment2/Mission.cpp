/* Talha Sezer Çakır
    150180027 
*/
#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

#include "Mission.h"
using namespace std;
Mission::Mission(){
    name = "";
    cost = 0;
    faultProbability = 0;
    missionNumber = 0;
    passengersSize = 0;
    crewSize = 0;
    completed = false;
    passengersHead = NULL;
    crewHead = NULL;
    
}

Mission::Mission(const string& Name,int Cost, int FaultProbability){
	int pos = Name.find("-");
	if (pos!=-1 && pos==2 && Name.size() == 5 && isupper(Name[0]) && isupper(Name[1]) && isdigit(Name[3]) && isdigit(Name[4]))
	{	
		name = Name;
	}
	else{
		cout<<"Given name does not satisfy the mission naming convention. Please set a new name!"<<endl;
		name = "AA-00";
	}
    
    numMissions++;
	missionNumber = numMissions;
    completed = false;
	cost = Cost;
	faultProbability = FaultProbability; 
	passengersHead = NULL;
	crewHead = NULL;
	passengersSize = 0;
	crewSize = 0;				
}

Mission::Mission(const Mission& in){
    name = in.name;
    missionNumber = in.missionNumber;
    numMissions = in.numMissions;
    cost = in.cost;
    completed = in.completed;
    crewSize = in.crewSize;
    passengersSize = in.passengersSize; 
    faultProbability = in.faultProbability;
    passengersHead = in.passengersHead;
    crewHead = in.crewHead;
    
}

Mission::~Mission(){
    if(crewHead == NULL && passengersHead == NULL ){
        return;
    }
    if(passengersHead != NULL){
        
        Passenger *del = passengersHead;
        while(del!=NULL){
            Passenger *temp = del->next;
            delete del; 
            del = temp;
        }
        passengersHead = NULL;
        
    }
    if(crewHead != NULL){
        Astronaut *del = crewHead;
        while(del!=NULL){
            
            Astronaut *temp = del->next;
            delete del;
            del = temp;
        }
        crewHead = NULL;
    }
}

void Mission::operator+=(Passenger* in_passenger){
    if(in_passenger->getTicket()){
        Passenger* tmp = new Passenger(*in_passenger,false);
        if(passengersHead==NULL)
            passengersHead = tmp;
        else{
            Passenger *temp2 = passengersHead;
            while(temp2->next!=NULL)
                temp2 = temp2->next;
            temp2->next = tmp;
        }
        passengersSize++;
    }
    else{
        cerr<<"Passenger "<<in_passenger->getName() << " " << in_passenger->getSurname()<<" does not have a valid ticket!"<<endl;
        return;
    }
}

void Mission::operator+=(Astronaut* in_astronaut){
    Astronaut* temp = new Astronaut(*in_astronaut,false);
    if (crewHead==NULL)
    {
        crewHead = temp;
        crewSize++;
        return;
    }
    else{
        Astronaut* iterator = crewHead;
        while(iterator->next!=NULL)
            iterator = iterator->next;
        iterator->next = temp;
        
    }
    crewSize++;
}

void Mission::operator=(Mission* in_mission){
    name = in_mission->name;
    missionNumber = in_mission->missionNumber;
    numMissions = in_mission->numMissions;
    cost = in_mission->cost;
    completed = in_mission->completed;
    crewSize = 0;
    passengersSize = 0; 
    faultProbability = in_mission->faultProbability;
    passengersHead = NULL;
    crewHead = NULL;
    Passenger *iteratorPass = in_mission->passengersHead;
    Astronaut *iteratorAst = in_mission->crewHead;
    while(iteratorPass!=NULL){
            (*this)+= &(*iteratorPass);        
            iteratorPass = iteratorPass->next;
    }
    while(iteratorAst!=NULL){
            (*this)+= &(*iteratorAst);
            iteratorAst = iteratorAst->next;
    }
}


bool Mission::executeMission(){
    int randomNum = rand()%100;
    if (randomNum > faultProbability && faultProbability!=100)
    {   
        cout<<"MISSION " << name <<" SUCCESSFUL!"<<endl;
        completed = true;
        Astronaut* iterator = crewHead;
        while(iterator!=NULL){
           iterator->completeMission();
            cout << "Astronaut " << iterator->getName() << " " << iterator->getSurname()<< " successfully completed "<<iterator->getNumMissions() <<" missions."<<endl;
            iterator = iterator->next;
        }//Astronaut Neil Armstrong successfully completed 4 missions.
    }
    else{
        completed = false;
        cout<<"MISSION " << name <<" FAILED!"<<endl;
    }
    return completed;
}
int Mission::calculateProfit(int price){
	if (completed)
		return (passengersSize*price - cost);
	else
		return ( 0 - cost); 
}


int Mission::getMissionNumber(){ return missionNumber; }
void Mission::setCompleted(bool F){ completed = F; }
string Mission::getName(){return name; }
void Mission::setMissionnumer(int N){ missionNumber = N; }
int Mission::getCost(){ return cost; }

void Mission::setName(const string& Name){
    int pos = Name  .find("-");
	if (pos!=-1 && pos==2 && Name.size() == 5 && isupper(Name[0]) && isupper(Name[1]) && isdigit(Name[3]) && isdigit(Name[4]))
	{	
		name = Name;
	}
	else{
		cout<<"Given name does not satisfy the mission naming convention. Please set a new name!"<<endl;
		name = "AA-00";
	}
}
