/* 
 * File:   employeeUtilities.h
 * Author: Nathan R
 *
 * Created on May 18, 2018, 6:32 PM
 */

#ifndef EMPLOYEEUTILITIES_H
#define EMPLOYEEUTILITIES_H

#include <vector>
#include "transaction.h"
#include "order.h"
#include "customerUtilities.h"
#include "employee.h"

using namespace std;

vector<string> searchBossID(vector<Employee *>&, string);
float getEmployeeAmount(vector<Employee *>&, vector<Transaction *>&, vector<Order *>&, vector<string>);
vector<string> searchEmployeeOrders(vector<Transaction *>&, string);
int searchID(vector<Employee *>&, string);
vector<float> searchAmount(vector<Order *>&, vector<string>);
float totalAmount(vector<float>);

#endif /* EMPLOYEEUTILITIES_H */

