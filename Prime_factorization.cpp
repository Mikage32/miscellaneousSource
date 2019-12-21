#include <iostream>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;

template<typename T>
constexpr std::vector<std::pair<T, T>> primeFactorization(T number) noexcept {
    std::vector<std::pair<T, T>> primeFactors;
    T quotient = number;
    for(T i = 2; i*i <= quotient; ++i){
        if(quotient%i == 0){
            T prime = i, power = 1;

            quotient /= i;
            while(quotient%i == 0){
                ++power;
                quotient /= i;
            }

            primeFactors.push_back(std::pair<T, T>(prime, power));
        }
    }
    if(quotient != 1) primeFactors.push_back(std::pair<T, T>(quotient, 1));

    return primeFactors;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    mp::cpp_int number;
    std::cin >> number;
    std::vector<std::pair<mp::cpp_int, mp::cpp_int>> primeFactors = primeFactorization(number);

    std::cout << number << " = ";
    for(int i = 0; i < primeFactors.size()-1; ++i){
        std::cout << primeFactors[i].first << "^" << primeFactors[i].second << " * ";
    }
    std::cout << primeFactors[primeFactors.size()-1].first << "^" << primeFactors[primeFactors.size()-1].second << "\n";
}
