#include "JoinPolicy.h"
#include <vector>
using std::vector;

MandatesJoinPolicy::~MandatesJoinPolicy() {}
 int MandatesJoinPolicy:: Join(vector<int> MandatesByCoalitions ){
    int max= -1;
    for ( int i=0;(unsigned )i<MandatesByCoalitions.size();i++) {
        if (MandatesByCoalitions[i]>max)
            max=i;
    }
    return max;
}

MandatesJoinPolicy* MandatesJoinPolicy::Clone() {return new MandatesJoinPolicy(*this);}