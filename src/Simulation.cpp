#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) , Coalitions()
{
    for (int i=0;(unsigned)i<mAgents.size();i++) {
        int Partyid = mAgents[i].getPartyId();
        mGraph.getParty(Partyid).setCoalition(i);
        Coalitions.push_back(mGraph.getParty(Partyid).getMandates());
    }
}

void Simulation::step()
{
    for (int v=0;v<mGraph.getNumVertices();v++) {
         mGraph.getParty(v).step(*this);
    }
        for (int i = 0; (unsigned )i < mAgents.size(); i++) {
            mAgents[i].step(*this);
        }
    }

void Simulation::updateoffer(int chosen, int Coalition) {
    mGraph.getParty(chosen).AddOffer(Coalition);
    if (mGraph.getParty(chosen).getState() != CollectingOffers)
      mGraph.getParty(chosen).setState(CollectingOffers);
}

bool Simulation::shouldTerminate() const
{
    int count=0;
    for (int c=0;(unsigned )c<Coalitions.size() ;c++) {
        if (Coalitions[c]>60)
            return true;
        count = count+Coalitions[c];
    }
    if (count==120)
        return true;
    return false;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}
Graph &Simulation::getGraph() {
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}
int Simulation::getMandatesByCoalition(int Coalition) {
    return Coalitions[Coalition];
}

void Simulation :: UpdateCoalitionSize (int Coalition , int mandates) { //updating Coalitions Size
    Coalitions[Coalition] += mandates;
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    vector<vector<int>> partiesOfCoalitions;
    for (int i=0;(unsigned )i<Coalitions.size();i++) {
        vector<int>v;
        partiesOfCoalitions.push_back(v);
    }
    for(int i=0;(unsigned )i<mAgents.size();i++) {
        int Partyid= mAgents[i].getPartyId();
        int Coalitionid=mAgents[i].getCoalition();
        partiesOfCoalitions[Coalitionid].push_back(Partyid);
    }
    return partiesOfCoalitions;
}

void Simulation:: CloneAgent(int Coalition , int Partyid) {
    Agent a=(mAgents[Coalition]);
    a.setId(mAgents.size());
    a.setPartyId(Partyid);
    mAgents.push_back(a);
}