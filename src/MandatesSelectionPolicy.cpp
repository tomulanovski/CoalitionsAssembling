#include "SelectionPolicy.h"
#include "Graph.h"
#include <vector>
using std::vector;

MandatesSelectionPolicy:: ~MandatesSelectionPolicy() {}

int MandatesSelectionPolicy:: Select(vector<int> v , Graph g) {
    int max=-1;
    for (int i=1;(unsigned )i<v.size();i++) {
        int partyMandates = g.getParty(i).getMandates();
        if (partyMandates > max)
            max = i;
    }
    return max;
}

MandatesSelectionPolicy* MandatesSelectionPolicy::Clone() {return new MandatesSelectionPolicy(*this);}
