#ifndef FELHASZNALO_H
#define FELHASZNALO_H
#include "string5.h"
#include "menetjegy.h"
#include "memtrace.h"
#include "bankszamla.h"

class Felhasznalo{
    String Username;
    String Password;
    Menetjegy Jegy;
    Bankszamla Szamla;
public:
    Felhasznalo(): Username(),Password(),Jegy(),Szamla(){}
    Felhasznalo(String un,String pw,Menetjegy j, Bankszamla sz);
    String getUsern();
    String getPW();
    Menetjegy getJegy();
    Bankszamla getSzamla();
};
#endif // FELHASZNALO_H
