#ifndef STRING_H
#define STRING_H

#include <iostream>
#include "memtrace.h"

#ifndef MEMTRACE
#endif // MEMTRACE

/**
 * A String osztály.
 * A 'pData'-ban vannak a karakterek (a lezáró nullával együtt), 'len' a hossza.
 * A hosszba nem számít bele a lezáró nulla.
 *
 * Korábban a len adattag unsigned int típusú volt. Most helyette a size_t típust használjuk.
 * Ezzel a típussal tér vissza a sizeof operator is, később több helyen ezt használjuk
 * mérettípusként.

 */
class String {
    char *pData;        ///< pointer az adatra
    size_t len;         ///< hossz lezáró nulla nélkül
public:
/// Kiírunk egy Stringet (debug célokra)
/// Ezt a tagfüggvényt elkészítettük, hogy használja a hibák felderítéséhez.
/// Igény szerint módosítható
/// @param txt - nullával lezárt szövegre mutató pointer.
///              Ezt a szöveget írjuk ki a debug információ előtt.
    void printDbg(const char *txt = "") const {
        std::cout << txt << "[" << len << "], "
                  << (pData ? pData : "(NULL)") << '|' << std::endl;
    }

/// Az első két feladatot előre megoldottuk, de lehet, hogy nem jól.
/// Az üres sztring reprezentációja nem szerencsés, mert így NULL pointerré
/// konvertál a c_str(), ami külön kezelést igényel a későbbiekben.
/// Ezt a teszt program sem fogadja el.
/// Gondolja végig, és változtassa meg!
/// Két lehetőség van:
///     a) nem NULL pointert tárol, hanem ténylegesen üres sztringet.
///     b) NULL-t tárol, de a c_str() üres sztringet ad vissza helyette
/// Bármelyik megoldás jó, mert ez az osztály belügye.


    /// Paraméter nélküli konstruktor:
    String() :pData(0), len(0) {};

    /// Sztring hosszát adja vissza.
    /// @return sztring tényleges hossza (lezáró nulla nélkül).
    size_t size() const { return len; }

    /// C-sztringet ad vissza
    /// @return pointer a tárolt, vagy azzal azonos tartalmú nullával lezárt sztring-re.
    const char* c_str() const {
            if(len==0)return "";
            return pData;
         }

/// Itt folytassa a tagfüggvények deklarációit a feladatoknak megfelelően.
/// ...

    String(const char c);
    String(const char* c);
    ~String();

    String(const String& str);

    String& operator=(const String& str);
    const String& operator+(const String& str) const;
    String& operator+(const String& str);
    String& operator+(char c);
    const String& operator+(char c) const;
    char& operator[](size_t idx);
    const char& operator[](size_t idx) const;


}; /// Itt az osztály deklarációjának vége
std::ostream& operator<<(std::ostream& os, const String& s0);
#endif
