#include "Keeper.h"

Keeper::Keeper() {
    this->data = nullptr;
    this->size = 0;
}

Keeper::~Keeper() {
    delete[] data;
}

int Keeper::getSize() {
    return size;
}

void Keeper::add() {
    int type; // Тип наследника 
    try {
        cout << "Select a successor class: " << endl
            << "1. Submarine" << endl
            << "2. Sail" << endl
            << "3. Boat" << endl
            << "Your choice: ";
        cin >> type;
        if (type > 3 || type < 1) {
            throw (string)"This descendant class does not exist.";
        }
        Ship** tmp = new Ship * [size + 1];
        for (int i = 0; i < size; i++) {
            tmp[i] = data[i];
        }
        switch (type) {
        case 1:
            tmp[size] = new Submarine;
            break;
        case 2:
            tmp[size] = new Sail;
            break;
        case 3:
            tmp[size] = new Boat;
            break;
        default:
            break;
        }
        if (tmp[size]->isError()) {
            cout << "The element was not added due to an error" << endl;
            system("pause");
            return;
        }
        size++;
        if (data)
            delete[] data;
        data = tmp;
        cout << "Item added successfully" << endl;
        system("pause");
    }
    catch (string err) {
        cout << "ERROR: " << err << endl;
        system("pause");
    }
}

void Keeper::add(int _type, ifstream& fin) {
    Ship** tmp = new Ship * [size + 1];
    for (int i = 0; i < size; i++) {
        tmp[i] = data[i];
    }
    switch (_type) {
    case 1:
        tmp[size] = new Submarine(fin);
        break;
    case 2:
        tmp[size] = new Sail(fin);
        break;
    case 3:
        tmp[size] = new Boat(fin);
        break;
    default:
        break;
    }
    size++;
    if (data)
        delete[] data;
    data = tmp;
}

void Keeper::edit() {
    int index;
    if (!size) {
        cout << "Container is empty. Load data from a file or add new elements." << endl;
        system("pause");
        return;
    }
    try {
        for (int i = 0; i < size; i++) {
            cout << i << ". ";
            switch (data[i]->getType()) {
            case 1:
                cout << "Submarine" << endl;
                break;
            case 2:
                cout << "Sail" << endl;
                break;
            case 3:
                cout << "Boat" << endl;
                break;
            default:
                break;
            }
        }
        cout << "Select item to edit: ";
        cin >> index;
        if (index < 0 || index > size - 1)
            throw (string)"Selected item does not exist";
        data[index]->edit();
        if (data[index]->isError()) {
            cout << "Item not changed due to error" << endl;
        }
        else {
            cout << "Item changed successfully" << endl;
        }
        system("pause");
    }
    catch (string err) {
        cout << "ERROR: " << err << endl;
        system("pause");
    }
}

void Keeper::del() {
    int index;
    if (!size) {
        cout << "Container is empty. Load data from a file or add new elements." << endl;
        system("pause");
        return;
    }
    try {
        for (int i = 0; i < size; i++) {
            cout << i << ". ";
            switch (data[i]->getType()) {
            case 1:
                cout << "Submarine" << endl;
                break;
            case 2:
                cout << "Sail" << endl;
                break;
            case 3:
                cout << "Boat" << endl;
                break;
            default:
                break;
            }
        }
        cout << "Select an item to delete: ";
        cin >> index;
        if (index < 0 || index > size - 1)
            throw (string)"Selected item does not exist";
        if (size == 1) {
            delete[] data;
            data = nullptr;
            cout << "Item deleted successfully" << endl;
            size--;
            system("pause");
            return;
        }
        Ship** tmp = new Ship * [size - 1];
        int j = 0;
        for (int i = 0; i < size; i++) {
            if (index == i)
                continue;
            tmp[j] = data[i];
            j++;
        }
        delete[] data;
        data = tmp;
        size--;
        cout << "Item deleted successfully" << endl;
        system("pause");
    }
    catch (string err) {
        cout << "ERROR: " << err << endl;
        system("pause");
    }
}

void Keeper::save() {
    ofstream fout("Ship.txt");
    for (int i = 0; i < size; i++) {
        data[i]->save(fout);
    }
    fout.close();
    cout << "Items successfully saved to file" << endl;
    system("pause");
}

void Keeper::load() {
    ifstream fin("Ship.txt");
    if (fin.fail()) {
        cout << "File is empty" << endl;
        system("pause");
        return;
    }
    int type = 0;
    while (fin) {
        fin >> type;
        if (fin.peek() == -1) {
            break;
        }
        add(type, fin);
    }
    fin.close();
    cout << "Items successfully loaded from file" << endl;
    system("pause");
}

ostream& operator<<(ostream& out, Keeper& obj) {
    if (!obj.size) {
        cout << "Container is empty. Load data from a file or add new elements." << endl;
        system("pause");
        return out;
    }
    for (int i = 0; i < obj.size; i++) {
        obj.data[i]->print(out);
    }
    system("pause");
    return out;
}
