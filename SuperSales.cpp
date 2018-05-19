/* 
 * File:   SuperSales.cpp
 * Author: Nathan R
 * 
 * Created on May 18, 2018, 4:34 PM
 */

#include "SuperSales.h"
#include "employeeUtilities.h"
#include "order.h"
#include "transaction.h"

SuperSales::SuperSales() {
}

SuperSales::SuperSales(string title, string name, string ID, string bossID) {
    this->title = title;
    this->name = name;
    this->ID = ID;
    this->bossID = bossID;
}

SuperSales::SuperSales(const SuperSales& orig) {
}

SuperSales::~SuperSales() {
}

float SuperSales::getSales(vector<Transaction *>& trList, vector<Order *>& orList) {
    float total;
    vector<float> amountList;
    
    amountList = searchAmount(orList, searchEmployeeOrders(trList, this->ID));
    total = totalAmount(amountList);
    return total;
}

float SuperSales::getComission(vector<Employee *>& eList, vector<Transaction *>& trList, vector<Order *>& orList)
{
    float total;
    
    total = getSales(trList, orList);
    
    return total*0.065;
}

