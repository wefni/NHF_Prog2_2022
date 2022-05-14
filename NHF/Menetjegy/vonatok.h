#ifndef VONATOK_H
#define VONATOK_H
#include "string5.h"
#include "memtrace.h"
#include "allomasok.h"

class Vonatok{
    int Class_T;    //Osztaly szam (1 vagy 2)
    int Train_SNum; //A vonat széria száma (4 szám)
    int TravellingTime; //Menetidő percben(0<x<1000)
    Allomasok Stations;  //Állomások (Honna-hova)
public:
    Vonatok():Class_T(0),Train_SNum(0),TravellingTime(0),Stations(){}
    Vonatok(int c,int t_snum,int tt,Allomasok all);
    int getClass();
    int getSerial();
    int getTravTime();
    Allomasok getAll();
};

#endif // VONATOK_H
