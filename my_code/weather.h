#ifndef WEATHER_H
#define WEATHER_H

#include <string>
#include <vector>
#include "date.h"
using namespace std;

struct GPS {
    double latitude;
    double longitude;
    GPS(double la, double lo): latitude(la), longitude(lo){}
};

ostream& operator << (ostream& os, const GPS& gps);





class WReading{
    friend ostream& operator << (ostream& os, const WReading& wr);
public:
    WReading(Date dt, double temp, double hum, double ws):
    date(dt), temperature(temp), humidity(hum), windspeed(ws){}
private:
    Date date;
    double temperature;  //stored temp in C
    double humidity;
    double windspeed;
    
};


const int UNRATED = -1;
const int BAD = 0;
const int OK = 1;
const int GOOD = 2;

class Weather {
    friend ostream& operator << (ostream& os, const Weather& w);
    
public:
    Weather(string nm, GPS loc);
    string get_name() const;
    int get_rating() const;
    void set_rating(int new_rating);
    void add_reading(WReading wr);
    
    
private:
    vector<WReading> wreadings;
    string station_nm;
    GPS my_loc;
    int rating = UNRATED;
};




#endif
