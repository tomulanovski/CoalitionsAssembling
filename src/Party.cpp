#include "Party.h"
#include <vector>
#include "Simulation.h"
#include "JoinPolicy.h"
using std::vector;


Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) ,
 Timer(0) , Coalition(-1) , CoalitionsOffers()
{}
Party::~Party() { //destructor
    if (mJoinPolicy) delete mJoinPolicy;
}
Party::Party(const Party &p) : mId(p.mId), mName(p.mName), mMandates(p.mMandates), mJoinPolicy(p.mJoinPolicy->Clone()), mState(p.mState) ,
Timer(p.Timer) , Coalition(p.Coalition) , CoalitionsOffers(p.CoalitionsOffers)  { //copy constructor

}
Party::Party(Party &&p) : mId(p.mId), mName(p.mName), mMandates(p.mMandates), mJoinPolicy(p.mJoinPolicy), mState(p.mState) ,
Timer(p.Timer) , Coalition(p.Coalition) , CoalitionsOffers(p.CoalitionsOffers) { //move constructor
    p.mJoinPolicy= nullptr;
}
Party& Party:: operator=(const Party &p) { //copy assignment
    if (this != &p) {
        mId = p.mId;
        mName = p.mName;
        mMandates = p.mMandates;
        *mJoinPolicy = *p.mJoinPolicy;
        mState = p.mState;
        CoalitionsOffers = p.CoalitionsOffers;
        Timer = p.Timer;
        Coalition = p.Coalition;
    }
        return *this;
}
Party& Party:: operator=(Party &&p) { //move assignment
    if (mJoinPolicy) delete mJoinPolicy;
    mId=p.mId;
    mName=p.mName;
    mMandates=p.mMandates;
    mJoinPolicy = p.mJoinPolicy;
    p.mJoinPolicy=nullptr;
    mState = p.mState;
    CoalitionsOffers = p.CoalitionsOffers;
    Timer = p.Timer;
    Coalition = p.Coalition;
    return *this;
}
State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party::step(Simulation &s)
{
    if(mState==CollectingOffers) {
        if (Timer<2)
            Timer++;
        else {
            vector<int>mandates;
            for(int i=0;(unsigned)i<CoalitionsOffers.size();i++) {
                mandates.push_back(s.getMandatesByCoalition(CoalitionsOffers[i]));
            }
            int coalition = mJoinPolicy->Join(mandates);
            mState=Joined;
            Coalition=CoalitionsOffers[coalition];
            s.UpdateCoalitionSize(Coalition,mMandates);
            s.CloneAgent(Coalition,mId);

        }
    }
}

void Party::AddOffer(int Coalition){ //adding the offer to the vector
    CoalitionsOffers.push_back(Coalition);
};

void Party::setTimer() {
    Timer++;
}

void Party::setCoalition(int &Coalition) {
    this->Coalition = Coalition;
}
vector<int> Party::getOffers() {
    return CoalitionsOffers;
}
int Party::getid(){
    return mId;
}
