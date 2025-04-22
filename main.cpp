#include "blacksmith.h"
#include <iostream>
using namespace std;

int main() {
    const int MAX_ITEMS = 100;
    Item inventory[MAX_ITEMS] = {
        {"Iron Sword", "Sword", 15, 120.0},
        {"Steel Shield", "Shield", 10, 140.0},
        {"Longbow", "Bow", 8, 160.0},
        {"Leather Armor", "Armor", 5, 180.0},
        {"Arrows", "Ammunition", 100, 2.5},
        {"War Axe", "Axe", 7, 200.0},
        {"Crossbow", "Bow", 6, 220.0},
        {"Chainmail Armor", "Armor", 3, 300.0},
        {"Battle Hammer", "Blunt", 4, 250.0},
        {"Throwing Knives", "Knife", 25, 20.0}
    };
    int itemCount = 10;    

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: showInventory(inventory, itemCount); break;
            case 2: purchaseRandomItems(inventory, itemCount); break;
            case 3: restock(inventory, itemCount); break;
            case 4: saveInventory(inventory, itemCount, "inventory.txt"); break;
            case 5: loadInventory(inventory, itemCount, "inventory.txt"); break;
            case 0: cout << "Exiting... Farewell, brave merchant!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}