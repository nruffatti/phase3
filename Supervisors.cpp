/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Supervisors.cpp
 * Author: Nathan R
 * 
 * Created on May 18, 2018, 4:34 PM
 */

#include "Supervisors.h"

Supervisors::Supervisors() {
}

Supervisors::Supervisors(string title, string name, string ID, string bossID){
    this->title = title;
    this->name = name;
    this->ID = ID;
    this->bossID = bossID;
}

Supervisors::Supervisors(const Supervisors& orig) {
}

Supervisors::~Supervisors() {
}

float Supervisors::getSales(vector<Transaction *>& trList, vector<Order *>& orList) {
    float total;
    vector<float> amountList;
    
    amountList = searchAmount(orList, searchEmployeeOrders(trList, this->ID));
    total = totalAmount(amountList);
    return total;
}

float Supervisors::getComission(vector<Employee *>& eList, vector<Transaction *>& trList, vector<Order *>& orList)
{
    float supTotal;
    float eTotal;

    supTotal = getSales(trList, orList);
    eTotal = getEmployeeAmount(eList, trList, orList, searchBossID(eList, this->ID));
    
    return supTotal*.065 + eTotal*0.03;
}