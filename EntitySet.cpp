//
// Created by gmook on 4/2/2021.
//
#include <iostream>
#include "EntitySet.hpp"

//Constructor
EntitySet::EntitySet() {
}

void EntitySet::setterForMatrix(std::vector<std::pair<std::string, double>> settingMatrix) {
    currentMatrix = settingMatrix;
}

std::vector<std::pair<std::string, double>> EntitySet::getterForMatrix() {
    return currentMatrix;
}

void EntitySet::addEntity(EntityInstance &entityInstance) {
    instances.push_back(entityInstance);
}

void EntitySet::print() {
    std::cout << "[" << std::endl;
    for(int i = 0; i < instances.size(); i++) {
       int last = instances.size() - 1;
        if(i == last)
            instances.at(i).print(5,false);
        else
            instances.at(i).print(5, true);
    }
    std::cout << "]" << std::endl;
}
