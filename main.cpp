#include <iostream>
#include <string>
#include <algorithm>
#include "Calculator.h"
#include "utility.h"
using namespace std;

int main()
{
    Calculator cal;
    bool quit = 0;
    string menus[] =
    {
        "Calculator",
        "History",
        "Exit"
    };
    int sizeOfMenus = sizeof(menus)/sizeof(string);
    string input;

    // PROGRAM START HERE!
    while(!quit)
    {
        system("cls"); // clear the screen
        // Print the menus
        cout << "SCIENTIFIC CALCULATOR" << endl;
        cout << "=====================" << endl;
        for(int i=0; i < sizeOfMenus; i++)
            cout << i+1 << " " << menus[i] << endl;

        cout << ">>> ";
        cin >> input; cin.ignore();

        // Check whether user inputted word or number
        if(isNumber(input)) {
            if(input == "1")
            {
                // some functions
                bool quitCal = false;
                while(!quitCal) {
                    // Print the banner
                    cout << "\n\nCalculator" << endl;
                    cout << "=====================\n" << endl;
                    cout << ">>> ";

                    string val;
                    getline(cin, val);

                    string tmp = "";
                    for(int i = 0; i < val.length(); i++) {

                        if(!isspace(val[i])) {
                            // check for operators
                            // TODO : revised... so next it use array of operators. not like this
                            if(val[i] == '+' || val[i] == '-' || val[i] == '*' || val[i] == '/') {
                                tmp += val[i];
                                cal.setComponents(tmp);
                                cal.addOperators(val[i]); // store the all operators to dictionary

                                tmp = "";
                                continue;

                            } else {

                                tmp += val[i];
                                if (isdigit(val[i+1])) // if next string is integer, continue the loop to next loop immediately
                                    continue;
                                else {
                                    cal.setComponents(tmp);
                                    tmp = "";
                                }
                            }
                        }
                    }

                    // Check for miss type or human-error
                    int valid = cal.checkValidity();
                    if(valid) {
                        // CALCULATION START HERE
                        cal.calculate();

                        // additional menu for the calculator side
                        int tmpInpt;
                        cout << "\n===================" << endl;
                        cout << "1. Continue" << endl;
                        cout << "2. Back to menu" << endl;
                        cin >> tmpInpt; cin.ignore();
                        if(tmpInpt == 1)
                            system("cls");
                        else if(tmpInpt == 2)
                            quitCal = true;
                    } else {
                        // IF Input is INVALID
                        cout << "\nYour Input is Invalid!" << endl;
                        cout << "Please Try Again" << endl;

                        system("pause");
                        system("cls");
                        cal.clearComponents();
                    }
                }
            }

            else if(input == "2")
            {
                bool quitStorage = false;
                while(!quitStorage) {
                    // some functions
                    cal.printStorage();
                    // check whether storage still empty or not
                    if(cal.getLengthStorage() > 0) {

                    int tmpInpt;
                    cout << "\n===================" << endl;
                    cout << "1. Delete" << endl;
                    cout << "2. Back to menu" << endl;
                    cout << ">>> ";
                    cin >> tmpInpt; cin.ignore();
                    if(tmpInpt == 1) {
                        cout << "Which one? " << endl;
                        cin >> tmpInpt; cin.ignore();

                        cal.removeElementStorage(tmpInpt-1);
                    }

                    else if(tmpInpt == 2)
                        quitStorage = true;
                    } else {
                        quitStorage = true;
                        system("pause");
                    }
                }
            }

            // exit
            else if (input == "3")
            {
                cout << "Bye Thank You!" << endl;
                cout << "See You Next Time" << endl;
                quit = true;
            }

            else
            {
                // If user entered more than size of menus
                cout << "Invalid Input!" << endl;
                cout << "Numbers allowed only from 1 to " << sizeOfMenus << endl;
                system("pause");
            }
        } else {
            // If user entered a word, not a number
            cout << "Invalid Type of Input!" << endl;
            cout << "Only numbers are allowed!" << endl;
            system("pause");
        }

    }

    return 0;
}
