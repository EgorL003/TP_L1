#include "Sail.h"

Sail::Sail() {
    cout << "\n********** Adding a sail **********" << endl << endl;
    try {
        setType(2);
        cout << "Enter sail name : ";
        cin.ignore(256, '\n');
        getline(cin, name);
        if (name == "")
            throw (string)"Title cannot be empty";
        cout << "Enter the type of sailboat : ";
        getline(cin, typeSail);
        if (typeSail == "")
            throw (string)"Type cannot be empty";
        cout << "Enter the number of crew = ";
        cin >> this->people;
        if (this->people < 0) {
            throw (string)"Crew number cannot be negative";
        }
        cout << "1. Peaceful" << endl
            << "2. Military" << endl;
        cout << "Your choice:" << endl;
        cin >> this->destination;
        if (this->destination < 1 || this->destination > 2) {
            throw (string)"Wrong destination sail";
        }
        cout << "Enter the speed of the sailboat = ";
        cin >> this->speed;
        if (this->speed < 0) {
            throw (string)"Speed cannot be negative.";
        }
        cout << "Enter sail length = ";
        cin >> this->_long;
        if (this->_long < 0) {
            throw (string)"Length cannot be negative";
        }
        setError(false);
    }
    catch (string err) {
        cout << "ERROR: " << err << endl;
        setError(true);
    }
}

Sail::Sail(ifstream& fin) {
    setType(2);
    fin.ignore(256, '\n');
    getline(fin, name);
    getline(fin, typeSail);
    fin >> this->destination >> this->_long >> this->speed >> this->people;
}

Sail::~Sail() {
    cout << "The destructor of the Sail class has been called" << endl;
    system("pause");
}

void Sail::edit() {
    try {
        int index;
        int iTmp;
        string sTmp;
        cout << "Select an option to change:" << endl
            << "1. Name" << endl
            << "2. Type" << endl
            << "3. Crew" << endl
            << "4. Destination" << endl
            << "5. Speed" << endl
            << "6. Length" << endl
            << "Your choice: ";
        cin >> index;
        if (index < 1 || index > 6) {
            throw (string)"Parameter with given index does not exist";
        }
        cout << "Initial value: ";
        switch (index) {
        case 1:
            cout << name << endl;
            cout << "New value: ";
            cin.ignore(256, '\n');
            getline(cin, sTmp);
            if (sTmp == "")
                throw (string)"Name cannot be empty";
            name = sTmp;
            break;
        case 2:
            cout << typeSail << endl;
            cout << "New value: ";
            cin.ignore(256, '\n');
            getline(cin, sTmp);
            if (sTmp == "")
                throw (string)"Type cannot be empty";
            typeSail = sTmp;
            break;
        case 3:
            cout << people << endl;
            cout << "New value: ";
            cin >> iTmp;
            if (iTmp < 0) {
                throw (string)"Crew number cannot be negative";
            }
            people = iTmp;
            break;
        case 4:
            cout << (destination == 1 ? "Peaceful" : "Military") << endl;
            cout << "New value 1/2: ";
            cin >> iTmp;
            if (iTmp < 1 || iTmp > 2) {
                throw (string)"Destination must be 1/2";
            }
            destination = iTmp;
            break;
        case 5:
            cout << speed << endl;
            cout << "New value: ";
            cin >> iTmp;
            if (iTmp < 0) {
                throw (string)"Speed cannot be negative";
            }
            speed = iTmp;
            break;
        case 6:
            cout << _long << endl;
            cout << "New value: ";
            cin >> iTmp;
            if (!iTmp || iTmp < 0) {
                throw (string)"Sail length is zero or negative";
            }
            _long = iTmp;
            break;
        default:
            break;
        }
        setError(false);
    }
    catch (string err) {
        cout << "ERROR: " << err << endl;
        setError(true);
    }
}

void Sail::save(ofstream& fout) {
    fout << getType() << endl
        << this->name << endl
        << this->typeSail << endl
        << this->destination << endl
        << this->_long << endl
        << this->speed << endl
        << this->people << endl;
}

void Sail::print(ostream& out) {
    out << "*************************************" << endl
        << "*********   Sail   *********" << endl
        << "*************************************" << endl
        << "Name : " << this->name << endl
        << "Type : " << this->typeSail << endl
        << "Destination : " << (this->destination == 1 ? "Peaceful" : "Military") << endl
        << "Length : " << this->_long << endl
        << "Speed : " << this->speed << endl
        << "Crew : " << this->people << endl;
}
