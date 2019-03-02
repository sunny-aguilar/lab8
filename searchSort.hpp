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
#ifndef SEARCHSORT_HPP
#define SEARCHSORT_HPP

#include "menu.hpp"
#include <string>
#include <fstream>
using std::string;
using std::ifstream;
using std::ofstream;

class SearchSort {
public:
    SearchSort();
    ~SearchSort();
    void startProgram();
    void loadArrays();
    void openFile(string fileName, int arr[], int size);
    void selectAlgorithm();
    void searchArrays();
    bool simpleSearch(int arr[], int size, int val);
    void sortOperations();
    void outputSortedFile(int arr[], int size);
    void insertFile(ofstream &file, int arr[], int size);
    void bubbleSort(int arr[], int size);
    void binarySearchOps();
    bool searchFiles(int target);
    int countElements(ifstream &file);
    bool binarySearch(int arr[], int size, int val);

private:
    Menu menu;
    int firstArray[9];
    int secondArray[10];
    int thirdArray[10];
    int fourthArray[10];
};

#endif //LAB8_SEARCHSORT_HPP