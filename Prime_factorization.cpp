#include <iostream>
#include <vector>

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

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    long long number;
    std::cin >> number;
    std::vector primeFactors = primeFactorization(number);

    std::cout << number << " = ";
    for(int i = 0; i < primeFactors.size()-1; ++i){
        std::cout << primeFactors[i].prime << "^" << primeFactors[i].power << " * ";
    }
    std::cout << primeFactors[primeFactors.size()-1].prime << "^" << primeFactors[primeFactors.size()-1].power << "\n";
}
