/* 
 * File:   part1.h
 * Author: Nathan R
 *
 * Created on April 14, 2018, 6:22 PM
 */

#ifndef PART1_H
#define PART1_H

using namespace std;

extern vector<vector<string>> getData(vector<vector<string>> data);
extern void printData(vector<vector<string>> data, int j);
extern vector<vector<string>> rm_spaces(vector<vector<string>> data, int j);
extern vector<vector<string>> rm_nonNum(vector<vector<string>> data, int j);
extern void bad_data(vector<vector<string>> data);
extern void save(vector<vector<string>> data, string name);
extern vector<vector<string>> fix_bad(vector<vector<string>> data);

#endif /* PART1_H */

