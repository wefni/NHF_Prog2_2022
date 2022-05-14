#include "string5.h"
#include "menetjegy.h"
#include "memtrace.h"

int Menetjegy::getPrice(){
    return Price;
}
int Menetjegy::getSeat(){
    return Seat;
}
int Menetjegy::getTNum(){
    return TicketNum;
}
Vonatok Menetjegy::getTrain(){
    return Train;
}

Kedvezmeny::Kedvezmeny(bool vane, Menetjegy jegy)
    : Menetjegy(jegy.getPrice(),jegy.getSeat(),jegy.getTNum(),jegy.getTrain()){
    diak = vane;
}
