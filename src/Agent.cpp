#include "Agent.h"
#include "Simulation.h"
#include "vector"
#include "Party.h"
#include "SelectionPolicy.h"
using std::vector;
Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy) , Coalition(agentId)
{
    // You can change the implementation of the constructor, but not the signature!ok
}
Agent::~Agent() { if  (mSelectionPolicy) delete mSelectionPolicy; } // destructor
Agent:: Agent ( const Agent &a) : mAgentId(a.mAgentId) , mPartyId(a.mPartyId) , mSelectionPolicy(a.mSelectionPolicy->Clone()) , Coalition(a.Coalition) { // copy constructor
}
Agent:: Agent (Agent &&a) : mAgentId(a.mAgentId) , mPartyId(a.mPartyId) , mSelectionPolicy(a.mSelectionPolicy) , Coalition(a.Coalition)  { //Move constructor
a.mSelectionPolicy= nullptr;
}
Agent& Agent::operator=(const Agent &a) { // copy assignment
        mAgentId = a.mAgentId;
        mPartyId = a.mPartyId;
        *mSelectionPolicy = *a.mSelectionPolicy;
        Coalition = a.Coalition;
        return *this;
}
Agent& Agent::operator=(Agent &&a) { //move assignment
    if (this != &a) {
        if (mSelectionPolicy) delete mSelectionPolicy;
        mAgentId = a.mAgentId;
        mPartyId = a.mPartyId;
        mSelectionPolicy = a.mSelectionPolicy;
        a.mSelectionPolicy = nullptr;
        Coalition = a.Coalition;
    }
        return *this;
}

    int Agent::getId() const {
        return mAgentId;
    }

    int Agent::getPartyId() const {
        return mPartyId;
    }

    void Agent::step(Simulation &sim) {
        Graph g = sim.getGraph();
        vector<int> tooffer;
        tooffer.push_back(mPartyId);
        for (int i = 0; i < g.getNumVertices(); i++) {
            Party p = g.getParty(i);
            if (g.getEdgeWeight(i, mPartyId) > 0) {
                if (p.getState() != Joined) {
                    vector<int> offers = p.getOffers();
                    bool offered = false;
                    for (int j = 0; (unsigned) j < offers.size() &&
                                    !offered; j++) { //checking if the party got an offer from agent coalition
                        if (offers[j] == Coalition)
                            offered = true;
                    }
                    if (!offered)
                        tooffer.push_back(p.getid());
                }
            }
        }
        if (tooffer.size() > 1) { //there is a party to offer to
            int choose = mSelectionPolicy->Select(tooffer, g); //the party which we offfer to join
            sim.updateoffer(choose ,Coalition);
            // Party chosen = g.getParty(choose);
            // chosen.AddOffer(Coalition);
            // if (chosen.getState() != CollectingOffers)
            //     chosen.setState(CollectingOffers);
        }

    }

    int Agent::getCoalition() const {
        return Coalition;
    }
    void Agent::setPartyId(int partyid) {
        mPartyId = partyid;
    }
    void Agent::setId(int Id) {
        mAgentId = Id;
    }

