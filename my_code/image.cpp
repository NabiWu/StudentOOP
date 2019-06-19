#include <iostream>
#include <string>
#include <vector>
#include "image.h"



using namespace std;


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

