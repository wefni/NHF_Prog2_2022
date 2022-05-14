#ifndef ALLOMASOK_H
#define ALLOMASOK_H
#include "string5.h"
#include "memtrace.h"

class Allomasok{
    String From;
    String To;
public:
    Allomasok(): From(),To(){}
    Allomasok(String from,String to): From(from),To(to){};
    String getFrom() const;
    String getTo() const;
    Allomasok& operator=(const Allomasok& a);
};

#endif// ALLOMASOK_H
