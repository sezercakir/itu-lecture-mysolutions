/* Talha Sezer Çakır
    150180027 
*/
#pragma once
#include "Mission.h"

class Agency
{
private:
    string name;
    int cash;
    int ticketPrice;
    Mission *completedMissions;
    Mission *nextMissions;
public:
    Agency(const string&, int,int);
    Agency();
    ~Agency();
    string getName();
    int getCash();
    void setName(const string&);
    void setCash(int);
    int getTicketPrice(); 
    void setTicketPrice(int);
    void addMission(const Mission&);
    
    void executeNextMission();
    friend ostream& operator<< (ostream&, const Agency&); 

};

