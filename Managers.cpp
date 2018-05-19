/* 
 * File:   Managers.cpp
 * Author: Nathan R
 * 
 * Created on May 18, 2018, 4:34 PM
 */

#include "Managers.h"

Managers::Managers() {
}

Managers::Managers(string title, string name, string ID, string bossID) {
    this->title = title;
    this->name = name;
    this->ID = ID;
    this->bossID = bossID;
}

Managers::Managers(const Managers& orig) {
}

Managers::~Managers() {
}

float Managers::getSales(vector<Transaction *>& trList, vector<Order *>& orList) {
    float total;
    vector<float> amountList;
    
    amountList = searchAmount(orList, searchEmployeeOrders(trList, this->ID));
    total = totalAmount(amountList);
    return total;
}

float Managers::getComission(vector<Employee *>& eList, vector<Transaction *>& trList, vector<Order *>& orList)
{
    float manTotal = 0;
    float supTotal = 0;
    float salTotal = 0;
    vector<string> employeeIDs;
    
    employeeIDs = searchBossID(eList, this->ID);
    for (string employeeID : employeeIDs)
    {
        salTotal += getEmployeeAmount(eList, trList, orList, searchBossID(eList, employeeID));
    }
    
    manTotal = getSales(trList, orList);
    supTotal = getEmployeeAmount(eList, trList, orList, searchBossID(eList, this->ID));
    
    return manTotal*.065 + supTotal*0.03 + salTotal*0.03;
}