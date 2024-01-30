#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"

class Weapon : public Item{
    std::string weaponType;
    int strength;
    int attack;

    std::ostream& printToStream(std::ostream& os) const {
        os << getName() << delimiter << getType() << delimiter << getWeight() << delimiter << getWeaponType() << delimiter << getStrength() << delimiter << getAttack();
        return os;
    };

    public:
    std::string getWeaponType() const { return weaponType; }
    int getStrength() const { return strength; }
    int getAttack() const { return attack; }

    Weapon(std::string namez, std::string typez, float weightz, std::string weaponTypez, int strengthz, int attackz)
    : Item(namez, typez, weightz), weaponType(weaponTypez), strength(strengthz), attack(attackz) {
        std::cout << "Weapon Created: " << getName() << std::endl;
    }

};

#endif