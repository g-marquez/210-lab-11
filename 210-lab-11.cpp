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
    int *superBowls;

    ~Fan() {
        if(superBowls)
            delete [] superBowls;
        superBowls = nullptr;
    }
};

void displayFan(Fan *);

int main() {


    return 0;
}

// displayFan() takes a pointer of a Fan object and outputs its members
// to the console.
// arguments: a pointer to a Fan object
// returns: n/a
void displayFan(Fan *fptr) {

}