/*
written by Mikage32
This is a program that uses the "findDivisor" function to calculate and return divisors after factoring the number (long long) received as an argument.
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct primeFactor{
    long long prime;
    long long power;
};

std::vector<primeFactor> primeFactorization(long long number){
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

    return primeFactors;
}

int countDivisor(std::vector<primeFactor> primeFactors){
    int counter = 1;
    for(int i = 0; i < primeFactors.size(); ++i){
        counter *= (primeFactors[i].power + 1);
    }

    return counter;
}

std::vector<long long> findDivisor(long long number){
    std::vector<primeFactor> primeFactors = primeFactorization(number);

    std::vector<long long> divisor(countDivisor(primeFactors));
    divisor[0] = 1;

    int counter = 1;
    for(int i = 0; i < primeFactors.size(); ++i){
        int currentSize = counter;
        for(int j = 1; j <= primeFactors[i].power; ++j){
            long long x = 1;
            for(int k = 0; k < j; ++k){
                x *= primeFactors[i].prime;
            }

            for(int k = 0; k < currentSize; ++k){
                divisor[counter + k] = divisor[k] * x;
            }
            counter += currentSize;
        }
    }
    sort(divisor.begin(), divisor.end());

    return divisor;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    
    long long number;
    std::cin >> number;

    std::vector<long long> divisor = findDivisor(number);

    std::cout << "The number of divisor is " << divisor.size() << "\n";
    for(int i = 0; i < divisor.size(); ++i){
        std::cout << divisor[i] << "\n";
    }
}
