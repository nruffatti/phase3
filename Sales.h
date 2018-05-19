/* 
 * File:   Sales.h
 * Author: Nathan R
 *
 * Created on May 18, 2018, 4:34 PM
 */

#ifndef SALES_H
#define SALES_H

#include <string>
#include <vector>
#include "employee.h"
#include "transaction.h"
#include "order.h"
#include "employeeUtilities.h"


using namespace std;

class Sales : public Employee {
public:
    Sales();
    Sales(string, string, string, string);
    Sales(const Sales& orig);
    virtual ~Sales();

    float getComission(vector<Employee *>&, vector<Transaction *>&, vector<Order *>&);
    float getSales(vector<Transaction *>&, vector<Order *>&);

};

#endif /* SALES_H */

