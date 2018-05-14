/* File: customer.cpp
 * Author: Brandon Youngquist, Hai Le
 *
 * Created on April 22, 2018
 */
#include "customer.h"

using namespace std;

Customer::Customer() {
	this->ID = "0";
    this->fname = "";
    this->lname = "";
    this->street = "";
    this->city = "";
    this->state = "";
    this->zip = "no_zip";
}

Customer::Customer(string ID, string fname, string lname, string street, string city, string state, string zip) {
    this->ID = ID;
    this->fname = fname;
    this->lname = lname;
    this->street = street;
    this->city = city;
    this->state = state;
    this->zip = zip;
}

string Customer::getID() {
    return ID;
}

string Customer::getFname() {
    return fname;
}

string Customer::getLname() {
    return lname;
}

string Customer::getFullName() {
    return fname + " " + lname;
}

string Customer::getStreet() {
    return street;
}

string Customer::getCity() {
    return city;
}

string Customer::getState() {
    return state;
}

string Customer::getZip() {
    return zip;
}


string Customer::getAddress() {
    return street + "\n\t" + city + ", " + state + " " + zip;
}

void Customer::setID(string ID) {
    this->ID = ID;
}

void Customer::setFname(string fname) {
    this->fname = fname;
}

void Customer::setLname(string lname) {
    this->lname = lname;
}

void Customer::setStreet(string street) {
    this->street = street;
}

void Customer::setState(string state) {
    this->state = state;
}

void Customer::setZip(string zip) {
    this->zip = zip;
}
