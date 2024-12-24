#include <iostream>
#include "Keeper.h"

using namespace std;

int main() {
    Keeper Container;
    int menu;
    do {
        system("cls");
        cout << "**************************" << endl
            << "*    MENU                *" << endl
            << "**************************" << endl
            << "Number of elements in the container : " << Container.getSize() << endl
            << "1. Add element" << endl
            << "2. Delete element" << endl
            << "3. Save data to file" << endl
            << "4. Load data from file" << endl
            << "5. Change element data" << endl
            << "6. Get data out of a container" << endl
            << "0. Exit" << endl;

        cin >> menu;
        system("cls");
        switch (menu) {
        case 1:
            Container.add();
            break;
        case 2:
            Container.del();
            break;
        case 3:
            Container.save();
            break;
        case 4:
            Container.load();
            break;
        case 5:
            Container.edit();
            break;
        case 6:
            cout << Container;
            break;
        case 0:
            return 0;
        default:
            break;
        }
    } while (true);
}
