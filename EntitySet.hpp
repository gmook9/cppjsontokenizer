//
// Created by gmook on 4/7/2021.
//

#ifndef P3P2_ENTITYSET_HPP
#define P3P2_ENTITYSET_HPP



#include <vector>
#include "EntityInstance.hpp"

class EntitySet {
public:
    EntitySet();
    void setterForMatrix(std::vector<std::pair<std::string, double>>);
    std::vector<std::pair<std::string, double>> getterForMatrix();
    void addEntity(EntityInstance &);
    void print();

private:
    std::vector<EntityInstance> instances;
    std::vector<std::pair<std::string, double>> currentMatrix;
};


#endif //P3P2_ENTITYSET_HPP
