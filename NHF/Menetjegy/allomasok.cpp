#include "string5.h"
#include "allomasok.h"
#include "memtrace.h"

String Allomasok::getFrom() const{
    return From;
}

String Allomasok::getTo() const{
    return To;
}

Allomasok& Allomasok::operator=(const Allomasok& a){
    if(this!=&a){
        From = a.From;
        To = a.To;
    }
    return *this;
}
