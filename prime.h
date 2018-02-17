#ifndef PRIME_H
#define PRIME_H

#include <cmath>

class Prime {
private:
    int number;
public:
    Prime();
    ~Prime();

    bool isPrime(int number);
    void setAText();
};

#endif // PRIME_H
