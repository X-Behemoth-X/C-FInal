#ifndef BLACKSMITH_H
#define BLACKSMITH_H

#include <string>
using namespace std;

struct Item {
    string name;
    string type;
    int quantity;
    float price;
};

void displayMenu();
void showInventory(Item items[], int size);
void purchaseRandomItems(Item items[], int &size);
void restock(Item items[], int size);
void saveInventory(Item items[], int size, const string& filename);
void loadInventory(Item items[], int &size, const string& filename);

void displayItem(const Item& item);
void displayItem(const Item& item, bool showStats);

#endif