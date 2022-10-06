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
        for (int j = 0; j < this->storage[i].size(); j++)
          cout << this->storage[i][j] << " ";
        cout << endl;
    }

    cout << "\n" << endl;
}

void Calculator::apex() {

}

// Calculate
void Calculator::calculate() {
    int step = 1;

    start:
    int index = 0;
    int itr1Index, itr2Index;
    list<string>::iterator it, itr1, itr2;
    itr1 = this->components.begin();
    itr2 = this->components.begin();

    vector<string> operationStorage;

    for(it = this->components.begin(); it != this->components.end(); ++it) {
        if(*it == "*" || *it == "/") {
            itr1Index = index - 1;
            advance(itr1, itr1Index);
            itr2Index = index + 1;
            advance(itr2, itr2Index);

            int first = stoi(*itr1);
            int second = stoi(*itr2);

            while(this->operators['*'] != 0 || this->operators['/'] != 0) {
                if(*it == "*" || *it == "/") {
                    string result;
                    if(*it == "*") {
                        // MULTIPLICATION
                        result = to_string(first * second);
                        this->operators['*']--; // subtract the 'operators' dictionary

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
                        cout << "STEP " << step << " : " << tmp << endl;step++;

                        goto start; // THIS IS CRITICAL COMMAND. DO NOT DELETE!

                    } else if(*it == "/") {
                        // DIVISION
                        result = to_string(first / second);
                        this->operators['/']--; // subtract the 'operators' dictionary

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
                        cout << "STEP " << step << " : " << tmp << endl;step++;

                        goto start; // THIS IS CRITICAL COMMAND. DO NOT DELETE!
                    }
                }
            }
        } else if((this->operators['*'] == 0 && this->operators['/'] == 0)) {
            if (*it == "+" || *it == "-") {
                itr1Index = index - 1;
                advance(itr1, itr1Index);
                itr2Index = index + 1;
                advance(itr2, itr2Index);

                int first = stoi(*itr1);
                int second = stoi(*itr2);

                while(this->operators['+'] != 0 || this->operators['-'] != 0) {
                    if(*it == "+" || *it == "-") {
                        string result;
                        if(*it == "+") {
                            // MULTIPLICATION
                            result = to_string(first + second);
                            this->operators['+']--; // subtract the 'operators' dictionary

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
                            cout << "STEP " << step << " : " << tmp << endl;step++;

                            goto start; // THIS IS CRITICAL COMMAND. DO NOT DELETE!

                        } else if(*it == "-") {
                            // DIVISION
                            result = to_string(first - second);
                            this->operators['-']--; // subtract the 'operators' dictionary

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
                            cout << "STEP " << step << " : " << tmp << endl; step++;

                            goto start; // THIS IS CRITICAL COMMAND. DO NOT DELETE!
                        }
                    }
                }
            }
        }
        index++;


    }
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












