/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 26, 2019
** Description:     This class holds all the algorithms used to
**                  implement the search, sorting, and binary search
**                  algorithms.
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
    void sorting();
    void sortFile(ofstream &file, int arr[], int size);
    void insertFile(ofstream &file, int arr[], int size);
    void bubbleSort(int arr[], int size);
    void binarySearch();

private:
    Menu menu;
    int firstArray[9];
    int secondArray[10];
    int thirdArray[10];
    int fourthArray[10];
};

#endif //LAB8_SEARCHSORT_HPP