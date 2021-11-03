//
// Created by gmook on 4/7/2021.
//

#ifndef P3P2_ENTITYINSTANCE_HPP
#define P3P2_ENTITYINSTANCE_HPP

#include <string>
#include <vector>
#include "Pair.hpp"

class EntityInstance {
public:
    void addPair(Pair &pair);
    int numAttributes();
    void print(int numSpaces, bool addComma);
    double locateGpa();
    std::string locateId();
private:
    std::vector<Pair> entityPairs;
};

#endif //P3P2_ENTITYINSTANCE_HPP
