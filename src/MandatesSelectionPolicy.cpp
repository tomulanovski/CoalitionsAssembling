#include "SelectionPolicy.h"
#include "Graph.h"
#include <vector>
using std::vector;

MandatesSelectionPolicy:: ~MandatesSelectionPolicy() {}

int MandatesSelectionPolicy:: Select(vector<int> v , Graph g) {
    int maxParty=-1;
    int toreturn=1000;
    for (int i=1;(unsigned )i<v.size();i++) {
        int partyMandates = g.getParty(i).getMandates();
        if (partyMandates == maxParty) {
            toreturn  = std::min(v[i],toreturn);
        }
        else if(partyMandates > maxParty) {
            maxParty = partyMandates;
            toreturn  = v[i];
        }

    }
    return toreturn;
}

MandatesSelectionPolicy* MandatesSelectionPolicy::Clone() {return new MandatesSelectionPolicy(*this);}
