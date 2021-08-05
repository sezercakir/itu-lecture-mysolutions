/*  Talha Sezer Çakır
    150180027
*/
    
#include "Agency.h"

Agency::Agency(){
    name = "";
    ticketPrice = 0;
    cash = 0;
    completedMissions = NULL;
    nextMissions = NULL;
}

Agency::Agency(const string& Name,int Cash, int TicketPrice){
    name = Name;
    cash = Cash;
    ticketPrice = TicketPrice;
    if(ticketPrice < 0){
        cerr<<"Ticket price can't be negative. It is set to 0."<<endl;
        ticketPrice = 0;
    }
    completedMissions = NULL;
    nextMissions = NULL;
}

Agency::~Agency() {
    if(completedMissions == NULL && nextMissions == NULL){
        return;
    }
    if(nextMissions != NULL){
        nextMissions =NULL;
    }
    if(completedMissions != NULL){
        completedMissions = NULL;
    }
}

int Agency::getCash(){return cash;}
void Agency::setName(const string& Name){ name = Name;}
void Agency::setCash(int Cash){ cash = Cash;}
int Agency::getTicketPrice(){ return ticketPrice; }
void Agency::setTicketPrice(int Ticket){ ticketPrice = Ticket; }

void Agency::addMission(const Mission& in){
    Mission *temp = new Mission(in);
    if(nextMissions == NULL)
        nextMissions = temp;
    else
    {
        Mission *iterator = nextMissions;
        while(iterator->next!=NULL)         // adding end of the nextMissions linked lis
            iterator = iterator->next;
        iterator->next = temp;
    }

}

void Agency::executeNextMission(){
    if(nextMissions == NULL){
        cout<<"No available mission to execute!"<<endl;
        return;
    }
    bool success = nextMissions->executeMission();
    int profit = nextMissions->calculateProfit(ticketPrice);
    cash += profit;
    
    if(success){
        Mission *miss = nextMissions;
        nextMissions = nextMissions->next;
        if(completedMissions == NULL){
            completedMissions = miss;
            miss->next = NULL; 
        }else{
            miss->next = completedMissions;
            completedMissions = miss;
        }

    }else{
        cout<<"Agency reschedules the mission."<<endl;
        Mission temp;               
        temp  = nextMissions;       // operator= 
        addMission(temp);
        Mission *old = nextMissions->next;
        nextMissions = NULL; 
        nextMissions = old;
    }
}

ostream& operator<<(ostream &out, const Agency &in){
    out << "Agency name: " << in.name << ", Total cash: " << in.cash << ", Ticket Price: "<< in.ticketPrice<<endl;
    cout<<"Next Missions:"<<endl;
    if(in.nextMissions == NULL){
        out<<"No missions available."<<endl;
    }else{
        Mission *traverse = in.nextMissions;
        while(traverse){
            out<<"Mission number: "<<traverse->getMissionNumber()<<" Mission name: "
            << traverse->getName() << " Cost: "<<traverse->getCost()<<endl;
            traverse = traverse->next;
        }
    }
    out<<"Completed Missions:"<<endl;
    if(in.completedMissions == NULL){
        out<<"No missions completed before."<<endl;
    }else{
        Mission *traverse = in.completedMissions;
        while(traverse){
            out<<"Mission number: "<<traverse->getMissionNumber()<<" Mission name: "
            << traverse->getName() << " Cost: "<<traverse->getCost()<<endl;
            traverse = traverse->next;
        }
    }
    return out;
}
