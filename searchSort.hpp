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
#include <fstream>
using std::ifstream;
using std::ofstream;

class SearchSort {
public:
    SearchSort();
    ~SearchSort();
    void startProgram();
    void loadArrays();

private:
    Menu menu;
    int firstArray[];
    int secondArray[];
    int thirdArray[];
    int fourthArray[];
};

#endif //LAB8_SEARCHSORT_HPP