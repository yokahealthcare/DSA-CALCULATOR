#include <iostream>
#include <string>
#include <algorithm>
#include "Calculator.h"
#include "utility.h"
using namespace std;

int main() {
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
    while(!quit) {
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
            if(input == "1") {
                bool quitCal = false;
                while(!quitCal) {
                    // Print the banner
                    cout << "\n\nCalculator" << endl;
                    cout << "=====================\n" << endl;
                    cout << ">>> ";

                    string val;
                    getline(cin, val);

                    // convert all to the lower case
                    for_each(val.begin(), val.end(), [](char & c) {
                        c = ::tolower(c);
                    });

                    string tmp = "";
                    for(int i = 0; i < val.length(); i++) {
                        if(!isspace(val[i])) { // ignored
                            int ascii = val[i];
                            // check for operators
                            if(val[i] == '+' || val[i] == '-' || val[i] == '*' || val[i] == '/' || val[i] == '^') {
                                tmp += val[i];
                                cal.setComponents(tmp);
                                cal.addOperators(val[i]); // store the all operators to dictionary

                                tmp = "";
                                continue;

                            } else if((ascii >= 97 && ascii <= 122)){
                                tmp += val[i];
                                int next = val[i+1];
                                if ((next >= 97 && next <= 122) || (next == 40)) { // if next string is string, continue the loop to next loop immediately
                                    // FUNCTION FOR 'FUNCTIONS' DETECTION (ex. LOG, SIN, COS, etc)
                                    if(next == 40) {
                                        cal.addOperatorsString(tmp); // store the all functions to dictionary

                                        int indexBonus = 1;
                                        string currentCharacter;
                                        bool existCloseBracket = false;
                                        while(!existCloseBracket) {
                                            currentCharacter = val[i+indexBonus];
                                            if(currentCharacter != ")"){
                                                if(currentCharacter != " ") {
                                                    tmp += currentCharacter;
                                                }
                                            } else {
                                                // end of program if it met with ")"
                                                tmp += currentCharacter;

                                                cal.setComponents(tmp);
                                                tmp = "";

                                                existCloseBracket = true;
                                                continue;
                                            }
                                            indexBonus++;
                                        }
                                        i += indexBonus;
                                    }
                                } else {
                                    cout << "\n\nERROR! Spaces are not allowed for functions calculation." << endl;
                                    cout << "Restart the program!\n\n" << endl;
                                    exit(0);
                                }
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

                }
            } else if(input == "2") {
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
            } else if (input == "3") {
                cout << "Bye Thank You!" << endl;
                cout << "See You Next Time" << endl;
                quit = true;
            } else {
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
