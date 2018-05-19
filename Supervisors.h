/* 
 * File:   Supervisors.h
 * Author: Nathan R
 *
 * Created on May 18, 2018, 4:34 PM
 */

#ifndef SUPERVISORS_H
#define SUPERVISORS_H

#include <string>
#include <vector>
#include "employee.h"
#include "transaction.h"
#include "order.h"
#include "employeeUtilities.h"


using namespace std;

class Supervisors : public Employee{
public:
    Supervisors();
    Supervisors(string, string, string, string);
    Supervisors(const Supervisors& orig);
    virtual ~Supervisors();
    
    float getComission(vector<Employee *>&, vector<Transaction *>&, vector<Order *>&);
    float getSales(vector<Transaction *>&, vector<Order *>&);

};

#endif /* SUPERVISORS_H */

