#ifndef ORDER_H
#define ORDER_H

#include<string>

using namespace std;

class Order {
	public:
		Order();
		Order(string orderID, string date, int quantity, float amountPaid);

		string getOrderID();
		string getDate();
		int getQuantity();
		float getAmountPaid();

		string to_string();

	private:
		string date, orderID;
		int quantity;
		float amountPaid;
};

#endif
