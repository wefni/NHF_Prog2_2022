#ifndef VONATOK_HETERO_H
#define VONATOK_HETERO_H
#include "vonatok.h"
#include "memtrace.h"

class Tarolo{
    Vonatok** vonat;
    size_t length;
public:
    Tarolo():vonat(NULL),length(0){}
    size_t size();
    void add(Vonatok* train);
    void del(Vonatok* train);
    Vonatok*& operator[](size_t idx) const;
    ~Tarolo();
};
#endif // VONATOK_HETERO_H
