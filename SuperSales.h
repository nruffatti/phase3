/* 
 * File:   SuperSales.h
 * Author: Nathan R
 *
 * Created on May 18, 2018, 4:34 PM
 */

#ifndef SUPERSALES_H
#define SUPERSALES_H

#include <string>
#include <vector>
#include "employee.h"
#include "transaction.h"
#include "order.h"
#include "employeeUtilities.h"


using namespace std;

class SuperSales : public Employee {
public:
    SuperSales();
    SuperSales(string, string, string, string);
    SuperSales(const SuperSales& orig);
    virtual ~SuperSales();
    
    float getComission(vector<Employee *>&, vector<Transaction *>&, vector<Order *>&);
    float getSales(vector<Transaction *>&, vector<Order *>&);

};

#endif /* SUPERSALES_H */

