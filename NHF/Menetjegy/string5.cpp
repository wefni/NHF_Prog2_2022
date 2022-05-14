/**
 *
 * \file string5.cpp
 *
 * Itt kell megvalósítania a hiányzó tagfüggvényeket.
 * Segítségül megadtuk a C++ nem OO eszközeinek felhasználásával készített String-kezelő
 * függvényke neveit.
 *
 * Ha valamit INLINE-ként valósít meg, akkor annak a string5.h-ba kell kerülnie,
 * akár kívül akár osztályon belül definiálja. (Az inline függvényeknek minden
 * fordítási egységben elérhetőknek kell lenniük)
 * *
 * A teszteléskor ne felejtse el beállítani a string5.h állományban az ELKESZULT makrót.
 *
 */

#ifdef _MSC_VER
// MSC ne adjon figyelmeztető üzenetet a C sztringkezelő függvényeire
  #define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>             // Kiíratáshoz
#include <cstring>
#include "string5.h"
#include "memtrace.h"
// Sztringműveletekhez           // a standard headerek után kell lennie


/// Konstruktorok: egy char karakterből (createString)
///                egy nullával lezárt char sorozatból (createString)

    String::String(const char c){
        pData = new char[2];
        len = 1;
        pData[0] = c;
        pData[1] = '\0';
    }

    String::String(const char* c){
        if(strlen(c)==0){
            pData = new char[2];
            strcpy(pData,"");
        }else{
            len = strlen(c);
            pData = new char[len+1];
            strcpy(pData,c);
        }
    }

/// Másoló konstruktor: String-ből készít (createString)

    String::String(const String& str){
        len = str.len;
        pData = new char[len+1];
        strncpy(pData,str.pData,len);
        pData[len] = '\0';
    }

/// Destruktor (disposeString)

    String::~String(){
        delete[] pData;
    }

/// operator=

    String& String::operator=(const String& str){

        if(this!=&str){
            delete[] pData;
            pData = new char[str.len+1];
            len = str.len;
            strcpy(pData,str.pData);
        }
        return *this;
    }

/// [] operátorok: egy megadott indexű elem REFERENCIÁJÁVAL térnek vissza (charAtString)
/// indexhiba esetén const char * kivételt dob!

    char& String::operator[](size_t idx){
        if(idx>len){
            throw "XTBJD6";
        }
        return pData[idx];
    }

    const char& String::operator[](size_t idx)const{
        if(idx>len){
            throw "XTBJD6";
        }
        return pData[idx];
    }


/// + operátorok:
///                 String-hez jobbról karaktert ad (addString)
///                 String-hez String-et ad (addString)

String& String::operator+(const char c){

    char* temp = new char[len+1];
    strcpy(temp,pData);
    delete [] pData;

    pData = new char[len+2];
    strcpy(pData,temp);
    pData[len+1] = c;
    pData[len+2] = '\0';

    return *this;
}

String& String::operator+(const String& str){

    char* temp = new char[len];
    strcpy(temp,pData);

    delete[] pData;
    pData = new char[(str.len+len)+1];
    strcpy(pData,temp);
    strcat(pData,str.pData);
    pData[(str.len+len)+1] = '\0';

    return *this;

}






/// << operator, ami kiír az ostream-re
std::ostream& operator<<(std::ostream& os, const String& s0) {
    os << s0.c_str();
    return os;
}


/// >> operátor, ami beolvas az istream-ről egy szót
