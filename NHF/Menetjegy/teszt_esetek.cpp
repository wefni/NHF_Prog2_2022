#include "allomasok.h"
#include "string5.h"
#include "teszt_esetek.h"
#include "gtest_lite.h"
#include "vonatok.h"
#include "menetjegy.h"
#include "bankszamla.h"
#include "felhasznalo.h"
#include "vonatok_hetero.h"
#include "memtrace.h"
#include <iostream>
#include <fstream>
#include <string>


void tesztek(){

    Allomasok a("Budapest","Zalaegerszeg");
    Vonatok v(1,2323,180,a);
    Menetjegy j(1250,045,1111,v);
    Bankszamla b("Halász Dávid","1234 5678 9012 3456","07/24",123);
    Felhasznalo f("asd","123",j,b);

    Tarolo t;

    TEST(allomas,String){
        EXPECT_STREQ(a.getFrom().c_str(),"Budapest")<< "Az indulasi hely nem jo!";
        EXPECT_STREQ(a.getTo().c_str(),"Zalaegerszeg")<< "Az erkezesi hely nem jo!";
    }
    END

    TEST(vonat,int){
       EXPECT_GE(v.getClass(),1)<<"Nem jo az osztalyszam!";
       EXPECT_EQ(v.getSerial(),2323)<<"Nem jo az szeria szam!";
       EXPECT_EQ(v.getTravTime(),180)<<"Nem jo a menetido!";
    }
    END

    TEST(menetjegy,int){
       EXPECT_EQ(j.getPrice(),1250)<<"Nem annyi!";
       EXPECT_GT(j.getSeat(),0)<<"Nem helyes!";
       EXPECT_GT(j.getTNum(),0)<<"Nem helyes!";
    }
    END

    TEST(Tarolo,String){
        Tarolo t;
        Allomasok a("Győr","Budapest");
        Vonatok *v = new Vonatok(1,1230,180,a);
        Vonatok *v2 = new Vonatok(2,1220,180,a);
        Vonatok *v3 = new Vonatok(2,2315,180,a);
        Vonatok *v4 = new Vonatok(2,2133,180,a);

        t.add(v);
        t.add(v2);
        t.add(v3);
        t.add(v4);

        EXPECT_STREQ(t[0]->getAll().getFrom().c_str(),"Győr");
        std::cout<<t.size()<<std::endl;
        t.del(v3);
        std::cout<<t.size()<<std::endl;
    }
    END

    TEST(IrasFileba,ofstream){
        std::ofstream file("Menetrend.txt");
        Allomasok a1("Győr","Budapest");
        Allomasok a2("Zalaegerszeg","Budapest");
        Tarolo t;
        t.add(new Vonatok(2,1232,180,a1));
        t.add(new Vonatok(1,4322,180,a2));

        if(file.is_open()){
            for(size_t i = 0;i<t.size();i++){
                file<<t[i]->getAll().getFrom().c_str() << " "
                    <<t[i]->getAll().getTo().c_str() << " "
                    <<t[i]->getClass() << " "
                    <<t[i]->getSerial() << " "
                    <<t[i]->getTravTime()<<std::endl;
            }
            file.close();
        }
    }
    END

    TEST(utzi,gfds){



    }
    END
}
