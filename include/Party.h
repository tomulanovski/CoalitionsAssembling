#pragma once
#include <string>
#include <vector>

using std::vector;
using std::string;

class JoinPolicy;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *);
    virtual ~Party(); //destructor
    Party(const Party &p); //copy constructor
    Party(Party &&p); // move constructor
    Party& operator=(const Party &p); //copy assignment
    Party& operator=(Party &&p); // move assignment
    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    void AddOffer(int Coalition);
    void setTimer();
    void setCoalition(int &Coalition);
    vector<int> getOffers();
    int getid();

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int Timer;
    int Coalition;
    vector<int> CoalitionsOffers;

};
