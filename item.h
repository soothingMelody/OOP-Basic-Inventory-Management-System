#ifndef ITEM_H
#define ITEM_H

#include "header.h"

class Item{
    std::string type;    
    std::string name;
    float weight;

    virtual std::ostream& printToStream(std::ostream& os) const {
        os << getName() << delimiter << getType() << delimiter << getWeight();
        return os;
    };
    
    public:
    std::string getName() const { return name; }
    std::string getType() const { return type; }
    float getWeight() const { return weight; }

    Item(std::string namez, std::string typez, float weightz): type(typez), name(namez), weight(weightz){
        std::cout << "Item Created: " << getName() << std::endl;
    }
    // << operator for Item class now returns the items parameters
    friend std::ostream& operator << (std::ostream& os, const Item& x) {
        x.printToStream(os);
        return os;
    }
};

void displayItemInfo(Item& y); //displays every item parameter

#endif