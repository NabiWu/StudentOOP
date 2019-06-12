#include <iostream>
#include <string>
#include <vector>
#include "weather.h"



using namespace std;
const double F_TO_C = 5/9;
const double C_TO_F = 9/5;

Image:: Image(int w, int h, string flnm)
    : width(w),height(h), filename(flnm)
{
    filename = flnm;
    image_buf = new char[image_sz()];
}


Image::Image(const Image& img2){
     copy_fields(img2);
}


Image::~Image(){
    if (image_buf != nullptr) delete[] image_buf;
}


Image& Image::operator=(const Image& img2){
    if (&img2 != this){
        if (image_buf != nullptr) delete[] image_buf;
        copy_fields(img2);
    }
    
    return *this;
}


int Image::image_sz(){
    return width*height;
}

void Image::copy_fields(const Image& img2){
    height = img2.height;
    width = img2.width;
    filename = img2.filename;
    image_buf = new char[image_sz()];
    for (int i = 0; i<image_sz(); i++){
        image_buf[i] = img2.image_buf[i];
    }
}


string Image::display(string s){
    return "Displaying image"+s;
}


double WReading::get_tempF(){
    return (temperature* C_TO_F) +32;
}

//double WReading::get_tempC(){
//    return (temperature-32)*(F_TO_C);
//}



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
