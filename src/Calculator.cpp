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

    double first = stod(*itr1);
    double second = stod(*itr2);
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

void Calculator::advancedApex(list<string>::iterator it, vector<string> vect) {
    this->step++;
    string result;
    string opch;

    /*
        STRUTURE OF 'PARTS' VARIABLE
        store functions all data
        ==================================>

        VARIABLE NAME   : parts
        TYPE            : VECTOR ARRAY
        STRUCTURE INDEX :   [0] : FUNCTION NAME (ex. sin, cos, tan, etc)
                            [1] : ARGUMENT 1
                            [2] : ARGUMENT 2
                            [n] : ARGUMENT n
    */

    // Prepare the variable to be processed
    string func = vect[0];
    vector<double> arguments; // convert the arguments to double type variables
    for(int i = 1; i < vect.size(); i++) {
        arguments.push_back(stod(vect[i]));
    }

    if(func == "sin" || func == "cos" || func == "tan") {
        // convert to radians FIRST
        double xDegrees = arguments[0];

        // converting degrees to radians
        double xrad = xDegrees * 3.14159 / 180;

        if(func == "sin") {
            result = to_string(sin(xrad)); opch = "sin";
        } else if(func == "cos") {
            result = to_string(cos(xrad)); opch = "cos";
        } else if(func == "tan") {
            result = to_string(tan(xrad)); opch = "tan";
        }
    } else if(func == "exp") {
        result = to_string(pow(arguments[0], arguments[1]));
        opch = "exp";
    } else if(func == "log"){
        result = to_string(log(arguments[1])/log(arguments[0]));
        opch = "log";
    } else if(func == "ln"){
        result = to_string(log(arguments[0]));
        opch = "log";
    } else if(func == "sqrt"){
        result = to_string(sqrt(arguments[0]));
        opch = "sqrt";
    } else if(func == "cbrt"){
        result = to_string(cbrt(arguments[0]));
        opch = "cbrt";
    }
    else if (func == "asin"){
        result = to_string(asin(arguments[0]));
        opch = "asin";
    }
    else if (func == "acos"){
        result = to_string(acos(arguments[0]));
        opch = "acos";
    }
    else if (func == "atan"){
        result = to_string(atan(arguments[0]));
        opch = "atan";
    }
    else if (func == "sinh"){
        result = to_string(sinh(arguments[0]));
        opch = "sinh";
    }
    else if (func == "cosh"){
        result = to_string(cosh(arguments[0]));
        opch = "cosh";
    }
    else if(func == "tanh"){
        result = to_string(tanh(arguments[0]));
        opch = "tanh";
    }
    else if(func == "asinh"){
        result = to_string(asinh(arguments[0]));
        opch = "asinh";
    }
    else if(func == "acosh"){
        result = to_string(acosh(arguments[0]));
        opch = "acosh";
    }
    else if(func == "atanh"){
        result = to_string(atanh(arguments[0]));
        opch = "atanh";
    }









    /*
        ADD NEW FUNCTION HERE!!!

        FUNCTIONS ONLY
        =======================>
        ADD MORE "IF-ELSE" OPERATOR HERE
        IF YOU WANT TO
        ADD THE NEW FUNCTIONS

        UPPER       ( HIGHER PRIORITY )
        DOWNNER     ( LOWER PRIORITY )

        NOTE: IT DOESN'T MATTER ACTUALLY

    */

    this->functions[opch]--; // subtract the 'functions' dictionary

    // ADDING THE VALUE, then ERASE THE LAST ITERATOR
    this->components.insert(it, result);
    this->components.erase(it);

    string tmp = "";
    for(string i: this->components) {
        tmp += i + " ";
    }
    cout << "STEP " << this->step << " : " << tmp << endl;

    // store the calculation
    this->tmpStorage.push_back(tmp);
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
    this->tmpStorage.push_back(tmp); // (second time, 1 index)



    // START HERE CALCULATION
    start:
    int index = 0;
    int itr1Index, itr2Index;
    list<string>::iterator it;

    for(it = this->components.begin(); it != this->components.end(); ++it) {
        // Detection
        bool isFunction = false;
        bool isOperator = false;
        string currentComponents = *it;

        for(int i = 0; i < currentComponents.length(); i++) {
            int ascii = currentComponents[i];

            // PRIORITY CHECK FOR 'Functions'
            if((ascii >= 97 && ascii <= 122)){
                // If it detect a functions
                isFunction = true;
                break;
            } else if(this->functions["sin"] == 0 && this->functions["cos"] == 0 && this->functions["tan"] == 0 && this->functions["exp"] == 0 && this->functions["log"] == 0 && this->functions["ln"] == 0 && this->functions["sqrt"] == 0 && this->functions["cbrt"] == 0 && this->functions["asin"] == 0 && this->functions["acos"] == 0 && this->functions["atan"] == 0 && this->functions["sinh"] == 0 && this->functions["cosh"] == 0 && this->functions["tanh"] == 0 && this->functions["asinh"] == 0 && this->functions["acosh"] == 0 && this->functions["atanh"] == 0) {
                if(*it == "*" || *it == "/" || *it == "+" || *it == "-" || *it == "^") {
                    // If it detect a operator
                    isOperator = true;
                    break;
                }
            }
        }

        // IS FUNCTION, IS OPERATOR, IS NUMBER START HERE!
        // IS FUNCTION
        if(isFunction) {
            string tmp;
            vector<string> parts;
            for(int i = 0; i < currentComponents.length(); i++) {
                if(!isspace(currentComponents[i])) { // ignored space
                    int ascii = currentComponents[i];

                    if((ascii >= 97 && ascii <= 122)){
                        tmp += currentComponents[i]; // store the first character of the word
                        int next = currentComponents[i+1]; // check the next character
                        if (next == 40){ // if next string is opening brackets
                            parts.push_back(tmp);
                            tmp = "";
                        }

                    } else if((ascii != 40) && (ascii != 41) && (ascii != 44)) { // jsut number are allowed to enter
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

            // Function Calculation
            advancedApex(it, parts);
            goto start;

        }
        // IS OPERATOR
        else if(isOperator) {
            list<string>::iterator itr1, itr2;
            itr1 = this->components.begin();
            itr2 = this->components.begin();

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
                    // POWER OF
                    this->apex(*it, it, itr1, itr2);
                    goto start; // THIS IS CRITICAL COMMAND. DO NOT DELETE!
                }
            } else if(*it == "*" || *it == "/") {
                // Check whether the pow symbol has been empty on operation
                if (this->operators['^'] == 0) {
                    while(this->operators['*'] != 0 || this->operators['/'] != 0) {
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
                if (this->operators['*'] == 0 && this->operators['/'] == 0 && this->operators['^'] == 0) {
                    while(this->operators['+'] != 0 || this->operators['-'] != 0) {
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

            // Reset the iterator
            itr1 = this->components.begin();
            itr2 = this->components.begin();

        }
        // Increase Index (this is just for the +, -, *, / operators
        // pin point to detect where are we?
        index++;
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
    cout << "tan : " << this->functions["exp"] << endl;
    cout << "\n" << endl;
}











