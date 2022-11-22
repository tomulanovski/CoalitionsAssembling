#pragma once

#include <vector>
#include "Graph.h"

class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    virtual ~Agent(); //destructor
    Agent(const Agent &a); // copy constructor
    Agent(Agent &&a); // move constructor
    Agent& operator=(const Agent &a); // copy assignment
    Agent& operator=(Agent &&a); // move assignment
    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    int getCoalition() const;
    void setPartyId(int partyid);
    void setId (int);

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int Coalition;
};
