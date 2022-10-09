#include "Calculator.h"
using namespace std;

// CONSTRUCTOR
Calculator::Calculator(){

}




// COMPONENTS
void Calculator::setComponents(string value) {
    this->components.push_back(value);
}

void Calculator::clearComponents() {
    this->components.clear();
}

void Calculator::printComponents() {
    int index = 0;
    cout << "\nComponents : " << endl;
    for(string i: this->components) {
        cout << "Index " << index << " : "<< i << endl;
        index++;
    }
}







// STORAGE
void Calculator::setStorage(string value, int index) {
    this->storage[index].push_back(value);
}

void Calculator::printStorage() {
    cout << "\n\nStorages" << endl;
    cout << "=====================\n" << endl;
    // Displaying the 2D vector
    for (int i = 0; i < this->storage.size(); i++) {
        cout << "Calculation [" << i+1 << "] executed at " << this->storage[i][0] << endl;
        for (int j = 1; j < this->storage[i].size(); j++)
          cout << this->storage[i][j] << endl;
        cout << endl;
    }

    cout << "\n" << endl;
}

void Calculator::removeElementStorage(int index) {
    this->storage.erase(storage.begin()+index);
    cout << "Successfully Deleted!" << endl;
    system("pause");
    system("cls");
}

int Calculator::getLengthStorage() {
    return this->storage.size();
}




// BASIC OPERATOR CALCULATOR
void Calculator::apex(string op, list<string>::iterator it, list<string>::iterator itr1, list<string>::iterator itr2) {
    this->step++;

    int first = stoi(*itr1);
    int second = stoi(*itr2);
    char opch;

    string result;
    if(op == "+") {
        result = to_string(first + second); opch = '+';
    } else if(op == "-") {
        result = to_string(first - second); opch = '-';
    } else if(op == "*") {
        result = to_string(first * second); opch = '*';
    } else if(op == "/") {
        result = to_string(first / second); opch = '/';
    } else if(op == "^") {
        result = to_string(pow(first, second)); opch = '^';
    }


    /*
        =======================>
        ADD MORE "ELSE IF" OPERATOR HERE
        IF YOU WANT TO
        ADD THE NEW SINGLE OPERATOR
    */

    this->operators[opch]--; // subtract the 'operators' dictionary

    // DELETE THE LIST ELEMENTS
    this->components.erase(itr1);
    this->components.erase(it);

    // ADDING THE VALUE, then ERASE THE LAST ITERATOR
    this->components.insert(itr2, result);
    this->components.erase(itr2);

    string tmp = "";
    for(string i: this->components) {
        tmp += i + " ";
    }
    cout << "STEP " << this->step << " : " << tmp << endl;

    // store the calculation
    this->tmpStorage.push_back(tmp);
}

void Calculator::advancedApex(string op, list<string>::iterator it) {
    cout << "ADVANCED APEX is CALLED" << endl;
}


void Calculator::calculate() {

    // TIME
    time_t t; // t passed as argument in function time()
    struct tm * tt; // decalring variable for localtime()
    time (&t); //passing argument to time()
    tt = localtime(&t);

    this->tmpStorage.push_back(asctime(tt)); // (first time, 0 index)

    string tmp = "";
    for(string i: this->components) {
        tmp += i + " ";
    }
    // store the notation
    this->tmpStorage.push_back(tmp); // (second time, 0 index)

    // START HERE CALCULATION
    start:
    int index = 0;
    int itr1Index, itr2Index;
    list<string>::iterator it, itr1, itr2;
    itr1 = this->components.begin();
    itr2 = this->components.begin();

    for(it = this->components.begin(); it != this->components.end(); ++it) {
        // Detection
        bool isFunction = false;
        bool isOperator = false;
        bool isNumber = false;
        string currentComponents = *it;
        for(int i = 0; i < currentComponents.length(); i++) {
            int ascii = currentComponents[i];

            if((ascii >= 97 && ascii <= 122)){
                // If it detect a functions
                cout << "IsFunction is TRUE NOW!" << "| VAL : " << currentComponents <<endl;
                isFunction = true;
                break;
            } else if(*it == "*" || *it == "/" || *it == "+" || *it == "-" || *it == "^") {
                // If it detect a operator
                cout << "IsOperator is TRUE NOW!" << "| VAL : " << currentComponents <<endl;
                isOperator = true;
                break;
            } else {
                // If it detect a number
                cout << "IsNumber is TRUE NOW!" << "| VAL : " << currentComponents <<endl;
                isNumber = true;
                break;
            }
        }

        // input = "+"

        if(isFunction) {
            string tmp;
            vector<string> parts;
            for(int i = 0; i < currentComponents.length(); i++) {
                if(!isspace(currentComponents[i])) { // ignored space
                    int ascii = currentComponents[i];

                    cout << "Current Components : " << i << " = " << currentComponents[i] << endl;

                    if((ascii >= 97 && ascii <= 122)){
                        cout << "ASCII ENTERED! INDEX : " << i << " = " << currentComponents[i] << endl;
                        tmp += currentComponents[i]; // store the first character of the word
                        int next = currentComponents[i+1]; // check the next character
                        if (next == 40){ // if next string is opening brackets
                            parts.push_back(tmp);
                            tmp = "";
                        }

                    } else if((ascii != 40) && (ascii != 41) && (ascii != 44)) { // jsut number are allowed to enter
                        cout << "NUMBER ENTERED! INDEX : " << i << " = " << currentComponents[i] << endl;
                        tmp += currentComponents[i];
                        if (isdigit(currentComponents[i+1])) // if next string is integer, continue the loop to next loop immediately
                            continue;
                        else {
                            parts.push_back(tmp); // insert the numbers
                            tmp = "";
                        }
                    }
                }
            }

            cout << "THIS IS PERFECT POINT!" << endl;
            for(string i: parts)
                cout << i << endl;

            /*
                STRUTURE OF 'PARTS' VARIABLE
                store functions data
                ==================================>

                VARIABLE NAME   : parts
                TYPE            : VECTOR ARRAY
                STRUCTURE       :   [0] : FUNCTION NAME (ex. sin, cos, tan, etc)
                                    [1] : ARGUMENT 1
                                    [2] : ARGUMENT 2
                                    [n] : ARGUMENT n
            */

            if(*it == "sin" || *it == "cos" || *it == "tan") {
                while(this->operators['sin'] != 0 || this->operators['cos'] != 0 || this->operators['tan'] != 0) {
                    if(*it == "sin" || *it == "cos" || *it == "tan") {
                        if(*it == "sin") {
                            // SIN
                            this->advancedApex(*it, it);
                            goto start; // THIS IS CRITICAL COMMAND. DO NOT DELETE!

                        } else if(*it == "cos") {
                            // COS
                            this->advancedApex(*it, it);
                            goto start; // THIS IS CRITICAL COMMAND. DO NOT DELETE!

                        } else if(*it == "tan") {
                            // TAN
                            this->advancedApex(*it, it);
                            goto start; // THIS IS CRITICAL COMMAND. DO NOT DELETE!
                        }
                    }
                }
            }



        } else if(isOperator) {
            // select before & after element from operator position
            itr1Index = index - 1;
            advance(itr1, itr1Index);
            itr2Index = index + 1;
            advance(itr2, itr2Index);


            /*
            BASIC SINGLE OPERATOR ONLY
            =======================>
            ADD MORE "IF-ELSE" OPERATOR HERE
            IF YOU WANT TO
            ADD THE NEW OPERATOR

            UPPER       ( HIGHER PRIORITY ) (ex. multiplication & division is higher priority)
            DOWNNER     ( LOWER PRIORITY )

            */
            if(*it == "^") {
                while(this->operators['^'] != 0) {
                    if(*it == "^") {
                        // POWER OF
                        this->apex(*it, it, itr1, itr2);
                        goto start; // THIS IS CRITICAL COMMAND. DO NOT DELETE!
                    }
                }
            } else if(*it == "*" || *it == "/") {
                while(this->operators['*'] != 0 || this->operators['/'] != 0) {
                    if(*it == "*" || *it == "/") {
                        if(*it == "*") {
                            // MULTIPLICATION
                            this->apex(*it, it, itr1, itr2);
                            goto start; // THIS IS CRITICAL COMMAND. DO NOT DELETE!

                        } else if(*it == "/") {
                            // DIVISION
                            this->apex(*it, it, itr1, itr2);
                            goto start; // THIS IS CRITICAL COMMAND. DO NOT DELETE!
                        }
                    }
                }
            } else if(*it == "+" || *it == "-") {
                // Check whether the aterisk / division symbol has been empty on operation
                if (this->operators['*'] == 0 && this->operators['/'] == 0) {
                    while(this->operators['+'] != 0 || this->operators['-'] != 0) {
                        if(*it == "+" || *it == "-") {
                            if(*it == "+") {
                                // ADDITION
                                this->apex(*it, it, itr1, itr2);
                                goto start; // THIS IS CRITICAL COMMAND. DO NOT DELETE!

                            } else if(*it == "-") {
                                // SUBTRACTION
                                this->apex(*it, it, itr1, itr2);
                                goto start; // THIS IS CRITIsCAL COMMAND. DO NOT DELETE!
                            }
                        }
                    }
                }
            }
        }
        // Increase Index (this is just for the +, -, *, / operators
        // pin point to detect where are we?
        index++;

        // Reset the iterator
        itr1 = this->components.begin();
        itr2 = this->components.begin();

    }

    // store the temporary "tmpStorage" on permanent variable "storage"
    this->storage.push_back(this->tmpStorage);

    // end of calculation reset all data
    this->tmpStorage.clear();
    this->step = 0;
    this->clearComponents();
}


// OTHER
void Calculator::addOperators(char val) {
    this->operators[val]++;
}

void Calculator::addOperatorsString(string val) {
    this->functions[val]++;
}

void Calculator::printOperators() {
    cout << "\n\n";
    cout << "+ : " << this->operators['+'] << endl;
    cout << "- : " << this->operators['-'] << endl;
    cout << "* : " << this->operators['*'] << endl;
    cout << "/ : " << this->operators['/'] << endl;
    cout << "^ : " << this->operators['^'] << endl;
    cout << "\n";
}

void Calculator::printFunctions() {
    cout << "\n\n";
    cout << "sin : " << this->functions["sin"] << endl;
    cout << "cos : " << this->functions["cos"] << endl;
    cout << "tan : " << this->functions["tan"] << endl;
    cout << "\n" << endl;
}











