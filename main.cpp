
/*
 * File:   main.cpp
 * Author: Nathan R, Brandon Youngquist, Hai Le
 *
 * Created on April 12, 2018, 9:45 AM
 */

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <deque>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

#include "part1.h"
#include "customer.h"
#include "customerUtilities.h"
#include "data.h"
#include "order.h"
#include "transaction.h"

using namespace std;

int s_to_i(string str) {
    istringstream buffer(str);
    int num;
    buffer >> num;

    return num;
}

void printSaleConfirmation(string name, int qty, float total, string date) {
    cout << "\nSale Confirmation" << endl;
    cout << "=================" << endl;
    cout << "Date: \t\t\t" << date <<
            "\nName: \t\t\t" << name <<
            "\nQuantity Purchased: \t" << qty <<
            "\nTotal: \t\t\t$" << fixed << setprecision(2) << total << endl;

}

void printCustomerInfo(string name, string ID, string address) {
    cout << "\nName: \t" << name
            << "\nID: \t" << ID
            << "\nAdr: \t" << address << endl;
}

void printCustomerOrder(vector<Order *>& orderList, vector<string>& index) {
    cout << "\nCustomer Order History:" << endl;
    if (index.size() == 0)
        cout << "No available records";
    else
        for (int i = 0; i < index.size(); i++) {
            cout << "=======================" << endl;
            cout << orderList[s_to_i(index[i]) - 1]->to_string() << endl;
            cout << "=======================";
        }

}

void printInvalid() {
    cout << "Not valid input. Try again!" << endl;

    //fixed infinite loop error for invalid inputs
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main(int argc, char** argv) {
    // variables that will be used in multiple places or multiple times
    Customer * newCustomer;
    Order * newOrder;
    Transaction * newTransaction;

    //data storage
    vector<Customer *> customerList;
    deque<string> rainbowList; // use deque instead of queue to iterate for id
    vector<Order *> orderList;
    vector<Transaction *> transactionList;
    vector<float> prices;

    vector<int> foundList; // to store the index of found records with duplicate name
    vector<string> orderFoundList; // to store order IDs found for a specific customer
    int choice;
    bool exit = false;

    int cSize, oSize, tSize; // to keep track of # of existing records

    // read customers.txt and parse the data
    vector<vector < string>> data, rainbow, transaction, order;
    data = getCustomerData("customers", 7);
    rainbow = getCustomerData("rainbowList", 1);
    transaction = getCustomerData("transactions", 2);
    order = getCustomerData("orders", 4);
    //    string s;
    //    cout << "Parse Data? (y/n)" << endl;
    //    cin >> s;
    //
    //    //user edits bad data
    //    if (s.compare("y") == 0) {
    //        data = getData(data);
    //        data = rm_spaces(data, 4);
    //        data = rm_spaces(data, 3);
    //        data = rm_nonNum(data, 5);
    //        cout << "Parsing through data..." << endl;
    //        bad_data(data);
    //        cout << "Possible bad data saved to badData.csv file" << endl;
    //        cout << "Fix the bad data now and resave data. Press any key, then enter to continue" << endl;
    //        cout << ("note: type 'delete' into an element to delete that entire row.") << endl;
    //        cin >> s;
    //        data = fix_bad(data);
    //        save(data, "fixed_data");
    //    } else { //uses last saved edited badData file
    //
    //        //data = getData(data);
    //        //data = rm_spaces(data, 4);
    //        //data = rm_spaces(data, 3);
    //        //data = rm_nonNum(data, 5);
    //        //data = fix_bad(data);
    //        //save(data, "fixed_data");
    //
    //        data = getCustomerData("customers",7);
    //    }
    //    cout << "\n\n\n\n\n";

    // translate the data into Customer objects and push them into the customerList vector
    for (int i = 0; (unsigned) i < data.size(); i++) {
        newCustomer = new Customer(data[i][0], data[i][1], data[i][2], data[i][3], data[i][4], data[i][5], data[i][6]);
        customerList.push_back(newCustomer);
    }

    // translate the data into order objects and push into orderList vector
    for (int i = 0; (unsigned) i < order.size(); i++) {
        newOrder = new Order(order[i][0], order[i][1], s_to_i(order[i][2]), s_to_i(order[i][3]));
        orderList.push_back(newOrder);
    }

    // translate the data into transaction objects and push into transactionList vector
    for (int i = 0; (unsigned) i < transaction.size(); i++) {

        newTransaction = new Transaction(transaction[i][0], transaction[i][1]);
        transactionList.push_back(newTransaction);
    }

    //push rainbow data to queue
    for (int i = 0; (unsigned) i < rainbow.size(); i++) {
        rainbowList.push_back(rainbow[i][0]);
    }

    // to keep the track of # of existing records
    tSize = transactionList.size();
    oSize = orderList.size();
    cSize = customerList.size();


    // vector is used to store the options that the user can choose
    vector<string> options;
    options.push_back("(1) Add a customer");
    options.push_back("(2) Search for a customer by last name");
    options.push_back("(3) Search for a customer by ID number");
    options.push_back("(4) Customer Sale");
    options.push_back("(5) Rainbow Tribble");
    options.push_back("(6) Exit");


    // Vector used to store tribble prices
    prices.push_back(9.50);
    prices.push_back(16.15);
    prices.push_back(25.88);
    prices.push_back(28.15);
    prices.push_back(30.00);


    // to store the user input
    string ID, fname, lname, street, city, state, zip;
    string orderID, transactionID, date, quantity;
    int quant;
    float amountPaid;

    while (!exit) {

        cout << "\n\nWhat would you like to do?\n";
        // for loop iterates through the available options that the user can choose
        for (int i = 0; i < (int) options.size(); i++) {
            cout << options.at(i) << endl;
        }

        cout << "\nEnter an above number to continue: ";
        cin >> choice;

        /**
         * Switch is used to determine what option the user chooses
         * case 1 - user is prompted to add new customer
         * case 2 - user is prompted to look up a customer by last name
         * case 3 - user is prompted to look up a customer by ID
         * case 4 - user prompted for customer sale
         * case 5 - user prompted to add customer to rainbow tribble queue
         * case 6 - exit
         */
        switch (choice) {
            case 1: // User is prompted to add new customer @Author Brandon Youngquist
                cout << "\nNew Customer\n============" << endl;
                cout << "\nWhat would you like to do?";
                cout << "\n(1) Enter a new customer";
                cout << "\n(2) Return to Main Menu";
                cout << "\n\nEnter an above number to continue: ";

                cin >> choice;

                switch (choice) {
                    case 1:
                        ID = generateID(customerList);

                        cout << "Enter first name: ";
                        cin >> fname;

                        cout << "Enter last name: ";
                        cin >> lname;

                        cout << "Enter street address: ";
                        cin.ignore();
                        getline(cin, street);

                        cout << "Enter city name: ";
                        cin >> city;

                        cout << "Enter state name: ";
                        cin >> state;

                        cout << "Enter zipcode: ";
                        cin >> zip;

                        newCustomer = new Customer(ID, fname, lname, street, city, state, zip);
                        customerList.push_back(newCustomer);

                        cout << "\nAdded new customer " << fname << " " << lname << " with ID " << ID << endl;

                        break;

                    case 2:
                        break;

                    default:
                        printInvalid();
                        break;
                }
                break;

            case 2: // User is prompted to look up a customer by last name
                cout << "\nEnter last name to search: ";
                cin >> lname;
                foundList = searchLastName(customerList, lname);

                //multiple last names
                if (foundList.size() > 1) {
                    for (int i = 0; (unsigned) i < foundList.size(); i++) {
                        cout << (i + 1) << ". " << customerList[foundList[i]]->getFullName() << endl;
                    }
                    // initial prompt
                    cout << "Enter a number to choose a record: " << endl;
                    cin >> choice;

                    // check if input is valid
                    while (!cin.good() || choice > foundList.size()) {
                        printInvalid();
                        // prompt until valid input is entered
                        cout << "Enter a number to choose a record: " << endl;
                        cin >> choice;
                    }

                    // match the choice with index 0
                    choice--;
                    // print customer name, id, address
                    printCustomerInfo(customerList[foundList[choice]]->getFullName(),
                            customerList[foundList[choice]]->getID(),
                            customerList[foundList[choice]]->getAddress());
                    //print customer orders
                    orderFoundList = searchOrderID(transactionList, customerList[foundList[choice]]->getID());
                    printCustomerOrder(orderList, orderFoundList);
                }//one last name found
                else if (foundList.size() == 1) {
                    //
                    printCustomerInfo(customerList[foundList[0]]->getFullName(),
                            customerList[foundList[0]]->getID(),
                            customerList[foundList[0]]->getAddress());
                    orderFoundList = searchOrderID(transactionList, customerList[foundList[0]]->getID());
                    printCustomerOrder(orderList, orderFoundList);
                    //print customer orders
                } else
                    cout << "No match was found. Try again!" << endl;
                break;

            case 3: // User is prompted to look up a customer by ID
                cout << "\nEnter ID number to search: ";
                cin >> ID;
                foundList = searchID(customerList, ID);
                if (foundList.size() == 1) {
                    printCustomerInfo(customerList[foundList[0]]->getFullName(),
                            customerList[foundList[0]]->getID(),
                            customerList[foundList[0]]->getAddress());
                    orderFoundList = searchOrderID(transactionList, customerList[foundList[0]]->getID());
                    printCustomerOrder(orderList, orderFoundList);
                    //print customer orders
                } else
                    cout << "No Match was found. Try again!" << endl;
                break;

            case 4: // Customer sale prompt @Author Brandon Youngquist
                cout << "Customer Sale Menu\n===================";
                cout << "\nWhat would you like to do?";
                cout << "\n(1) Sell to Customer";
                cout << "\n(2) Return to Main Menu";
                cout << "\n\nEnter an above number to continue: ";

                cin >> choice;

                switch (choice) {
                    case 1: // Sell to customer
                        cout << "Please enter customer ID: ";
                        cin >> ID;


                        // check if ID exists
                        foundList = searchID(customerList, ID);
                        while (foundList.size() == 0) {
                            cout << "\nError! Customer ID was not found!" << endl;
                            cout << "Please try again: ";
                            cin >> ID;
                            foundList = searchID(customerList, ID);
                        }

                        cout << "Please enter quantity (Limit 5): ";
                        cin >> quantity;
                        while (s_to_i(quantity) > 5 || s_to_i(quantity) < 0) {
                            cout << "Please enter a valid number: ";
                            cin >> quantity;
                        }

                        /// generate new transaction
                        transactionID = generateTransactionID(transactionList);
                        newTransaction = new Transaction(ID, transactionID);
                        transactionList.push_back(newTransaction);

                        quant = s_to_i(quantity);
                        amountPaid = prices.at(quant - 1);
                        orderID = transactionID;
                        // create timestamp
                        date = generateTimeStamp();

                        // generate new order
                        newOrder = new Order(orderID, date, quant, amountPaid);
                        orderList.push_back(newOrder);

                        // Print Sale confirmation
                        cout << "Sold Tribble(s) to customer " << ID << endl;
                        printSaleConfirmation(customerList[foundList[0]]->getFullName(), quant, amountPaid, date);

                        break;

                    case 2: // Return to main menu
                        break;

                    default: // Invalid input
                        printInvalid();
                        break;
                }
                break;

            case 5: // User prompted to add customer to rainbow tribble queue
                cout << "\nWhat would you like to do?\n";
                cout << "(1) Add Customer to Queue\n";
                cout << "(2) Sell to Customer on Queue\n";
                cout << "\nEnter an above number to continue: ";
                cin >> choice;

                //---------------------submenu----------------------
                switch (choice) {
                    case 1:
                        cout << "Enter customer ID to add to queue: ";
                        cin >> ID;
                        //check if id is already on the list
                        if (checkDupID(rainbowList, ID)) {
                            cout << "Customer " << ID << " is already on the list"
                                    << endl;
                        }// check if it is a valid id
                        else if (!checkDupID(customerList, ID)) {
                            cout << "Error! No match was found for ID " + ID << endl;
                        }// otherwise, add customer to the list
                        else {
                            cout << "Added customer " << ID << " to the list" << endl;
                            rainbowList.push_back(ID);
                        }

                        break;
                    case 2:
                        //copy - Customer Sale menu

                        //temporary output:
                        if (rainbowList.empty()) {
                            cout << "\nThe waiting list for Rainbow Tribble(S) is empty"
                                    << endl;
                            break;
                        }
                        cout << "\nSold Rainbow Tribble(s) to customer " << rainbowList.front()
                                << endl;
                        
                        // find customer record for printing sale confirmation
                        foundList = searchID(customerList, rainbowList.front());
                        // create timestamp
                        date = generateTimeStamp();
                        
                        // Generate new transaction
                        transactionID = generateTransactionID(transactionList);
                        newTransaction = new Transaction(rainbowList.front(), transactionID);
                        transactionList.push_back(newTransaction);
                        
                        // Generate new order
                        orderID = transactionID;
                        newOrder = new Order(orderID, date, 1, prices.at(0));
                        orderList.push_back(newOrder);
                        
                        // print sale confirmation
                        printSaleConfirmation(customerList[foundList[0]]->getFullName(), 1, prices.at(0), date);
                        rainbowList.pop_front();
                        break;
                    default:
                        printInvalid();
                        break;
                }
                break;

            case 6: // Exit
                updateRecordFile(customerList, cSize);
                updateOrders(orderList, oSize);
                updateTransactions(transactionList, tSize);
                updateDeque(rainbowList);

                exit = true;
                break;
            default:
                printInvalid();
                break;
        }
    }
    return 0;
}
