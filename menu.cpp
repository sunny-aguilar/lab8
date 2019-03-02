/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 1, 2019
** Description:     Menu class holds the main menu and user prompts
**                  for the program. The menu class lives inside of
**                  the searchSort class and the menus are called
**                  as needed from within the searchSort class.
*********************************************************************/
#include "menu.hpp"

void Menu::mainMenu() {
    cout << "Welcome, the following tasks will be performed\n";
    cout << ">> Simple Search\n";
    cout << ">> Sorting\n";
    cout << ">> Binary Search\n";
}

/*********************************************************************
** Description:     alerts user that the data files are being copied
**                  into the arrays
*********************************************************************/
void Menu::menuCreateArrays() {
    cout << "\n Stand By, transferring data into arrays. . . Done\n";
    cout << "+--------------------------------------------------+\n\n";
}

/*********************************************************************
** Description:     prompts user to enter a value to search
*********************************************************************/
void Menu::menuSearchValue() {
    cout << "\n Enter a value to search\n";
    cout << "+--------------------------------------------------+\n";
    cout << ">> ";
}

/*********************************************************************
** Description:     prompts user to enter a value to search
*********************************************************************/
void Menu::menuSearchResults(bool arr1, bool arr2, bool arr3, bool arr4) {
    cout << "\n Search Results\n";
    cout << "+--------------------------------------------------+\n";
    cout << "num.txt: ";
    if (arr1) { cout << setw(26) << "target value found\n"; }
    else { cout << setw(30) << "target value not found\n"; }
    cout << "Second Array: ";
    if (arr2) { cout << setw(21) << "target value found\n"; }
    else { cout << setw(25) << "target value not found\n"; }
    cout << "Third Array: ";
    if (arr3) { cout << setw(22) << "target value found\n"; }
    else { cout << setw(26) << "target value not found\n"; }
    cout << "Fourth Array: ";
    if (arr4) { cout << setw(22) << "target value found\n\n"; }
    else { cout << setw(26) << "target value not found\n\n"; }
}

/*********************************************************************
** Description:     alerts user that the program is being exited
*********************************************************************/
void Menu::menuExit() {
    cout << "\n Now exiting the program, goodbye.\n";
    cout << "+--------------------------------------------------+\n";
}


/*********************************************************************
** Description:     general validator where the parameters are the
**                  min and max numbers acceptable
*********************************************************************/
int Menu::validateNumber(int min, int max) {
    char choice[100];
    int validatedChoice = 0;
    std::stringstream convert;
    bool tooLong = false;
    bool isNotDigit = false;
    bool notInRange = false;

    // determine # of digits in max value acceptable
    long unsigned length = std::to_string(max).length();

    do {
        // store user input
        cin.getline(choice, 100);

        // reject any input that has more than digits than max parameter
        tooLong = false;
        if (strlen(choice) > length) {
            tooLong = true;
            cout << "enter only one number!\n";
        }

        // check if all characters entered are digits
        isNotDigit = false;
        for (unsigned i = 0; i < strlen(choice); i++) {
            // if digit is not a digit, then set it true so that
            // loop will repeat
            if (!isdigit(choice[i])) {
                isNotDigit = true;
            }
        }
        if (isNotDigit) {
            // prompt user to enter only digits
            cout << "enter only digits!\n";
        }

        // check if characters entered are within range
        notInRange = false;
        if (!isNotDigit && !tooLong) {
            convert.clear();
            convert << choice;
            convert >> validatedChoice;

            if (validatedChoice < min || validatedChoice > max) {
                notInRange = true;
                cout << "enter a number between "
                     << min << " or " << max << endl;
            }
        }
    } while (tooLong || isNotDigit || notInRange);

    return validatedChoice;
}