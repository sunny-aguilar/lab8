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
SearchSort::SearchSort() :target{0} {}

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
    loadArrays();

    // main menu and select algorithm
    selectAlgorithm();
}


/*********************************************************************
** Description:     this functions calls a function that opens the
**                  respective text files that are added to the data
**                  arrays.
*********************************************************************/
void SearchSort::loadArrays() {
    openFile("original.txt", firstArray, 9);
    openFile("early.txt", firstArray, 10);
    openFile("middle.txt", firstArray, 10);
    openFile("end.txt", firstArray, 10);
}

/*********************************************************************
** Description:     this functions receives parameters that specify
**                  the name of the file to open, the array to add
**                  the data to, and the size of the array
*********************************************************************/
void SearchSort::openFile(string fileName, int arr[], int size) {
    int val;
    int index = 0;

    ifstream inFile;
    inFile.open(fileName);
    if (inFile.fail()) {
        cout << "WARNING! Cannot find file \"" << fileName << "\"\n\n";
    }
    while (!inFile.eof()) {
        inFile >> val;
        arr[index] = val;
        index++;
    }
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
            getTargetValue();
            simpleSearch(firstArray, 9, target);
            break;
        case 2:
            sorting();
            break;
        case 3:
            binarySearch();
            break;
        case 4:
            menu.menuExit();
            break;
        default:
            cout << "Unable to determine selection\n";
    }
}

/*********************************************************************
** Description:     desc
*********************************************************************/
void SearchSort::getTargetValue() {
    menu.menuSearchValue();
    int val = menu.validateNumber(0,50);
}

/*********************************************************************
** Description:     implements a search algorithm using linear search
**                  which is useful when the list of numbers are not
**                  sorted.
*********************************************************************/
void SearchSort::simpleSearch(int arr[], int size, int val) {
    bool found false;

    // binary search algorithm

}

/*********************************************************************
** Description:     desc
*********************************************************************/
void SearchSort::sorting() {

}

/*********************************************************************
** Description:     desc
*********************************************************************/
void SearchSort::binarySearch() {

}