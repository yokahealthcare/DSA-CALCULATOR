#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
using namespace std;

class Calculator
{
    private:
        string components[100];
        string storage[10000];
        int filled = 0;


    public:
        Calculator();

        // COMPONENTS
        void setComponents(string, int);
        string getComponents();
        void printComponents();

        // STORAGE
        void setStorage(string);
        void printStorage();


};

#endif // CALCULATOR_H
