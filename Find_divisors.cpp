#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

template<typename T>
constexpr std::vector<std::pair<T, T>> primeFactorization(T number) noexcept {
	std::vector<std::pair<T, T>> primeFactors;
	T quotient = number;
	for (T i = 2; i * i <= quotient; ++i) {
		if (quotient % i == 0) {
			T prime = i, power = 1;

			quotient /= i;
			while (quotient % i == 0) {
				++power;
				quotient /= i;
			}

			primeFactors.push_back(std::pair<T, T>(prime, power));
		}
	}
	if (quotient != 1) primeFactors.push_back(std::pair<T, T>(quotient, 1));

	return primeFactors;
}

template<typename T>
constexpr int countDivisor(std::vector<std::pair<T, T>> primeFactors) noexcept {
	int counter = 1;
	for (int i = 0; i < primeFactors.size(); ++i) {
		counter *= (primeFactors[i].second + 1);
	}

	return counter;
}

template<typename T>
constexpr std::vector<T> findDivisor(T number) noexcept {
	std::vector<std::pair<T, T>> primeFactors = primeFactorization(number);

	std::vector<T> divisor(countDivisor(primeFactors));
	divisor[0] = 1;

	int counter = 1;
	for (int i = 0; i < primeFactors.size(); ++i) {
		int currentSize = counter;
		for (int j = 1; j <= primeFactors[i].second; ++j) {
			T x = 1;
			for (int k = 0; k < j; ++k) {
				x *= primeFactors[i].first;
			}

			for (int k = 0; k < currentSize; ++k) {
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
    
    int sum = 0;
    for(int x = 0; x < 100; ++x){
        auto startTime = std::chrono::system_clock::now();
        for(long long i = 1; i < 100000; ++i){
            std::vector<long long> divisor = findDivisor(i);
        }
        auto endTime = std::chrono::system_clock::now();
        auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(endTime-startTime).count();
        sum += msec;
    }
    std::cout << "avr = " << sum/100 << " mSec Number of tests=100\n";
}
