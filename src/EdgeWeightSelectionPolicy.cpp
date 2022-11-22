#include "SelectionPolicy.h"
#include <vector>
#include "Graph.h"
using std::vector;

EdgeWeightSelectionPolicy:: ~EdgeWeightSelectionPolicy(){}

int EdgeWeightSelectionPolicy::Select(vector<int> parties , Graph g) {
int max = -1;
for (int i=1 ; (unsigned )i<parties.size();i++) {
    if (g.getEdgeWeight(0,i)>max)
        max=i;
}
return max;
}

EdgeWeightSelectionPolicy* EdgeWeightSelectionPolicy::Clone(){return new EdgeWeightSelectionPolicy(*this);}
