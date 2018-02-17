#include "prime.h"
#include "music.h"

Prime::Prime() {
    //constructor
}

bool Prime::isPrime(int number) {
    if(number<2) {
        return false;
    }

    for(int i=2; i<=sqrt(number); i++)
        if(number%i==0)
            return false;
    return true;
}

Prime::~Prime() {
    //destructor
}
