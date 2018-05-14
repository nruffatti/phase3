/*
 * File:   data.cpp
 * Author: Nathan R
 *
 * Created on April 25, 2018, 4:34 PM
 */
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <vector>
#include <ctime>

#include "data.h"

using namespace std;

vector<vector<string>> getCustomerData(string name, int i) {
    vector<vector < string>> data;
    string line;
    vector<string> row;
    char delimiter = ';';
    if (i == 1) {
        delimiter = '\n';
    }
    ifstream file(name + ".txt");
    int j = 0;
    if (file.is_open()) {
        while (getline(file, line, delimiter)) {
            if (i == 1) {
                row.push_back(line);
                data.push_back(row);
                row.clear();
                continue;
            }
            if (j == i - 2) {
                delimiter = '\n';
            }
            if (j == i - 1) {
                delimiter = ';';
                j = 0;
                row.push_back(line);
                data.push_back(row);
                row.clear();
                continue;
            }
            row.push_back(line);
            j++;
        }
        file.close();
    }
    return data;
}

string generateID(vector<Customer *>& customerList) {
    bool unique = false;
    int x;
    stringstream ss;
    string r;
    while (!unique) {
        srand(time(0));
        x = rand() % 1000000;
        ss << x;
        r = ss.str();
        if (!checkDupID(customerList, r)) {
            unique = true;
        }
    }

    string ID = "";
    int size = r.length();

    for (; size < 6; size++) {
        ID += "0";
    }
    ID += r;
    return ID;
}

string generateTransactionID(vector<Transaction *> list) {
    string r;
    stringstream ts;
    
    int num = list.size();
    num++;
    ts << num;
    r = ts.str();
    
    int size = r.length();
    string ID = "";
    
    for (; size < 6; size++) {
        ID += "0";
    }
    
    ID += r;
    return ID;
}


// use iomanip and stream << fixed << setprecision(2) instead
/*
string amountToString(float n)
{
    int cts;
    string dollars, cents;
    
    int doll = (int)n;
    stringstream a;
    a << doll;
    dollars = a.str(); 
    
    
    cts = (int)(n*100)%100;
    
    stringstream d;
    d << cts;
    cents = d.str();
    
    int size = cents.length();
    dollars = dollars + "." + cents;
    for(;size < 2; size++)
    {
        dollars += "0";
    }
    
    return dollars;
}
 */