/* Talha Sezer Çakır
    150180027 
*/
#pragma once
using namespace std;
#include <string>
#include "Person.h"
class Mission
{
private:
    string name;
	int missionNumber;
	int cost;
	int faultProbability;
	bool completed;
	static int numMissions;
	int passengersSize;
	int crewSize;	
	Passenger* passengersHead;
	Astronaut* crewHead;
public:
    Mission();
    ~Mission();
    Mission(const Mission&);
    Mission(const string&,int,int);
    int getCrewSize();
    void setMissionnumer(int);
    void setCompleted(bool);
    int getpassengerSize();
    int getFaultProbabilty();
    int getCost();
    bool getCompleted();
    int getMissionNumber();
    string getName();
    void operator+=(Passenger*);
    void operator+=(Astronaut*);
    void operator=(Mission*);
    void setName(const string&);
    void setCost(int);
    void setFaultProbability(int);
    bool executeMission();
    int calculateProfit(int);
    Mission* next;

};