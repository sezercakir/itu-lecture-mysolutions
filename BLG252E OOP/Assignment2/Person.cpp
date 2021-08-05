/* Talha Sezer Çakır
    150180027 
*/
#include "Person.h"
using namespace std;

Person::Person(const string& Name, const string& Surname){
    name = Name;
    surname = Surname;
    next = NULL;
}
Person::Person(){
    name = "";
    surname = "";
    next = NULL;
}
Person::Person(const Person& in){
	name = in.name;
	surname = in.surname;
	next = in.next;
}


string Person::getName(){return name;}
string Person::getSurname(){return surname;}   

Passenger::Passenger() : Person(){
    cash = 0;
    ticket = false;
    next = NULL;
}

Passenger::Passenger(const string& name,const string& surname)
                                :Person(name,surname){
    cash = 0;
    ticket = false; 
    next = NULL;
}
Passenger::Passenger(const string& name,const string& surname,int Cash) 
                        : Person(name,surname){
    if(Cash < 0){
        cerr<< "Passenger cash can't be negative. It is set to 0."<<endl;
        cash = 0;
    }else{
        cash = Cash;
    }
    ticket = false;
    next = NULL;
}

Passenger::Passenger(const Passenger& in,bool F):Person(in){
    if (F==false)
        next = NULL;
    else
        next = in.next;
	ticket = in.ticket;
	cash = in.cash;
}

int Passenger::getCash(){return cash;};
void Passenger::setCash(int Cash){cash = Cash;};
void Passenger::setTicket(bool F){ticket = F;};
bool Passenger::buyTicket(int price){
	cash < (price) ? ticket = false : ticket = true; 
	return ticket;
}
bool Passenger::getTicket(){return ticket;}

Astronaut::Astronaut(const string& name,const string& surname, int NumMissions) 
                                : Person(name,surname){
    
    numMissions = NumMissions;
    if(numMissions < 0){
        cerr << "Number of missions that astronaut completed can't be negative. It is set to 0." <<endl;
        numMissions = 0;
    }
    next = NULL;
}


Astronaut::Astronaut() : Person(){
    numMissions = 0;
    next = NULL;
}
void Astronaut::completeMission(){numMissions++;};


Astronaut::Astronaut(const Astronaut& in,bool F):Person(in){
    numMissions = in.numMissions;
    if (F==false)
        next = NULL;
    else
        next = in.next;
    
	
}

int Astronaut::getNumMissions(){return numMissions;}
void Astronaut::setNumMissions(int N){numMissions = N;};