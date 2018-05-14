/*
 * File:   part1.cpp
 * Author: Nathan R
 *
 * Created on April 12, 2018, 9:45 AM
 */
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <vector>

#include "part1.h"

using namespace std;

//get data from file changing
//delimiters when necessary
vector<vector<string>> getData(vector<vector<string>> data) {
    string line;
    ifstream file ("customer___data.txt");
    if(file.is_open())
    {
        int i = -1;
        int j = 0;
        char delimiter = '\n';
        vector<string> row;
        while(getline(file, line, delimiter))
        {
            replace(line.begin(), line.end(), '"', '\0');
            if(i == -1)
            {
                delimiter = '\t';
                i++;
                continue;
            }
            if(j == 1)
            {
                delimiter = ',';
            }
            if(j == 4)
            {
                delimiter = '\t';
            }
            if(j == 5)
            {
                delimiter = '\n';
            }
            if(j == 6)
            {
                delimiter = '\t';
                j = 0;
                i++;
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

//print data for given column
void printData(vector<vector<string>> data, int j)
{
    int i = 0;
    for(i; i < data.size(); i++)
    {
        cout << data[i][j] << endl;
    }
}

//remove initial space character for given columns(city, state)
vector<vector<string>> rm_spaces(vector<vector<string>> data, int j)
{
    for(int i = 0; i < data.size(); i++)
    {
        data[i][j] = data[i][j].substr(1);
    }
    return data;
}

//take zipcode substring
vector<vector<string>> rm_nonNum(vector<vector<string>> data, int j)
{
    for(int i = 0; i < data.size(); i++)
    {
        data[i][j] = data[i][j].substr(1,5);
    }
    return data;
}

//export bad_data
void bad_data(vector<vector<string>> data)
{
    vector<int> bad;
    string temp;
    int k = 0;
    
    //find empty or partial data
    for(int j = 0; j < 6; j++)
    {
        for(int i = 0; i < data.size(); i++)
        {
            temp = data[i][j];
            if(temp.length() < 5 && j == 5 || temp.length() < 6 && j == 2 || temp.length() < 2)
            {
                bad.push_back(i);
                k++;
            }
        }
    }
    
    //find duplicates
    string firstTemp;
    int after;
    for (int z = 0; z < data.size(); z++)
    {
        temp = data[z][1];
        firstTemp = data[z][0];
        after = z+1;
        for (int i = after; i < data.size(); i++)
        {
            if(temp.compare(data[i][1]) == 0)
            {
                if(firstTemp.find(data[i][0]) != string::npos || data[i][0].find(firstTemp) != string::npos)
                {
                    bad.push_back(i);
                    bad.push_back(z);
                }
            }
        }
    }
    
    //export bad data
    vector<vector<string>> badTemp;
    vector<string> row;
    for (int i = 0; i < bad.size(); i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if(j == 6)
            {
                stringstream tt;
                tt << bad.at(i);
                row.push_back(tt.str());
                tt.clear();
                badTemp.push_back(row);
                row.clear();
            } else {
                row.push_back(data[bad.at(i)][j]);
            }
        }
    }
    save(badTemp, "badData");
}

//save 2d array to file
void save(vector<vector<string>> data, string name)
{
    ofstream file;
    name += ".csv";
    file.open(name);
    for(int i = 0; i < data.size(); i++)
    {
        for(int j = 0; j < data[0].size(); j++)
        {
            file << data[i][j] << ",";
        }
        file << endl;
    }
    file.close();
}

//fix bad data
vector<vector<string>> fix_bad(vector<vector<string>> data)
{
    //import fixed data and location
    string line;
    int t;
    vector<int> loc;
    vector<vector<string>> temp;
    vector<string> row;
    ifstream f ("badData.csv");
    
    if(f.is_open())
    {
        int j = 0;
        int i = 0;
        char delimiter = ',';
        while(getline(f, line, delimiter))
        {
            //loc vector is the location
            if(j == 6)
            {
                stringstream ss(line);
                ss >> t;
                loc.push_back(t);
                ss.clear();
            } else {
                row.push_back(line);
            }
            j++;
            if(j == 6)
            {
                delimiter = '\n';
            }
            if(j == 7)
            {
                temp.push_back(row);
                row.clear();
                j = 0;
                i++;
                delimiter = ',';
            }
        }
        f.close();
    }
    
    //replace bad with good data
    int count = 0;
    for (int i = 0; i < loc.size(); i++)
    {
        for (int j = 0; j < 6; j++)
        {
            //delete if prompted
            if(temp[i][j].compare("delete") == 0)
            {
                data.erase(data.begin() + loc.at(i) + count);
                count--;
                break;
            } else {
                data[loc.at(i)][j] = temp[i][j];
            }
        }
    }
    return data;
    
}