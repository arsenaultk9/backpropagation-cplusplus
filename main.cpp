#include <iostream>
#include <vector>
#include <string>

#include "values.h"

using namespace std;

// TODO: Rendu au build.
int main()
{
    vector<string> msg = getValues();

    for (const string &word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}