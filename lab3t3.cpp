#include <iostream>
using namespace std;

class Planner {
private:
    string task;
    int day;
    int month;
    string client;
    string jan[31][2], feb[28][2], march[31][2], april[30][2], may[31][2], june[30][2], 
           july[31][2], august[31][2], sept[30][2], oct[31][2], nov[30][2], dec[31][2];

public:
    Planner() {}

    void add(string task, int month, int day, string client) {
        if (month < 1 || month > 12 || day < 1 || day > 31) {
            cout << "Invalid date!\n";
            return;
        }

        int index = day - 1; // Fixing the array index issue

        switch (month) {
            case 1: jan[index][0] = task; jan[index][1] = client; break;
            case 2: if (index < 28) { feb[index][0] = task; feb[index][1] = client; } break;
            case 3: march[index][0] = task; march[index][1] = client; break;
            case 4: if (index < 30) { april[index][0] = task; april[index][1] = client; } break;
            case 5: may[index][0] = task; may[index][1] = client; break;
            case 6: if (index < 30) { june[index][0] = task; june[index][1] = client; } break;
            case 7: july[index][0] = task; july[index][1] = client; break;
            case 8: august[index][0] = task; august[index][1] = client; break;
            case 9: if (index < 30) { sept[index][0] = task; sept[index][1] = client; } break;
            case 10: oct[index][0] = task; oct[index][1] = client; break;
            case 11: if (index < 30) { nov[index][0] = task; nov[index][1] = client; } break;
            case 12: dec[index][0] = task; dec[index][1] = client; break;
        }
        cout << "Task added successfully!\n";
    }

    void remove(int month, int day) {
        if (month < 1 || month > 12 || day < 1 || day > 31) {
            cout << "Invalid date!\n";
            return;
        }

        int index = day - 1;

        switch (month) {
            case 1: jan[index][0] = ""; jan[index][1] = ""; break;
            case 2: if (index < 28) { feb[index][0] = ""; feb[index][1] = ""; } break;
            case 3: march[index][0] = ""; march[index][1] = ""; break;
            case 4: if (index < 30) { april[index][0] = ""; april[index][1] = ""; } break;
            case 5: may[index][0] = ""; may[index][1] = ""; break;
            case 6: if (index < 30) { june[index][0] = ""; june[index][1] = ""; } break;
            case 7: july[index][0] = ""; july[index][1] = ""; break;
            case 8: august[index][0] = ""; august[index][1] = ""; break;
            case 9: if (index < 30) { sept[index][0] = ""; sept[index][1] = ""; } break;
            case 10: oct[index][0] = ""; oct[index][1] = ""; break;
            case 11: if (index < 30) { nov[index][0] = ""; nov[index][1] = ""; } break;
            case 12: dec[index][0] = ""; dec[index][1] = ""; break;
        }
        cout << "Task removed successfully!\n";
    }

    void display(int month) {
        if (month < 1 || month > 12) {
            cout << "Invalid month!\n";
            return;
        }

        cout << "\nTasks for Month " << month << ":\n";
        bool hasTasks = false;

        int days = (month == 2) ? 28 : ((month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31);

        string (*selectedMonth)[2];

        switch (month) {
            case 1: selectedMonth = jan; break;
            case 2: selectedMonth = feb; break;
            case 3: selectedMonth = march; break;
            case 4: selectedMonth = april; break;
            case 5: selectedMonth = may; break;
            case 6: selectedMonth = june; break;
            case 7: selectedMonth = july; break;
            case 8: selectedMonth = august; break;
            case 9: selectedMonth = sept; break;
            case 10: selectedMonth = oct; break;
            case 11: selectedMonth = nov; break;
            case 12: selectedMonth = dec; break;
            default: return;
        }

        for (int d = 0; d < days; d++) {
            if (!selectedMonth[d][0].empty()) {
                cout << "Day " << (d + 1) << ": " << selectedMonth[d][0] 
                     << " (Client: " << selectedMonth[d][1] << ")\n";
                hasTasks = true;
            }
        }

        if (!hasTasks) {
            cout << "No tasks scheduled for this month.\n";
        }
    }

    void displayAll() {
        cout << "\nAll Scheduled Tasks:\n";
        bool hasTasks = false;

        for (int m = 1; m <= 12; m++) {
            cout << "\n--- Month " << m << " ---\n";
            display(m);
            hasTasks = true;
        }

        if (!hasTasks) {
            cout << "No tasks scheduled.\n";
        }
    }
};

int main() {
    Planner planner;
    int choice, day, month;
    string task, client;

    while (true) {
        cout << "\nPlanner Menu\n";
        cout << "1. Add Task\n2. Remove Task\n3. Display Tasks for a Month\n4. Display All Tasks\n5. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 5) break;

        if (choice == 4) {
            planner.displayAll();
            continue;
        }

        cout << "Enter month (1-12): ";
        cin >> month;

        if (choice == 3) {
            planner.display(month);
            continue;
        }

        cout << "Enter day (1-31): ";
        cin >> day;

        if (choice == 1) {
            cout << "Enter task: ";
            cin.ignore();
            getline(cin, task);
            cout << "Enter client: ";
            getline(cin, client);
            planner.add(task, month, day, client);
        } else if (choice == 2) {
            planner.remove(month, day);
        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
