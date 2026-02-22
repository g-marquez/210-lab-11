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
    int numSuperBowls; //to store number for iterating through dynamic array
                       //makes it easier to account for different num of SBs
    int *superBowls; //dynamic array that will hold the years that the
                     //team in the respective struct won the Super Bowl
    ~Fan() {
        if(superBowls)
            delete [] superBowls; //deletes the dynamic array within each struct
        superBowls = nullptr;
    }
};

void createFan(ifstream &, Fan *);
void displayFan(Fan *);

int main() {
    int numFans; 
    
    ifstream fin("fans.txt");
    if (fin.good()){
        fin >> numFans; //first line of fans.txt for number of structs
        Fan *fans = new Fan[numFans];
        for (int i = 0; i < numFans; ++i)
            createFan(fin, &fans[i]); //passing fin to populate Fan struct
        for (int i = 0; i < numFans; ++i)
            displayFan(&fans[i]);
        fin.close();
        delete [] fans; //deletes the array of structs/activates destructor
                        //won't let me delete outside of this code block
    }
    else {
        cout << "ERROR! Please verify file name/directory and restart program.";
        return 1;
    }
    return 0;
}

// createFan() takes an ifstream file and a pointer to a Fan object and
// populates its members
// arguments: an ifstream object to read data, a pointer to a Fan object
// returns: n/a
void createFan(ifstream &fin, Fan *fptr) { //passing the file to make main()
    fin >> fptr->name;                     //cleaner - it worked!
    fin.ignore();
    getline(fin, fptr->team);
    fin >> fptr->numSuperBowls; //needed because it's different for each team

    //dynamically allocate array for Super Bowl wins
    fptr->superBowls = new int[fptr->numSuperBowls];
    for (int i = 0; i < fptr->numSuperBowls; ++i)
        fin >> fptr->superBowls[i];
}

// displayFan() takes a pointer to a Fan object and outputs its members
// to the console.
// arguments: a pointer to a Fan object
// returns: n/a
void displayFan(Fan *fptr) {
    cout << "Fan summary:" << endl;
    cout << "Name: " << fptr->name << endl;
    cout << "Favorite NFL team: " << fptr->team << endl;
    cout << fptr->team << " Super Bowl wins: ";
    if (fptr->numSuperBowls == 0)
        cout << "none (haha)" <<endl; //small dig at Super Bowl-less fans
    else {
        for (int i = 0; i < fptr->numSuperBowls; ++i)
            cout << fptr->superBowls[i] << " "; //output on one line for ease
        cout << endl;
    }
    cout << endl;
}