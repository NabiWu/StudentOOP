#include <iostream>
#include "vector.h"
using namespace std;


void print_vector(const MyVec& v){
    for (int i =0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<< endl;
}


MyVec::MyVec(){
    sz = 0;
    capacity = DEF_CAPACITY;
    data = new int[DEF_CAPACITY];
}


MyVec::MyVec(const MyVec& v2){
    capacity = v2.capacity;
    sz = v2.sz ;
    
    data = new int[capacity];
    //copy over existing data
    for (int i =0;i<size();i++){
        data[i] = v2.data[i];
    }
}






MyVec:: ~MyVec(){
    delete[] data;
}
MyVec&MyVec:: operator=(const MyVec& v2){
    if (&v2 != this){
        delete[] data;
        capacity = v2.capacity;
        sz = v2.size() ;
        data = new int[capacity];
        for (int i =0;i<size();i++){
            data[i] = v2.data[i];
        }
    }
    
    
    return *this;
}

void MyVec::push_back(int val){
    if (sz == capacity){
        cout<<"Increasing capacity\n";
        //get new array of capacity *2
        
        capacity *= 2;
        int* new_data = new int[capacity];
        //copy over existing data
        for (int i =0;i<size();i++){
            new_data[i] = data[i];
            
        }
        //delete old array
        delete[] data;
        //set pointer to new array
        data = new_data;
    }
    //post increment increase the size and set the val
    data[sz++] = val;
}




//Operator overloading
int MyVec:: operator[](int i) const{
    return data[i];
}

int& MyVec:: operator[](int i){
    return data[i];
}


bool operator==(MyVec& v1, MyVec& v2) {
    if (v1.size() == v2.size()){
        for (int i =0; i <v1.size();i++){
            if (v1[i]!=v2[i]){
                return false;
            }
        }
         return true;
    }
    return false;
}








