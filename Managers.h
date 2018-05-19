/* 
 * File:   Managers.h
 * Author: Nathan R
 *
 * Created on May 18, 2018, 4:34 PM
 */

#ifndef MANAGERS_H
#define MANAGERS_H

#include <string>
#include <vector>
#include "employee.h"
#include "transaction.h"
#include "order.h"
#include "employeeUtilities.h"

using namespace std;

class Managers : public Employee{
public:
    Managers();
    Managers(string, string, string, string);
    Managers(const Managers& orig);
    virtual ~Managers();
    
    float getComission(vector<Employee *>&, vector<Transaction *>&, vector<Order *>&);
    float getSales(vector<Transaction *>&, vector<Order *>&);

};

#endif /* MANAGERS_H */

