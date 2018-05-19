/* 
 * File:   employee.cpp
 * Author: Nathan R
 * 
 * Created on May 18, 2018, 4:14 PM
 */

#include "employee.h"

Employee::Employee() {
    this->title = "";
    this->name = "";
    this->ID = "";
    this->bossID = "";
}

Employee::Employee(string title, string name, string ID, string bossID)
{
    this->title = title;
    this->name = name;
    this->ID = ID;
    this->bossID = bossID;
}

Employee::Employee(const Employee& orig) {
}

Employee::~Employee() {
}

string Employee::getTitle() {
    return title;
}

string Employee::getName() {
    return name;
}

string Employee::getID() {
    return ID;
}

string Employee::getBossID() {
    return bossID;
}

void Employee::setTitle(string title) {
    this->title = title;
}

void Employee::setName(string name) {
    this->name = name;
}

void Employee::setID(string ID) {
    this->ID = ID;
}

void Employee::setBossID(string bossID) {
    this->bossID = bossID;
}

float Employee::getComission(vector<Employee*>& eList, vector<Transaction*>& trList, vector<Order*>& orList) {
    //do nothing
}

float Employee::getSales(vector<Transaction*>& trList, vector<Order*>& orList) {
    //do nothing
}