/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 26, 2019
** Description:     Menu class holds the main menu and user prompts
**                  for the program. The menu class lives inside of
**                  the searchSort class and the menus are called
**                  as needed from within the searchSort class.
*********************************************************************/
#include "menu.hpp"

void Menu::mainMenu() {
    cout << "Select an operation:\n";
    cout << "1. Simple Search\n";
    cout << "2. Sorting\n";
    cout << "3. Binary Search\n";
    cout << "4. Exit\n";
    cout << ">> ";
}

/*********************************************************************
** Description:     alerts user that the data files are being copied
**                  into the arrays
*********************************************************************/
void Menu::menuCreateArrays() {
    cout << "\n Stand By, transferring data into arrays. . . Done\n";
    cout << "+--------------------------------------------------+\n";
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
    cout << "\n Linear Search Results\n";
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
    if (arr4) { cout << setw(21) << "target value found\n"; }
    else { cout << setw(25) << "target value not found\n"; }
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

/*********************************************************************
** Description:     general integer validator where the parameters are
**                  the min and max numbers acceptable
*********************************************************************/
int Menu::validateInteger(int min, int max) {
    char choice[100];
    int validatedChoice = 0;
    bool tooLong = false;
    bool negativeFound = false;
    bool notInRange = true;
    bool characterFound = false;
    long unsigned length = 0;
    std::stringstream convert;

    do {
        cout << "Enter a number from " << min << " to " << max << endl;
        cout << ">> ";
        cin.getline(choice, 100);

        // determine # of digits in max value acceptable
        if (choice[0] == 45) { length = std::to_string(min).length(); }
        else { length = std::to_string(max).length(); }

        // reject any input that has more than digits than max parameter
        tooLong = false;
        if (strlen(choice) > length) {
            tooLong = true;
            cout << "Digits entered are too long!\n";
        }

        // check if a negative character has been found
        negativeFound = false;
        if (choice[0] == 45) { negativeFound = true; }

        // if a value entered is a negative, validate value
        notInRange = true;
        characterFound = false;
        if (negativeFound) {
            for (int index = 1; index < strlen(choice); index++) {
                if (choice[index] >= 48 && choice[index] <= 57) {
                    notInRange = false;
                }
                if (choice[index] < 48 || choice[index] > 57) {
                    characterFound = true;
                }
                if (characterFound) { notInRange = true; }
            }
            if (characterFound) { cout << "Make sure to only enter numbers!\n"; }
        }
        else { // if value entered is positive, validate value
            for (int index = 0; index < strlen(choice); index++) {
                if (choice[index] >= 48 && choice[index] <= 57) {
                    notInRange = false;
                }
                if (choice[index] < 48 || choice[index] > 57) {
                    characterFound = true;
                }
                if (characterFound) { notInRange = true; }
            }
            if (characterFound) { cout << "Make sure to only enter numbers!\n"; }
        }

    } while (tooLong || notInRange);

    convert << choice;
    convert >> validatedChoice;

    return validatedChoice;
}