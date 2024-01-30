#include "header.h"
#include "item.h"

int main() {
    int state = 0;
    while (state != 4){
        printWelcomeScreen();
        std::cin >> state;
        switch(state){
            case 1:
                displayInventory();
                break;
            case 2:
                int choice1;
                printDivider();
                printf("Do you want to ADD(1) or REMOVE(2) an item? Type in the corresponding number: ");
                std::cin >> choice1;
                if(choice1 == 1){
                    addItem();
                }
                else if(choice1 == 2){
                    removeItem();
                }
                else{
                    printf("Invalid Choice\n");
                }
                break;
            case 3:
                int choice2;
                printDivider();
                printf("Do you want to SAVE(1) to file or LOAD(2) from file? Type in the corresponding number: ");
                std::cin >> choice2;
                if(choice2 == 1){
                    saveToFile();
                }

                else if(choice2 == 2){
                    loadFromFile();
                }
                else{
                    printf("Invalid Choice\n");
                }
                break;
            case 4:
                printf("\nExiting the application...\n");
                break;
            default:
                printf("\nInvalid Choice\n");
        }
    }
    cleanupInventory();
    return 0;
}