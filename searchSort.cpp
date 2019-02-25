/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 26, 2019
** Description:     This class holds all the algorithms used to
**                  implement the search, sorting, and binary search
**                  algorithms.
*********************************************************************/
#include "searchSort.hpp"

#include <iostream>

/*********************************************************************
** Description:     default constructor
*********************************************************************/
SearchSort::SearchSort() {}

/*********************************************************************
** Description:     destructor
*********************************************************************/
SearchSort::~SearchSort() {}

/*********************************************************************
** Description:     starts the program
*********************************************************************/
void SearchSort::startProgram() {
    // load arrays with data from files
    menu.menuCreateArrays();

    // load arrays
    loadArrays();

    // main menu and select algorithm
    selectAlgorithm();

}


/*********************************************************************
** Description:     this functions gets the text files and adds the
**                  data into the arrays
*********************************************************************/
void SearchSort::loadArrays() {
    // get and copy first file data into array
    ifstream infile_original;
    infile_original.open("original.txt");
    if (infile_original.fail()) {
        cout << "WARNING! Cannot find file \"original.txt\"\n\n";
    }

    int val;
    int index = 0;
    while (!infile_original.eof()) {
        infile_original >> val;
        firstArray[index] = val;
        index++;
    }
    for (int i = 0; i < 9; i++) {
        cout << firstArray[i] << " ";
    }
    cout << endl;

    // reset index
    index = 0;

    // get and copy second file data into array
    ifstream infile_early;
    infile_early.open("early.txt");
    if (infile_early.fail()) {
        cout << "WARNING! Cannot find file \"early.txt\"\n\n";
    }
    while (!infile_early.eof()) {
        infile_early >> val;
        secondArray[index] = val;
        index++;
    }
    for (int i = 0; i < 10; i++) {
        cout << secondArray[i] << " ";
    }
    cout << endl;

    // get and copy third file data into array
    ifstream infile_middle;
    infile_middle.open("middle.txt");
    if (infile_middle.fail()) {
        cout << "WARNING! Cannot find file \"middle.txt\"\n\n";
    }
    while (!infile_middle.eof()) {
        infile_middle >> val;
        thirdArray[index] = val;
        index++;
    }
    for (int i = 0; i < 10; i++) {
        cout << thirdArray[i] << " ";
    }
    cout << endl;

    // reset index
    index = 0;

    
}

/*********************************************************************
** Description:     this functions gets the text files and adds the
**                  data into the arrays
*********************************************************************/
void SearchSort::selectAlgorithm() {
    // display main menu
    menu.mainMenu();
    switch (menu.validateNumber(1,4)) {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            menu.menuExit();
            break;
        default:
            cout << "Unable to determine selection\n";
    }
}