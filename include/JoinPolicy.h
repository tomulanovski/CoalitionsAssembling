#pragma once
#include <vector>
#include "Party.h"
using std::vector;
class JoinPolicy {
    public:
    virtual ~JoinPolicy() = default;
    virtual int Join(vector<int>)=0;
    virtual JoinPolicy* Clone()=0;

};

class MandatesJoinPolicy : public JoinPolicy {
public:
   ~MandatesJoinPolicy() override;
   virtual int Join (vector<int> Offers);
    virtual MandatesJoinPolicy* Clone();
};

class LastOfferJoinPolicy : public JoinPolicy {
public:
   ~LastOfferJoinPolicy() override;
   virtual int Join (vector<int> Offers);
    virtual LastOfferJoinPolicy* Clone();
};
