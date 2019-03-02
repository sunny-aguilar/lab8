/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 1, 2019
** Description:     Menu class holds the main menu and user prompts
**                  for the program. The menu class lives inside of
**                  the searchSort class and the menus are called
**                  as needed from within the searchSort class.
*********************************************************************/
#ifndef MENU_HPP
#define LAB8_MENU_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
using std::string;
using std::setw;
using std::left;
using std::cin;
using std::cout;
using std::endl;

class Menu {
public:
    void mainMenu();
    void menuCreateArrays();
    void menuSearchValue();
    void menuSearchResults(bool arr1, bool arr2, bool arr3, bool arr4);
    void menuExit();
    int validateNumber(int min, int max);

private:

};

#endif //LAB8_MENU_HPP