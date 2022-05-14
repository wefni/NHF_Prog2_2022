#include "string5.h"
#include "felhasznalo.h"
#include "memtrace.h"
#include <string.h>

Felhasznalo::Felhasznalo(String un,String pw,Menetjegy j, Bankszamla sz){
    if(strlen(un.c_str())>15||strlen(pw.c_str())>15) throw "Túl hosszú felhasználónév vagy jelszó!";
    Username = un;
    Password = pw;
    Jegy = j;
    Szamla = sz;
}

String Felhasznalo::getUsern(){
    return Username;
}
String Felhasznalo::getPW(){
    return Password;
}
Menetjegy Felhasznalo::getJegy(){
    return Jegy;
}
Bankszamla Felhasznalo::getSzamla(){
    return Szamla;
}
