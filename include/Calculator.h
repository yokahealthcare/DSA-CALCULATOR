#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <vector>
#include <map>
#include <list>
using namespace std;

class Calculator
{
    private:
        list<string> components;
        vector<vector<string>> storage;

        map<char, int> operators;
    public:
        Calculator();

        // COMPONENTS
        void setComponents(string);
        void clearComponents();
        void printComponents();

        // STORAGE
        void setStorage(string, int);
        void printStorage();

        // Calculate
        void calculate();
        void apex();

        // OTHER
        void addOperators(char);
        void printOperators();
};

#endif // CALCULATOR_H
