#ifndef ARMOR_H
#define ARMOR_H

#include "item.h"

class Armor : public Item{
    std::string armorType;
    int physResist;
    int magicResist;
    
    std::ostream& printToStream(std::ostream& os) const {
        os << getName() << delimiter << getType() << delimiter << getWeight() << delimiter << getArmorType() << delimiter << getPhysResist() << delimiter << getMagicResist();
        return os;
    };

    public:
    std::string getArmorType() const { return armorType; }
    int getPhysResist() const { return physResist; }
    int getMagicResist() const { return magicResist; }

    Armor(std::string namez, std::string typez, float weightz, std::string armorTypez, int physResistz, int magicResistz)
    : Item(namez, typez, weightz), armorType(armorTypez), physResist(physResistz), magicResist(magicResistz){
        std::cout << "Armor Created: " << getName() << std::endl;
    }
};

#endif