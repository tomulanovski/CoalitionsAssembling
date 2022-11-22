#include "JoinPolicy.h"
#include <vector>
using std::vector;

LastOfferJoinPolicy:: ~LastOfferJoinPolicy() {}

int LastOfferJoinPolicy::Join(vector<int> MandatesByCoalitions ){
    return MandatesByCoalitions.size()-1; //returning the last object in the vector
}

LastOfferJoinPolicy* LastOfferJoinPolicy::Clone() {return new LastOfferJoinPolicy(*this);}