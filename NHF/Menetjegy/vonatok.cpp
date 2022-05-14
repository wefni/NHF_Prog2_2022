#include "vonatok.h"
#include "string5.h"
#include "memtrace.h"
#include <iostream>
#include <fstream>
#include <string>

Vonatok::Vonatok(int c,int t_snum,int tt,Allomasok all){

    if(c>2||c<0||t_snum<1000||t_snum>9999||tt<1||tt>1000){
        throw "Hibás adat!";
    }else{
        Class_T = c;
        Train_SNum = t_snum;
        TravellingTime = tt;
    }
    bool vane = false;
    bool vane2 = false;
    std::string line;
    std::ifstream file("telepulesek.txt");
    if(file.is_open()){
        while(std::getline(file,line)){
            if(all.getFrom().c_str() == line) vane = true;
            if(all.getTo().c_str() == line) vane2 = true;
        }
        file.close();
    }else{
        std::cout<<"Nem sikerult megnyitni a fájlt!";
    }
    if(!vane || !vane2){
        throw "Nem létezik ilyen település!";
    }else{
        Stations = all;
    }

}

int Vonatok::getClass(){
    return Class_T;
}
int Vonatok::getSerial(){
    return Train_SNum;
}
int Vonatok::getTravTime(){
    return TravellingTime;
}
Allomasok Vonatok::getAll(){
    return Stations;
}
