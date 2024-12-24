#include "Boat.h"

Boat::Boat() {
    cout << "\n********** Adding a boat **********" << endl << endl;
    try {
        setType(3);
        cout << "Enter boat hull material : ";
        cin.ignore(256, '\n');
        getline(cin, material);
        if (material == "")
            throw (string)"Material cannot be empty";
        cout << "Enter driving performance : ";
        getline(cin, _class);
        if (_class == "")
            throw (string)"Driving performance cannot be empty";
        cout << "Enter the number of crew = ";
        cin >> this->people;
        if (this->people < 0) {
            throw (string)"Crew number cannot be negative";
        }
        cout << "Enter destination to boat:" << endl;
        cout << "1. Relaxation" << endl
            << "2. Fishing" << endl
            << "3. Cargo transportation" << endl;
        cin >> this->destination;
        if (this->destination < 1 || this->destination > 3) {
            throw (string)"Wrong destination for the boat";
        }
        cout << "Enter speed of the boat = ";
        cin >> this->speed;
        if (this->speed < 0) {
            throw (string)"Speed cannot be negative";
        }
        setError(false);
    }
    catch (string err) {
        cout << "ERROR: " << err << endl;
        setError(true);
    }
}

Boat::Boat(ifstream& fin) {
    setType(3);
    fin >> this->destination;
    fin.ignore(256, '\n');
    getline(fin, material);
    fin >> this->speed >> this->people;
    fin.ignore(256, '\n');
    getline(fin, _class);
}

Boat::~Boat() {
    cout << "The destructor of the Boat class has been called" << endl;
}

void Boat::edit() {
    try {
        int index;
        int iTmp;
        string sTmp;
        cout << "Select an option to change:" << endl
            << "1. Material" << endl
            << "2. Driving performance" << endl
            << "3. Crew" << endl
            << "4. Destination" << endl
            << "5. Speed" << endl
            << "Your choice: ";
        cin >> index;
        if (index < 1 || index > 5) {
            throw (string)"Parameter with given index does not exist";
        }
        cout << "Initial value: ";
        switch (index) {
        case 1:
            cout << material << endl;
            cout << "New value: ";
            cin.ignore(256, '\n');
            getline(cin, sTmp);
            if (sTmp == "")
                throw (string)"Material cannot be empty";
            material = sTmp;
            break;
        case 2:
            cout << _class << endl;
            cout << "New value: ";
            cin.ignore(256, '\n');
            getline(cin, sTmp);
            if (sTmp == "")
                throw (string)"Driving performance cannot be empty";
            _class = sTmp;
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
            cout << "Current destination: " << (destination == 1 ? "Relaxation" : destination == 2 ? "Fishing" : "Cargo transportation") << endl;
            cout << "New value 1/2/3: ";
            cin >> iTmp;
            if (iTmp < 1 || iTmp > 3) {
                throw (string)"The destination must be 1/2/3";
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

void Boat::save(ofstream& fout) {
    fout << getType() << endl
        << this->destination << endl
        << this->material << endl
        << this->speed << endl
        << this->people << endl
        << this->_class << endl;
}

void Boat::print(ostream& out) {
    out << "*************************************" << endl
        << "*********   Boat   *********" << endl
        << "*************************************" << endl;
    out << "Destination : " << (this->destination == 1 ? "Relaxation" : this->destination == 2 ? "Fishing" : "Cargo transportation") << endl;
    out << "Material : " << this->material << endl
        << "Speed : " << this->speed << endl
        << "Crew : " << this->people << endl
        << "Driving performance : " << this->_class << endl;
}
