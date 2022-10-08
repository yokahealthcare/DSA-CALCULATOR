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




// CALCULATOR
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
    }

    /*
        =======================>
        ADD MORE "ELSE IF" OPERATOR HERE
        IF YOU WANT TO
        ADD THE NEW OPERATOR
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


void Calculator::calculate() {
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

    start:
    int index = 0;
    int itr1Index, itr2Index;
    list<string>::iterator it, itr1, itr2;
    itr1 = this->components.begin();
    itr2 = this->components.begin();

    for(it = this->components.begin(); it != this->components.end(); ++it) {
        if(*it == "*" || *it == "/" || *it == "+" || *it == "-") {
            // select before & after element from operator position
            itr1Index = index - 1;
            advance(itr1, itr1Index);
            itr2Index = index + 1;
            advance(itr2, itr2Index);


            /*
            =======================>
            ADD MORE "IF-ELSE" OPERATOR HERE
            IF YOU WANT TO
            ADD THE NEW OPERATOR

            UPPER       ( HIGHER PRIORITY ) (ex. multiplication & division is higher priority)
            DOWNNER     ( LOWER PRIORITY )

            */
            if(*it == "*" || *it == "/") {
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
        // Increase Index
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

void Calculator::printOperators() {
    cout << "\n\n";
    cout << "+ : " << this->operators['+'] << endl;
    cout << "- : " << this->operators['-'] << endl;
    cout << "* : " << this->operators['*'] << endl;
    cout << "/ : " << this->operators['/'] << endl;
    cout << "\n";
}












