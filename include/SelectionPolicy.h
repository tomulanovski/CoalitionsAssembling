#pragma once
#include <vector>
#include "Graph.h"
using std::vector;

class SelectionPolicy {
public:
    virtual ~SelectionPolicy() = default;
    virtual int Select(vector<int> v , Graph g)=0;
    virtual SelectionPolicy* Clone() =0;

};

class MandatesSelectionPolicy: public SelectionPolicy{
public:

    ~MandatesSelectionPolicy() override;
   virtual int Select(vector<int> v , Graph g);
    virtual MandatesSelectionPolicy* Clone();
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
public:
    ~EdgeWeightSelectionPolicy() override;
    virtual int Select(vector<int> v , Graph g);
    virtual EdgeWeightSelectionPolicy* Clone();
};