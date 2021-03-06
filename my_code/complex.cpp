#include <iostream>
#include <istream>
#include <iomanip>
#include "complex.h"
#include <cmath>

using namespace std;



ostream& operator<< (ostream& os, const Complex& c) {
    /*
     * Outputting a `Complex` instance, while illustrating some of the
     * capabilities of I/O streams: `setprecision` gives us a fixed
     * number of decimal places, while `showpos` turns on the plus
     * sign for positive numbers.
     * */
    os << setprecision(10) << c.real << showpos
    << c.imag << "i" << noshowpos << endl;
    return os;
}


/*
 * Read a `Complex` number from an input stream.
 * */
istream& operator>> (istream& is, Complex& c) {
    is >> c.real >> c.imag;
    return is;
}


Complex::Complex(double real, double imag)
: real{real}, imag{imag} {}


Complex::operator bool() const {
    return ((real != 0) || (imag != 0));
}


double Complex::get_real() const {
    return real;
}

double Complex::get_imag() const {
    return imag;
}


Complex& Complex::operator++() {
    ++real;
    return (*this);
}

Complex Complex::operator++(int dummy) {
    Complex temp(*this);
    real++;
    return temp;
}

Complex& Complex::operator--() {
    --real;
    return (*this);
}

Complex Complex::operator--(int dummy) {
    Complex temp(*this);
    real--;
    return temp;
}

Complex Complex::operator-=(const Complex& c){
    real = real - c.real;
    imag = imag - c.imag;
    return *this;
}


Complex Complex :: operator*(const int i){
    Complex temp{real*i,imag*i};
    return temp;
   
}





bool operator == (const Complex& c1, const Complex& c2) {
    cout<< "c1: "<<c1<<endl;
    cout<< "c2: "<<c2<<endl;
    return ( abs(c1.get_real() - c2.get_real())<0.00001 &&  abs(c1.get_imag() - c2.get_imag())<0.00001);
}
bool operator!= (const Complex& c1, const Complex& c2){
    return ((c1.get_real() != c2.get_real()) || (c1.get_imag() != c2.get_imag()));
}


Complex operator+(const Complex& c1, const Complex& c2) {
    Complex sum{c1.get_real() + c2.get_real() , c1.get_imag()+c2.get_imag()};
    return sum;
}
Complex operator-(const Complex& c1, const Complex& c2) {
    Complex sub{c1.get_real() - c2.get_real() , c1.get_imag() - c2.get_imag()};
    return sub;
}
