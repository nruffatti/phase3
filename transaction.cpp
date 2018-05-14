#include "transaction.h"

Transaction::Transaction() {
	this->orderID = "";
	this->customerID = "";
}

Transaction::Transaction(string customerID, string orderID) {

	this->orderID = orderID;
	this->customerID = customerID;
}

string Transaction::getOrderID() {
	return orderID;
}

string Transaction::getCustomerID() {
	return customerID;
}
