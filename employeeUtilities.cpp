/*
 * File:    employeeeUtilities.cpp
 * Author: Nathan R
 * 
 * Created on May 18, 2018, 6:32 PM
 */

#include "employeeUtilities.h"
#include <iostream>

using namespace std;

//get all direct employees from boss id
vector<string> searchBossID(vector<Employee *>& searchList, string bossID) {
    vector<string> foundList;
    
    for (int i = 0; i < searchList.size(); i++) {
        if (searchList[i]->getBossID() == bossID)
            foundList.push_back(searchList[i]->getID());
    }

    return foundList;
}

//get sales totals from boss's employees
float getEmployeeAmount(vector<Employee *>& eList, vector<Transaction *>& trList, vector<Order *>& orList, vector<string> employeeIDs) {
    float sum = 0;
    for (int i = 0; i < eList.size(); i++) {
        for (string employeeID : employeeIDs)
        {
            if(eList[i]->getID() == employeeID)
                sum += totalAmount(searchAmount(orList, searchEmployeeOrders(trList, employeeID)));
        }
    }
    return sum;
}

//search transactions for employee id and return order id
vector<string> searchEmployeeOrders(vector<Transaction *>& searchList, string employeeID) {
    vector<string> foundList;
    
    for (int i = 0; i < searchList.size(); i++) {
        if (searchList[i]->getEmployeeID() == employeeID)
            foundList.push_back(searchList[i]->getOrderID());
    }

    return foundList;
}

//search orders with order id to get transaction amount
vector<float> searchAmount(vector<Order *>& searchList, vector<string> orderIDs) {
    vector<float> foundList;
    
    for (int i = 0; i < searchList.size(); i++) {
        for(string orderID : orderIDs)
        {
            if (searchList[i]->getOrderID() == orderID)
            {
                foundList.push_back(searchList[i]->getAmountPaid());
                //cout << searchList[i]->getOrderID() << "\t" << searchList[i]->getAmountPaid() << endl;
            }
        }
    }
    return foundList;
}

int searchID(vector<Employee *>& searchList, string employeeID)
{
    int found = -1;
    
    for (int i = 0; i < searchList.size(); i++)
    {
        if (searchList[i]->getID() == employeeID)
            found = i;
    }
    return found;
}

float totalAmount(vector<float> amountList)
{
    float sum = 0;
    for(float a : amountList)
    {
        sum += a;
    }
    return sum;
}