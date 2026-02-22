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

void displayFan(Fan *);

int main() {
    int numFans;
    
    ifstream fin("fans.txt");
    if (fin.good()){
        fin >> numFans;
        Fan *fans = new Fan[numFans];

        fin.close();
    }

    return 0;
}

// displayFan() takes a pointer of a Fan object and outputs its members
// to the console.
// arguments: a pointer to a Fan object
// returns: n/a
void displayFan(Fan *fptr) {
    cout << "Fan summary:" << endl;
    cout << "Name: " << fptr->name << endl;
    cout << "Favorite NFL team: " << fptr->team << endl;
    cout << fptr->team << "Super Bowl wins: ";
    if (fptr->numSuperBowls == 0)
        cout << "none (haha)" <<endl;
    else {
        for (int i = 0; i < fptr->numSuperBowls; ++i)
            
    }

}