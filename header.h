#ifndef HEADER_H
#define HEADER_H

#include <fstream> //file stuff
#include <iostream> //C++ yaaaaa
#include <vector> //for work with vectors
#include <sstream>
#include <string> //work with strings
#include <cstdio> //for C functions

const char delimiter = ','; //for writing and loading from files. This will signify what the parameters are separated by

void printDivider(); //prints a divider, cosmetic
void printWelcomeScreen(); //prints the main menu
void addItem(); //creates any sort of item and then adds it to the inventory vector
void removeItem(); //removes an item from the inventory vector by name
void displayInventory(); // displays the inventory in detail
void saveToFile(); //Saves current Inventory state to file
void saveToFile_sub(std::string filename); //the actual saving function
void loadFromFile(); //Loads Inventory state from file
void cleanupInventory(); //cleans up the pointer vector



#endif