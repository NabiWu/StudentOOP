#include <cassert>
#include <iostream>
#include <fstream>
#include "../my_code/weather.h"

using namespace std;

string get_input_file(){
    string filenm;
    cout << "Input the name of the new reading file:\n";
    cin >> filenm;
    return filenm;
};

void get_wreadings(string filenm, Weather& w){
    ifstream rfile(filenm);
    while(!rfile){
        cout<< "Could not read input file."<< endl;
        rfile.open(get_input_file());
    };
   
    int m,d,y;
    double temp,hum,ws;
    while(rfile>>m>>d>>y>>temp>>hum>>ws){
        WReading wr = WReading(Date(d,m,y),temp, hum, ws);
        w.add_reading(wr);
    };
    rfile.close();
}

int main() {
    GPS loc = GPS(46.3, 67.2);
    Weather irkutsk = Weather("Irkutsk", loc);
    
    string filenm;
    cout << "Input the name of the new readings file:" << endl;
    cin >> filenm;
    
   
    
    get_wreadings(filenm, irkutsk);
    cout << irkutsk << endl;
    exit(0);
    
    
    
    
    
    
    
    
    
    //int rate = 2;
    //cout << filenm << endl;
    //Date test_date(15,12,2019);
    //cout << test_date<< endl;
    //WReading wr = WReading (Date(17 ,12, 2000),78.2, 43.6, 12.3);
    //cout << wr << endl;
    //cout << irkutsk.get_name() << endl;
}

