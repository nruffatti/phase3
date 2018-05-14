#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

using namespace std;

class Transaction {
	public:
		Transaction();

		Transaction(string customerID, string orderID);

		string getOrderID();
		string getCustomerID();

	private:
		string orderID, customerID;
};

#endif
