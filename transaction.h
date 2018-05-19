#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

using namespace std;

class Transaction {
public:
    Transaction();

    Transaction(string customerID, string employeeID, string orderID);

    string getOrderID();
    string getCustomerID();
    string getEmployeeID();

private:
    string orderID, customerID, employeeID;
};

#endif
