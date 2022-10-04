#include "Calculator.h"
using namespace std;

// CONSTRUCTOR
Calculator::Calculator(){

}


// COMPONENTS
void Calculator::setComponents(string value, int index) {
    this->components[index] = value;
}

string Calculator::getComponents(){return "";}

void Calculator::printComponents() {
    cout << "\nComponents : " << endl;
    for(int i = 0; i < sizeof(this->components)/sizeof(string); i++) {
        if(this->components[i] != "")
            cout << "Index " << i << " : " << this->components[i] << endl;
        else
            break;
    }
}


// STORAGE
void Calculator::setStorage(string value) {
    this->storage[this->filled] = value;
    this->filled++;
}

void Calculator::printStorage() {
    cout << "\n\nStorages" << endl;
    cout << "=====================\n" << endl;
    for(int i = 0; i < sizeof(this->storage)/sizeof(string); i++) {
        if(this->storage[i] != "")
            cout << "Calculation [" << i+1 << "] : " << this->storage[i] << endl;
        else
            break;
    }
    cout << "\n" << endl;
}
