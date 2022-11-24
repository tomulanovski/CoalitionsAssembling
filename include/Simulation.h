#pragma once

#include <vector>

#include "Graph.h"
#include "Agent.h"

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    void updateoffer(int chosen,int Coalition);
    bool shouldTerminate() const;
    const Graph &getGraph() const;
    Graph &getGraph();
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    void UpdateCoalitionSize (int Coalition , int mandates);
    int getMandatesByCoalition(int Coalition);
    void CloneAgent(int Coalition , int Partyid);

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<int> Coalitions;
};
