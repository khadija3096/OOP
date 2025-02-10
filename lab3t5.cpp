#include <iostream>
using namespace std;

class GroceryStore {
private:
    string itemNames[100]; 
    double itemPrices[100]; 
    int itemCount; 

public:
    // Constructor
    GroceryStore() {
        itemCount = 0;
    }

  
    void addItem() {
        if (itemCount >= 100) {
            cout << "Inventory full! Cannot add more items.\n";
            return;
        }
        
        string name;
        double price;
        cout << "Enter item name: ";
        cin >> name;
        cout << "Enter item price: Rs.";
        cin >> price;

        itemNames[itemCount] = name;
        itemPrices[itemCount] = price;
        itemCount++;
        cout << "Item added: " << name << " - Rs." << price << endl;
    }

    
    void updatePrice() {
        string name;
        double newPrice;
        cout << "Enter item name to update price: ";
        cin >> name;
        cout << "Enter new price: Rs.";
        cin >> newPrice;

        for (int i = 0; i < itemCount; i++) {
            if (itemNames[i] == name) {
                itemPrices[i] = newPrice;
                cout << "Price updated: " << name << " - Rs." << newPrice << endl;
                return;
            }
        }
        cout << "Item not found!" << endl;
    }

    
    void viewInventory() {
        if (itemCount == 0) {
            cout << "Inventory is empty!\n";
            return;
        }

        cout << "\nCurrent Inventory:\n";
        for (int i = 0; i < itemCount; i++) {
            cout << itemNames[i] << " - Rs." << itemPrices[i] << endl;
        }
    }

  
    void generateReceipt() {
        if (itemCount == 0) {
            cout << "Inventory is empty! No items available for purchase.\n";
            return;
        }

        int numItems;
        cout << "Enter number of different items being purchased: ";
        cin >> numItems;

        string purchasedItems[numItems];
        int quantities[numItems];

        for (int i = 0; i < numItems; i++) {
            cout << "Enter item name: ";
            cin >> purchasedItems[i];
            cout << "Enter quantity: ";
            cin >> quantities[i];
        }

        double total = 0;
        cout << "\nReceipt:\n";
        for (int i = 0; i < numItems; i++) {
            string itemName = purchasedItems[i];
            int quantity = quantities[i];
            double price = 0;
            bool found = false;

            // Find item price
            for (int j = 0; j < itemCount; j++) {
                if (itemNames[j] == itemName) {
                    price = itemPrices[j];
                    found = true;
                    break;
                }
            }

            if (found) {
                double cost = price * quantity;
                total += cost;
                cout << itemName << " x " << quantity << " = Rs." << cost << endl;
            } else {
                cout << itemName << " not found in inventory!\n";
            }
        }
        cout << "Total: Rs." << total << endl;
    }
};

// Main function
int main() {
    GroceryStore store;
    int choice;

    while (true) {
        cout << "\n=== Grocery Store Menu ===\n";
        cout << "1. Add Item\n";
        cout << "2. Update Item Price\n";
        cout << "3. View Inventory\n";
        cout << "4. Generate Receipt\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                store.addItem();
                break;
            case 2:
                store.updatePrice();
                break;
            case 3:
                store.viewInventory();
                break;
            case 4:
                store.generateReceipt();
                break;
            case 5:
                cout << "Exiting program. Thank you!\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
