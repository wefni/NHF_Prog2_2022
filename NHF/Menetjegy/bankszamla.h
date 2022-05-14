#ifndef BANKSZAMLA_H
#define BANKSZAMLA_H
#include "string5.h"
#include "memtrace.h"

class Bankszamla{
    String Cardholder;
    String Cardnum;
    String valid;
    int secNum;
public:
    Bankszamla(): Cardholder(),Cardnum(),valid(),secNum(0){}
    Bankszamla(String f,String cn,String v,int sn);
    String getCNum();
    String getVal();
    int getSecNum();
    String getF();
};
#endif // BANKSZAMLA_H
