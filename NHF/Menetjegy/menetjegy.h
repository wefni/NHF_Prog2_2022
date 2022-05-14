#ifndef MENETJEGY_H
#define MENETJEGY_H
#include "string5.h"
#include "memtrace.h"
#include "vonatok.h"

class Menetjegy{
    Vonatok Train;
    int Price;
    int Seat;
    int TicketNum;

public:
    Menetjegy(): Train(),Price(0),Seat(0),TicketNum(0){}
    Menetjegy(int p,int s,int tnum,Vonatok v):Train(v),Price(p),Seat(s),TicketNum(tnum){};
    int getPrice();
    int getSeat();
    int getTNum();
    Vonatok getTrain();

     void jegyKiir();
};

class Kedvezmeny: public Menetjegy{
    bool diak;
public:
    Kedvezmeny():Menetjegy(), diak(false){}
    Kedvezmeny(bool vane, Menetjegy jegy);
};
#endif // MENETJEGY_H
