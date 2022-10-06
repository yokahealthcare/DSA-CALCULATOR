#include "utility.h"

using namespace std;

/*
    UTILITY FUNCTIONS
    -- Some necessary function to make program functional
*/

// Returns true if s is a number else false
bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}
