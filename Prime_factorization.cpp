#include <iostream>
#include <vector>
#include <algorithm>

struct primeFactor{
    long long prime;
    long long power;
};

std::vector<long long> primeFactorization(long long number){
    std::vector<primeFactor> primeFactors;
    long long quotient = number;
    for(long long i = 2; i*i <= quotient; ++i){
        if(quotient%i == 0){
            primeFactor pf;
            pf.prime = i;
            pf.power = 1;

            quotient /= i;
            while(quotient%i == 0){
                ++pf.power;
                quotient /= i;
            }

            primeFactors.push_back(pf);
        }
    }
    if(quotient != 1){
        primeFactor pf;
        pf.prime = quotient;
        pf.power = 1;
        primeFactors.push_back(pf);
    }
}