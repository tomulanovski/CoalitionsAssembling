#include "SelectionPolicy.h"
#include <vector>
#include "Graph.h"
using std::vector;

EdgeWeightSelectionPolicy:: ~EdgeWeightSelectionPolicy(){}

int EdgeWeightSelectionPolicy::Select(vector<int> parties , Graph g) {
int maxweight = -1;
int totreturn=1000; //giving max falue for min to work correctly
for (int i=1 ; (unsigned )i<parties.size();i++) {
    if (g.getEdgeWeight(parties[0],parties[i])>maxweight) {
        maxweight=g.getEdgeWeight(parties[0],parties[i]);
        totreturn= parties[i];
    }
    else if (g.getEdgeWeight(parties[0],parties[i])==maxweight) {
        totreturn=std::min (parties[i],totreturn);
    }
}
return totreturn;
}

EdgeWeightSelectionPolicy* EdgeWeightSelectionPolicy::Clone(){return new EdgeWeightSelectionPolicy(*this);}
