#ifndef DATE_H
#define DATE_H


#include <string>
#include <vector>
using namespace std;


class Date{
    friend ostream& operator << (ostream& os, const Date& date);
public:
    Date(int d, int m, int y);
private:
    int day;
    int month;
    int year;
};

#endif
