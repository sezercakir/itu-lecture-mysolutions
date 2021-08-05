/* Talha Sezer Çakır
    150180027 
*/
#pragma once
#include <iostream>
using namespace std;
#include <string>


class Person{
    string name;
    string surname;  
public:
    Person(const string&,const string&);
    Person(); 
    Person(const Person&); 
    string getName();
    string getSurname();
    void setName(const string&);
    void setSurname(const string&);
    Person* next;
};

class Passenger : public Person{ //public derivation from Person class
    int cash;
    bool ticket;
public:
    Passenger(const string&, const string&,int);
    Passenger(const string&,const string&);
    Passenger();
    Passenger(const Passenger&,bool);
    Passenger* next;
    bool buyTicket(int);
    int getCash();
    bool getTicket();
    void setCash(int);
    void setTicket(bool);
};

class Astronaut : public Person{ //public derivation from Person class
    int numMissions;
public:
    Astronaut(const string&,const string&,int=0);
    Astronaut();
    Astronaut* next;
    void completeMission();
    Astronaut(const Astronaut&,bool);
    int getNumMissions();
    void setNumMissions(int);
};



