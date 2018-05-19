/* 
 * File:   employee.h
 * Author: Nathan R
 *
 * Created on May 18, 2018, 4:14 PM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>
#include "transaction.h"
#include "order.h"

using namespace std;

class Employee {
public:
    Employee();
    Employee(string, string, string, string);
    
    string getTitle();
    string getName();
    string getID();
    string getBossID();
    virtual float getComission(vector<Employee *>&, vector<Transaction *>&, vector<Order *>&);
    virtual float getSales(vector<Transaction *>&, vector<Order *>&);
    
    
    void setTitle(string);
    void setName(string);
    void setID(string);
    void setBossID(string);
    
    Employee(const Employee& orig);
    virtual ~Employee();
protected:
    string title, name, ID, bossID;
};

#endif /* EMPLOYEE_H */

