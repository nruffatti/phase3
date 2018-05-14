/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   data.h
 * Author: npruffatti
 *
 * Created on April 25, 2018, 4:44 PM
 */

#ifndef DATA_H
#define DATA_H

#include "customer.h"
#include "customerUtilities.h"

using namespace std;

extern vector<vector<string>> getCustomerData(string, int);
extern string generateID(vector<Customer *>&);
extern string generateTransactionID(vector<Transaction *> list);
// extern string amountToString(float n);
#endif /* DATA_H */

