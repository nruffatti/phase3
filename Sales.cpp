/* 
 * File:   Sales.cpp
 * Author: Nathan R
 * 
 * Created on May 18, 2018, 4:34 PM
 */

#include "Sales.h"
#include "employeeUtilities.h"
#include "transaction.h"
#include "order.h"

Sales::Sales() {
}

Sales::Sales(string title, string name, string ID, string bossID) {
    this->title = title;
    this->name = name;
    this->ID = ID;
    this->bossID = bossID;
}

Sales::Sales(const Sales& orig) {
}

Sales::~Sales() {
}


float Sales::getSales(vector<Transaction *>& trList, vector<Order *>& orList) {
    return totalAmount(searchAmount(orList, searchEmployeeOrders(trList, this->ID)));
}

float Sales::getComission(vector<Employee *>& eList, vector<Transaction *>& trList, vector<Order *>& orList)
{
    float total;
    
    total = getSales(trList, orList);
    
    return total*0.05;
}