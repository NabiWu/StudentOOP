#include <iostream>
#include <string>
#include <vector>
#include "weather.h"


using namespace std;





ostream& operator << ( ostream& os, const GPS& gps){
    os << "latitude: "<< gps.latitude<< "; longitude: "<<gps.longitude;
    return os;
}



ostream& operator << (ostream& os, const WReading& wr){
    os << wr.date << ": temp: "<< wr.temperature
    << " : humid :"<<wr.humidity << " : wind:"<<wr.windspeed;
    return os;
};
/*
 * A constructor for weather class.
 * */

Weather::Weather(string nm, GPS loc) :
    station_nm(nm), my_loc(loc) {
}


string Weather::get_name()const {
    return station_nm;
}



int Weather:: get_rating() const {
    return rating;
}


void Weather:: set_rating(int new_rating){
    rating = new_rating;
}

void Weather:: add_reading(WReading wr){
    wreadings.push_back(wr);
};

ostream& operator << (ostream& os, const Weather& w){
   
    //w.set_rating(20);
    os << w.get_name() << ": rating："<< w.get_rating()<<" "<<w.my_loc<<endl;
    for (WReading wr : w.wreadings ){
        os << "   "<< wr <<endl;
    };
    return os;
};
