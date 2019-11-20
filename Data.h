#ifndef PROJECT8_DATA_H
#define PROJECT8_DATA_H

#include <iostream>
using namespace std;
class Data{
public:
    Data();
    Data(double rank, string name, double sales, int year);
    friend const ostream& operator<<( ostream& os, Data d);
    bool operator<(const Data& rhs) const;
    bool operator>(const Data &rhs) const;
private:
    double rankP;
    string nameP;
    double salesP;
    int yearP;
};

#endif //PROJECT8_DATA_H
