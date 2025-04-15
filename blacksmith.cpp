#include "blacksmith.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

void displayMenu() {
    cout << "\n=== Blacksmith Menu ===\n";
    cout << "1. Show Inventory\n";
    cout << "2. Simulate Customer Purchase\n";
    cout << "3. Restock Items\n";
    cout << "4. Save Inventory\n";
    cout << "5. Load Imventory\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

void showInventory(Item items[] int size) {
    cout << "\n--- Current Inventory ---\n";
    for (int i = 0; i < size; ++i) {
        displayItem(items[i], true);
    }
}

void displayItem(const Item& item) {
    cout << item.name << " (" << item.type << ") - Qty: " << item.quantity << "\n";
}

void displayItem(const Item& item, bool showStats) {
    displayItem(item);
    if (showStats) {
        cout << " Price: " << item.price << " gold\n";
    }
}

void purchaseRandomItems(Item items[], int &size) {
    srand(time(0));
    int idx = rand() % size;
    int qty = 1 + rand() % 3;
    cout << "\nCustomer wants to buy " << qty << " " << items[idx].name << "(s).\n";

    if (items[idx].quantity >= qty) {
        items[idx].quantity -= qty;
        cout << "Purchase successful! " << items[idx].quantity << " remaining.\n";
    } else {
        cout << "Not enough stock. Only " << items[idx].quantity << " left.\n";
    }
}

void restock(Item items[], int size) {
    static int restockedCount = 0;
    if (restockedCount >= size) return;

    if (items[restockedCount].quantity < 5) {
        cout << "Restocking " << items[restockedCount].name << "...\n";
        items[restockedCount].quantity += 5;
    }
    restockedCount++;
    restock(items, size);
}

void saveInventory(Item items[], int size, const string& filename) {
    ofstream file(filename);
    for (int i = 0; i < size; ++i) {
        file << items[i].name << "," << items[i].type << "," << items[i].quantity << "," << items[i].price << "\n";
    }
    file.close();
    cout << "Inventory saved to " << filename << "\n";
}

void loadInventory(Item items[], int &size, const string& filename) {
    ifstream file(filename);
    size = 0;
    while (file && size < 100) {
        getline(file, items[size].name, ',');
        getline(file, items[size].type, ',');
        file >> items[size].quantity;
        file.ignore(1);
        file >> items[size].price;
        file.ignore();
        size++;
    }
    file.close();
    cout << "Inventory loaded from " << filename << "\n";
}