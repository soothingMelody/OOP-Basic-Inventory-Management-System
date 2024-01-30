#include "header.h"
#include "item.h"
#include "armor.h"
#include "weapon.h"
#include <iterator>

std::vector<Item*> inventory;

void printDivider(){
    printf("\n--------------------------------------------------\n");
}

void printWelcomeScreen(){
    printDivider();
    printf("Welcome to the IMS1.0 (Inventory Management System 1.0).\n");
    printf("Menu Options:\n1 - Display the Inventory\n2 - Item Management\n3 - Save/Load Inventory from File\n4 - Exit\n");
    printf("What do you want to do? Input a number corresponding to the menu options: ");
}

void displayItemInfo(Item* y){
    if(y->getType() == "weapon" ){
        Weapon* weaponPtr = dynamic_cast<Weapon*>(y);
        Weapon x = *weaponPtr;
        printDivider();
        
        std::cout << "Name: " << x.getName() << "\nType: " << x.getType() << "\nWeapon Type: " << x.getWeaponType() << "\nStrength: " 
        << x.getStrength() << "\nAttack: " << x.getAttack() << "\n Weight: " << x.getWeight(); 
        
        printDivider();
    }
    else if(y->getType() == "armor"){
        Armor* armorPtr = dynamic_cast<Armor*>(y);
        Armor x = *armorPtr;
        printDivider();
        std::cout << "Name: " << x.getName() << "\nType: " << x.getType() << "\nArmor Type: "<< x.getArmorType() << "\nPhysical Defense: " 
        << x.getPhysResist() << "\nMagical Defense: " << x.getMagicResist() << "\nWeight: " << x.getWeight(); 
        printDivider();
    }
    else{
        printDivider();
        Item x = *y;
        std::cout << "Name: " << x.getName() << "\nType: " << x.getType() << "\nWeight: " << x.getWeight();
        printDivider();
    }
}

void displayInventory(){
    printDivider();
    printf("---INVENTORY CONTENTS:---");
    for (Item* itemPtr : inventory){
        displayItemInfo(itemPtr);
    }
}

void addItem(){
    printDivider();
    int choicex;
    printf("What kind of item do you want to add? ITEM(1), WEAPON(2), ARMOR(3). Type in the corresponding number: ");
    std::cin >> choicex;
    printDivider();
    if (choicex == 1){
        std::string typex = "item";
        std::string namex;
        float weightx;
        printf("Type in your item's name: ");
        std::cin >> namex;
        printf("\nType in your item's weight (float value): ");
        std::cin >> weightx;

        Item* itemPtr = new Item(namex, typex, weightx);
        inventory.push_back(itemPtr);
        displayItemInfo(inventory.back());
    }
    else if (choicex == 2){
        std::string typex = "weapon";
        std::string namex;
        float weightx;
        std::string weaponTypex;
        int strengthx;
        int attackx;

        printf("Type in your weapon's name: ");
        std::cin >> namex;
        printf("\nType in your weapon's type: ");
        std::cin >> weaponTypex;
        printf("\nType in your weapon's strength stat: ");
        std::cin >> strengthx;
        printf("\nType in your weapon's attack stat: ");
        std::cin >> attackx;
        printf("\nType in your weapon's weight (float value): ");
        std::cin >> weightx;

        Weapon* weaponPtr = new Weapon(namex, typex, weightx, weaponTypex, strengthx, attackx);
        inventory.push_back(weaponPtr);
        displayItemInfo(inventory.back());
    }
    else if (choicex == 3){
        std::string typex = "armor";
        std::string namex;
        float weightx;
        std::string armorTypex;
        int physResistx;
        int magicResistx;

        printf("Type in your Armor's name: ");
        std::cin >> namex;
        printf("Type in your Armor's armor type: ");
        std::cin >> armorTypex;
        printf("Type in your Armor's physical defense stat: ");
        std::cin >> physResistx;
        printf("Type in your Armor's magical defense stat: ");
        std::cin >> magicResistx;
        printf("\nType in your Armor's weight (float value): ");
        std::cin >> weightx;

        Armor* armorPtr = new Armor(namex, typex, weightx, armorTypex, physResistx, magicResistx);
        inventory.push_back(armorPtr);
        displayItemInfo(inventory.back());
    }
    else{
        printf("\nThe choice you've made is invalid...\n");
    }
}

void removeItem() {
    std::string namex;
    printf("\nEnter the name of the item you want to remove: ");
    std::cin >> namex;
    
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if ((*it)->getName() == namex) {
            std::string nameofItem = (*it)->getName();
            delete *it; // delete dynamically allocated memory
            inventory.erase(it);
            std::cout << "\nDeleted " << nameofItem << " item from inventory.\n";
            return;
        }
    }

    std::cout << "Item '" << namex << "' not found in inventory.\n";
}

void saveToFile(){
    std::string filename;
    printDivider();
    printf("Type in the name of the file you want to save the current state of the inventory to (include .txt): ");
    std::cin >> filename;
    saveToFile_sub(filename);
    printDivider();
}

void saveToFile_sub(std::string filename){
    std::ofstream outputFile(filename);
    if(outputFile.is_open()){
        for(const Item* itemPtr : inventory){
            outputFile << *itemPtr << std::endl;
        }
        outputFile.close();
        std::cout << "\nInventory successfully saved in " << filename << ". ";
    }
    else{
        printf("\nERROR OPENING FILE FOR WRITING.\n");
    }
}

void loadFromFile(){
    std::string filename;
    printDivider();
    printf("Type in the name of the file you want to load from: \n"); 
    std::cin >> filename;

    saveToFile_sub("backup.txt");

    cleanupInventory();
    inventory.shrink_to_fit();

    std::ifstream inputFile(filename);
    if(inputFile.is_open()){
        std::string line;
        while(std::getline(inputFile, line)){
            std::istringstream iss(line);
            std::string param;
            std::vector<std::string> itemParam; //list of parameters (Healing Potion item 3.5)
            while(std::getline(iss, param, delimiter)){
                itemParam.push_back(param);
            }

            if(itemParam[1] == "item"){
                Item* addedItem = new Item(itemParam[0], itemParam[1], std::stof(itemParam[2]));
                inventory.push_back(addedItem);
            }
            else if(itemParam[1] == "weapon"){
                Weapon* addedItem = new Weapon(itemParam[0], itemParam[1], std::stof(itemParam[2]), itemParam[3], std::stoi(itemParam[4]), std::stoi(itemParam[5]));
                inventory.push_back(addedItem);
            }
            else if(itemParam[1] == "armor"){
                Armor* addedItem = new Armor(itemParam[0], itemParam[1], std::stof(itemParam[2]), itemParam[3], std::stoi(itemParam[4]), std::stoi(itemParam[5]));
                inventory.push_back(addedItem);
            }
            else{
                printf("One item could not be loaded due to improper formatting.\n");
            }
        }
    }
    else{
        printf("/nERROR OPENING FILE.\n");
        }
}

void cleanupInventory() {
    for (Item* itemPtr : inventory) {
        delete itemPtr; // Delete each dynamically allocated Item object
    }
    inventory.clear(); // Clear the vector (optional)
}
