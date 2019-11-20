//
// Created by Steven on 11/14/2019.
//

#include "Data.h"
#include <iostream>

Data::Data() { //Default constructor for data objects
    rankP = 0;
    nameP = "";
    salesP = 0;
    yearP =  0;
}
Data::Data(double rank, string name, double sales, int year) {
    rankP = rank;
    nameP = name;
    salesP = sales;
    yearP = year;
}

const ostream& operator<<( ostream &os, Data d) { //Overloaded output operator
    os << d.nameP << ", Year: " << d.yearP << " Rank: " << d.rankP << " Sales: " << d.salesP << endl;
    return os;
}

//Overloaded comparison operators to be used when sorting elements
bool Data::operator<(const Data &rhs) const {
    return this->yearP < rhs.yearP;
}

bool Data::operator>(const Data &rhs) const {
    return !(*this < rhs);
}




