#include "order.h"
#include <sstream>
#include <iomanip>

Order::Order() {
    this->orderID = "";
    this->date = "";
    this->quantity = 0;
    this->amountPaid = 0;
}

Order::Order(string orderID, string date, int quantity, float amountPaid) {
    this->orderID = orderID;
    this->date = date;
    this->quantity = quantity;
    this->amountPaid = amountPaid;
}

string Order::getOrderID() {
    return orderID;
}

string Order::getDate() {
    return date;
}

int Order::getQuantity() {
    return quantity;
}

float Order::getAmountPaid() {
    return amountPaid;
}

string Order::to_string() {
    stringstream stream;
    string line;
    stream << "Order ID: " << orderID;
    stream << "\nDate Placed: " << date;
    stream << "\nQuantity Ordered: " << quantity;
    stream << "\nAmount Paid: $" << fixed << setprecision(2) << amountPaid;

    line = stream.str();
    return line;

}
