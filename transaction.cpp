#include "transaction.h"

Transaction::Transaction() {
	this->orderID = "";
        this->employeeID = "";
	this->customerID = "";
}

Transaction::Transaction(string customerID, string employeeID, string orderID) {

	this->orderID = orderID;
        this->employeeID = employeeID;
	this->customerID = customerID;
}

string Transaction::getOrderID() {
	return orderID;
}

string Transaction::getCustomerID() {
	return customerID;
}

string Transaction::getEmployeeID() {
    return employeeID;
}