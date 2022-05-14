#include "vonatok_hetero.h"
#include "memtrace.h"

void Tarolo::add(Vonatok* train){

    Vonatok** temp = new Vonatok*[length+1];

    for(size_t i = 0;i<length;i++){
        temp[i] = vonat[i];
    }
    temp[length] = train;
    length++;
    delete[] vonat;
    vonat = temp;

}

void Tarolo::del(Vonatok* train){
   if(length != 0){
        Vonatok** temp = new Vonatok*[length-1];
        size_t i;

        for(i=0;i<length;i++){
            if(vonat[i]->getSerial()==train->getSerial()){
                delete vonat[i];
                break;
            }
        }
        int d = 0;
        for(size_t j = 0;j<length;j++){
            if(j!=i){
                temp[d] = vonat[j];
                ++d;
            }
        }
        length--;
        delete[] vonat;
        vonat = temp;

   }
}

size_t Tarolo::size(){
    return length;
}

Vonatok*& Tarolo::operator[](size_t idx) const{
    return vonat[idx];
}

Tarolo::~Tarolo(){
    for(size_t i = 0;i<length;i++){
        delete vonat[i];
    }
    delete[] vonat;
}
