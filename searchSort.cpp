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
    openFile("num.txt", firstArray, 9);
    openFile("early.txt", secondArray, 10);
    openFile("middle.txt", thirdArray, 10);
    openFile("end.txt", fourthArray, 10);
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
            searchArrays();
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
void SearchSort::searchArrays() {
    // prompt user for search value
    menu.menuSearchValue();
    int val = menu.validateNumber(0,50);

    // search for value in each array and return if found
    bool firstResult = simpleSearch(firstArray, 9, val);
    bool secondResult = simpleSearch(secondArray, 10, val);
    bool thirdResult = simpleSearch(thirdArray, 10, val);
    bool fourthResult = simpleSearch(fourthArray, 10, val);

    // send results to menu class for display
    menu.menuSearchResults(firstResult, secondResult, thirdResult, fourthResult);
}

/*********************************************************************
** Description:     implements a search algorithm using linear search
**                  which is useful when the list of numbers are not
**                  sorted.
*********************************************************************/
bool SearchSort::simpleSearch(int arr[], int size, int val) {
    bool found = false;
    int index = 0;
    while (index < size && found == false) {
        if (arr[index] == val) {
            found = true;
        }
        index++;
    }
    return found;
}

/*********************************************************************
** Description:     desc
*********************************************************************/
void SearchSort::sorting() {

}

/*********************************************************************
** Description:     the algorithm implemented for sorting is the
 *                  bubble sort method. This method compares two
 *                  values in the array and swaps the smallest one
 *                  to the left. It continues to do this until all
 *                  the values are sorted. This algorithm is similar
 *                  to the one in the textbook on page 613.
*********************************************************************/
void SearchSort::bubbleSort(int arr[], int size) {
    int temp;
    bool swapMade;
    do {
        for (int count = 0; count < (size - 1); count++) {
            if (arr[count] > arr[count + 1]) {
                temp = arr[count + 1];
                arr[count + 1] = temp;
                swapMade = true;
            }
        }
    } while ();
}

/*********************************************************************
** Description:     desc
*********************************************************************/
void SearchSort::binarySearch() {

}