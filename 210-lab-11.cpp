//*****************************************************************************
// COMSC-210 | Lab 11 | Gabriel Marquez
// Description: this program features a simple dynamic array of structs used
// to track NFL fans, their favorite teams, and their team's Super Bowl wins.
//*****************************************************************************

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Fan {
    string name; 
    string team;
    int numSuperBowls;
    int *superBowls; //dynamic array that will hold the years that the
                     //team in the respective struct won the Super Bowl
    ~Fan() {
        if(superBowls)
            delete [] superBowls;
        superBowls = nullptr;
    }
};

void createFan(ifstream &, Fan *);
void displayFan(Fan *);

int main() {
    int numFans;
    
    ifstream fin("fans.txt");
    if (fin.good()){
        fin >> numFans;
        Fan *fans = new Fan[numFans];
        for (int i = 0; i < numFans; ++i)
            createFan(fin, &fans[i]);
        for (int i = 0; i < numFans; ++i)
            displayFan(&fans[i]);
        fin.close();
        delete [] fans;
    }
    else {
        cout << "ERROR! Please verify file name/directory and restart program.";
        return 1;
    }
    return 0;
}

// createFan() takes a pointer of a Fan object and populates its members
// arguments: a pointer to a Fan object
// returns: n/a
void createFan(ifstream &fin, Fan *fptr) { //trying to pass the file by reference
    fin >> fptr->name;
    fin.ignore();
    getline(fin, fptr->team);
    fin >> fptr->numSuperBowls;
    fptr->superBowls = new int[fptr->numSuperBowls];
    for (int i = 0; i < fptr->numSuperBowls; ++i)
        fin >> fptr->superBowls[i];
}

// displayFan() takes a pointer of a Fan object and outputs its members
// to the console.
// arguments: a pointer to a Fan object
// returns: n/a
void displayFan(Fan *fptr) {
    cout << "Fan summary:" << endl;
    cout << "Name: " << fptr->name << endl;
    cout << "Favorite NFL team: " << fptr->team << endl;
    cout << fptr->team << " Super Bowl wins: ";
    if (fptr->numSuperBowls == 0)
        cout << "none (haha)" <<endl;
    else {
        for (int i = 0; i < fptr->numSuperBowls; ++i)
            cout << fptr->superBowls[i] << " ";
        cout << endl;
    }
    cout << endl;
}