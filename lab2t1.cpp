#include <iostream>
using namespace std;

class MarkerPen {
private:
    string brand;
    string color;
    int inklevel;
    bool refillability;

public:
    MarkerPen(string b, string c, int ink, bool ref) : brand(b), color(c), inklevel(ink), refillability(ref) {}


    void write() {
        if (inklevel > 0) {
            --inklevel;
            cout << "Ink level decreased.\n";
        } else {
            cout << "Empty marker, please refill.\n";
        }
    }

   
    void refill() {
        if (refillability) {
            inklevel = 10;
            cout << "Ink level refilled to 10.\n";
        } else {
            cout << "Cannot refill, this marker is not refillable.\n";
        }
    }

    int getInkLevel() {
        return inklevel;
    }

    void displayDetails() {
        cout << "Marker Brand: " << brand << "\n"
             << "Color: " << color << "\n"
             << "Ink Level: " << inklevel << "\n"
             << "Refillable: " << (refillability ? "Yes" : "No") << "\n";
    }
};

int main() {
    string brand, color;
    int inklevel;
    char refillOption;
    bool refillable;


    cout << "Enter details for Marker 1:\n";
    cout << "Brand: ";
    cin >> brand;
    cout << "Color: ";
    cin >> color;
    cout << "Initial Ink Level (0-10): ";
    cin >> inklevel;
    cout << "Is it refillable? (y/n): ";
    cin >> refillOption;
    refillable = (refillOption == 'y' || refillOption == 'Y');

    MarkerPen pen1(brand, color, inklevel, refillable);


    cout << "\nEnter details for Marker 2:\n";
    cout << "Brand: ";
    cin >> brand;
    cout << "Color: ";
    cin >> color;
    cout << "Initial Ink Level (0-10): ";
    cin >> inklevel;
    cout << "Is it refillable? (y/n): ";
    cin >> refillOption;
    refillable = (refillOption == 'y' || refillOption == 'Y');

    MarkerPen pen2(brand, color, inklevel, refillable);


    cout << "\nMarker 1 Details:\n";
    pen1.displayDetails();
    cout << "\nMarker 2 Details:\n";
    pen2.displayDetails();


    pen1.write();
    if (pen1.getInkLevel() == 0) {
        pen1.refill();
    }

    pen2.write();
    if (pen2.getInkLevel() == 0) {
        pen2.refill();
    }

    return 0;
}
