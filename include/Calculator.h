#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <cstring>
#include <ctime>
using namespace std;

class Calculator
{
    private:
        list<string> components; // storing ALL components (included. number & operator)
        vector<vector<string>> storage; // storing ALL Calculation that has been made by user
        vector<string> tmpStorage; // storing 1 Calculation Temporary
        int step = 0;

        map<char, int> operators; // storing operators if and only if in the process of calculation

        vector<string> allowedOperators = {
            "+", "-", "*", "/",
            "sin", "cos", "tan", "asin", "acos", "atan",
            "^", "sqrt", "log", "ln"
        };



    public:
        Calculator();

        // COMPONENTS
        void setComponents(string);
        void clearComponents();
        void printComponents();

        // STORAGE
        void setStorage(string, int);
        void removeElementStorage(int);
        int getLengthStorage();
        void printStorage();

        // Calculate
        void calculate();
        void apex(string, list<string>::iterator, list<string>::iterator, list<string>::iterator);

        // OTHER
        void addOperators(char);
        void printOperators();

};

#endif // CALCULATOR_H
