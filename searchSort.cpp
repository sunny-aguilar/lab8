/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 1, 2019
** Description:     This class holds all the algorithms used to
**                  implement the search, sorting, and binary search
**                  algorithms. Text files are used to retrieve
**                  integer values which are stored in arrays and
**                  searched for a user-entered value. After the
**                  search is done, the arrays are sorted in
**                  ascending order. Once the arrays are sorted, text
**                  files are outputted with the sorted values.
**                  Finally, the sorted values are read from the
**                  text files back into the program and binary
**                  search is implemented to search for a user
**                  entered value.
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
** Description:     this calls the functions in a specified order
**                  to accomplish the task of searching, sorting, and
**                  searchign again.
*********************************************************************/
void SearchSort::selectAlgorithm() {
    // display main menu
    menu.mainMenu();
    // call linear search function
    searchArrays();
    // call sort function
    sortOperations();
    // call binary search function
    binarySearchOps();

    menu.menuExit();
}

/*********************************************************************
** Description:     this function prompts a user to enter a value to
**                  search in each array. The value is passed to all
**                  four functions and a bool value is returned to
**                  indicate whether the value was found. The last
**                  function called displays the results of the value
**                  found.
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
** Description:     this function calls another function for each
**                  array to be sorted
*********************************************************************/
void SearchSort::sortOperations() {
    outputSortedFile(firstArray, 9);
    outputSortedFile(secondArray, 10);
    outputSortedFile(thirdArray, 10);
    outputSortedFile(fourthArray, 10);
}

/*********************************************************************
** Description:     creates an output file that is used to store the
**                  results of the sorted arrays. This functions calls
**                  other functions that do the sorting and writing of
**                  the data.
*********************************************************************/
void SearchSort::outputSortedFile(int arr[], int size) {
    // string to hold output file name
    string outFileName;

    // create output file object
    ofstream outFile;

    // request output file name;
    cout << "Enter a file name to save the data to (i.e., outfile_one.txt):\n";
    cout << ">> ";
    cin >> outFileName;

    // create outfile and write
    outFile.open(outFileName);

    // sort array
    bubbleSort(arr, size);

    // insert sorted values into file
    insertFile(outFile, arr, size);
}

/*********************************************************************
** Description:     inserts the array values into the output file
*********************************************************************/
void SearchSort::insertFile(ofstream &file, int arr[], int size) {
    for (int index = 0; index < size; index++) {
        file << " " << arr[index];
    }
}

/*********************************************************************
** Description:     the algorithm implemented for sorting is the
**                  bubble sort method. This method compares two
**                  values in the array and swaps the smallest one
**                  to the left. It continues to do this until all
**                  the values are sorted. This algorithm is similar
**                  to the one in the textbook on page 613.
*********************************************************************/
void SearchSort::bubbleSort(int arr[], int size) {
    int temp;
    bool swapMade;
    do {
        swapMade = false;
        for (int count = 0; count < (size - 1); count++) {
            if (arr[count] > arr[count + 1]) {
                temp = arr[count];
                arr[count] = arr[count + 1];
                arr[count + 1] = temp;
                swapMade = true;
            }
        }
    } while (swapMade);
}

/*********************************************************************
** Description:     starts the program
*********************************************************************/
void SearchSort::binarySearchOps() {
    // prompt user for search value
    cin.ignore();
    menu.menuSearchValue();
    int val = menu.validateNumber(0,50);

    // search each file and return if value is found
    bool firstResult = searchFiles(val);
    bool secondResult = searchFiles(val);
    bool thirdResult = searchFiles(val);
    bool fourthResult = searchFiles(val);

    // send results to menu class for display
    menu.menuSearchResults(firstResult, secondResult, thirdResult, fourthResult);
}

/*********************************************************************
** Description:     this functions takes a target value to search for
**                  and opens a file to search. The files it takes in
**                  are already sorted and so binary search is used.
**                  A bool value is returned to indicate if the value
**                  was found.
*********************************************************************/
bool SearchSort::searchFiles(int target) {
    // open sorted files from task 3
    string fileName;
    ifstream inFile;

    // add a file name
    cout << "Enter a file name (i.e. outfile_one.txt)\n";

    // loop - ask user for file name if incorrect
    do {
        cin >> fileName;
        inFile.open(fileName);
        if (inFile.fail())
            cout << "File not found! "
                 << "Enter a file name:\n";
    } while (inFile.fail());

    // confirm input file opened
    cout << "Text file successfully opened\n";

    // count elements in text file & reset read position
    int totalElements = 0;
    totalElements = countElements(inFile);
    inFile.clear();
    inFile.seekg(0, std::ios::beg);

    // dynamically create an array to hold text values
    int *tempArray;
    tempArray = new int[totalElements];

    // store text values in array
    int index = 0;
    while (!inFile.eof()) {
        inFile >> tempArray[index];
        index++;
    }

    // search for value in each array and return if found
    bool found = binarySearch(tempArray, 9, target);

    // free memory
    delete [] tempArray;

    return found;
}

/*********************************************************************
** Description:     counts the number of characters in the file and
**                  returns the value
*********************************************************************/
int SearchSort::countElements(ifstream &file) {
    string line;
    int length = 0;
    int count = 0;
    while (!file.eof()) {
        getline(file, line);
        count = line.length();
        for (int index = 0; index < length; index++) {
            if (line.at(index) == ' ') {
                count--;
            }
        }
    }
    return count;
}

/*********************************************************************
** Description:     this function implements the binary search
**                  algorithm to search each array. It is similar to
**                  the one found in the textbook on page 606.
*********************************************************************/
bool SearchSort::binarySearch(int arr[], int size, int val) {
    int first = 0;
    int last = size - 1;
    int middle;
    bool found = false;

    while (!found && first <= last) {
        middle = ((unsigned)first + (unsigned)last) >> 1;
        if (arr[middle] == val) {
            found = true;
        }
        else if (arr[middle] > val) {
            last = middle - 1;
        }
        else {
            first = middle + 1;
        }
    }
    return found;
}