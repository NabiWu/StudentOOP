#include <iostream>
#include <string>
#include <vector>
#include "weather.h"



using namespace std;
const double F_TO_C = 5/9;
const double C_TO_F = 9/5;

//This is the date constructor
Date ::Date(int d, int m, int y){
    if ((d<1) || (d>31)) throw(d);
    if ((m<1) || (m>12)) throw(m);
    if ((y<1800) || (y>2200)) throw(y);
    
    day = d;
    month = m;
    year = y;
};

ostream& operator << (ostream& os, const Date& date){
    
    os << date.month << "/"<< date.day << "/" << date.year;
    return os;
    
};



//Image class
Image:: Image(int w, int h, string flnm)
    : width(w),height(h), filename(flnm)
{
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
    cout<< "Displaying image "<<s<<endl;
    return s;
}


string Gif::display(string s){
    cout<< "Displaying Gif "<<s<<endl;
    return s;
}

string Jpeg::display(string s){
    cout<< "Displaying Jpeg "<<s<<endl;
    return s;
}

string Png::display(string s){
    cout<< "Displaying Png "<<s<<endl;
    return s;
}



//WReading Class
double WReading::get_tempF()const{
    return (temperature* C_TO_F) +32;
}

void WReading::display_image()const{
    if (!image) cout<<"No image for reading "<< date<<endl;
    else image->display("from wreading");
}

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

void Weather::display_images()const{
    for (WReading wr: wreadings){
        wr.display_image();
    }
}

ostream& operator << (ostream& os, const Weather& w){
    os << w.get_name() << ": rating："<< w.get_rating()<<" "<<w.my_loc<<endl;
    for (WReading wr : w.wreadings ){
        os << "   "<< wr <<endl;
    };
    return os;
};



