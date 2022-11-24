#include "JoinPolicy.h"
#include <vector>
using std::vector;

MandatesJoinPolicy::~MandatesJoinPolicy() {}
 int MandatesJoinPolicy:: Join(vector<int> MandatesByCoalitions) {
    int maxMandates= -1;
    int toreturn=1000;
    for ( int i=0;(unsigned )i<MandatesByCoalitions.size();i++) {
        if (MandatesByCoalitions[i]==maxMandates) {
            toreturn=std::min(i,toreturn);
        }
        else if (MandatesByCoalitions[i]>maxMandates) {
             maxMandates = MandatesByCoalitions[i];
            toreturn=i;
        }
    }
    return toreturn;
}

MandatesJoinPolicy* MandatesJoinPolicy::Clone() {return new MandatesJoinPolicy(*this);}