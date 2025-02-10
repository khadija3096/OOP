#include <iostream>
using namespace std;

class Laptop {
private:
    string brand, model, processor;
    int ram;       
    int storage;   
    bool isOn;

public:
    // Constructor
    Laptop(string b, string m, string p, int r, int s) {
        brand = b;
        model = m;
        processor = p;
        ram = r;
        storage = s;
        isOn = false; 
    }

   
    void turnOn() {
        if (!isOn) {
            isOn = true;
            cout << brand << " " << model << " is now ON.\n";
        } else {
            cout << brand << " " << model << " is already ON.\n";
        }
    }

  
    void turnOff() {
        if (isOn) {
            isOn = false;
            cout << brand << " " << model << " is now OFF.\n";
        } else {
            cout << brand << " " << model << " is already OFF.\n";
        }
    }


    void runProgram(string program) {
        if (isOn) {
            cout << "Running " << program << " on " << brand << " " << model << ".\n";
        } else {
            cout << "Cannot run " << program << ". " << brand << " " << model << " is OFF!\n";
        }
    }

   
    void displaySpecs() {
        cout << "\nLaptop Specifications:\n";
        cout << "Brand: " << brand << "\nModel: " << model << "\nProcessor: " << processor 
             << "\nRAM: " << ram << "GB\nStorage: " << storage << "GB\n";
    }


    static void compareLaptops(Laptop l1, Laptop l2) {
        cout << "\nComparing " << l1.brand << " " << l1.model << " and " << l2.brand << " " << l2.model << ":\n";

       
        if (l1.processor > l2.processor)
            cout << l1.brand << " has a better processor.\n";
        else if (l1.processor < l2.processor)
            cout << l2.brand << " has a better processor.\n";
        else
            cout << "Both have the same processor.\n";

     
        if (l1.ram > l2.ram)
            cout << l1.brand << " has more RAM.\n";
        else if (l1.ram < l2.ram)
            cout << l2.brand << " has more RAM.\n";
        else
            cout << "Both have the same RAM.\n";

        // Compare Storage
        if (l1.storage > l2.storage)
            cout << l1.brand << " has more storage.\n";
        else if (l1.storage < l2.storage)
            cout << l2.brand << " has more storage.\n";
        else
            cout << "Both have the same storage.\n";
    }
};

int main() {
  
    string brand, model, processor;
    int ram, storage;
    
    cout << "Enter Bilal's Laptop Details:\n";
    cout << "Brand: "; cin >> brand;
    cout << "Model: "; cin >> model;
    cout << "Processor: "; cin >> processor;
    cout << "RAM (GB): "; cin >> ram;
    cout << "Storage (GB): "; cin >> storage;
    Laptop bilalLaptop(brand, model, processor, ram, storage);

    cout << "\nEnter Ayesha's Laptop Details:\n";
    cout << "Brand: "; cin >> brand;
    cout << "Model: "; cin >> model;
    cout << "Processor: "; cin >> processor;
    cout << "RAM (GB): "; cin >> ram;
    cout << "Storage (GB): "; cin >> storage;
    Laptop ayeshaLaptop(brand, model, processor, ram, storage);

   
    bilalLaptop.displaySpecs();
    ayeshaLaptop.displaySpecs();

 
    Laptop::compareLaptops(bilalLaptop, ayeshaLaptop);

    // Running a program on Bilal's laptop
    bilalLaptop.turnOn();
    bilalLaptop.runProgram("Photoshop");
    
    // Turning off Ayesha's laptop
    ayeshaLaptop.turnOff();

    return 0;
}
