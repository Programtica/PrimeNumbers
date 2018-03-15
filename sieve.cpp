#include "sieve.h"

Sieve::Sieve() {
    //constructor
}

void Sieve::setSieve(int number) {
    bool *check = new bool[number+1];

        if(number<=1) {
            //cout << "Oh, prime numbers can be greater than 1!" << endl;
        } else {
            for(int i=2; i<=number; i++)
                check[i] = false;

            for(unsigned int i=2; i<=sqrt(number); i++) {
                if(check[i] == false) {
                    for(int j=i*i; j<=number; j += i) {
                        check[j] = true;
                }
            }

            //cout << endl << "The prime numbers in this interval:" << endl;

            for(int i=2; i<=number; i++) {
                if(check[i] == false) {
                    //qDebug() << "test";
                }
            }
        }

            delete [] check;
        }
}

Sieve::~Sieve() {
    //dectructor
}
