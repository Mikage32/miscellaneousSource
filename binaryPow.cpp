#include <iostream>
using namespace std;

template<typename T>
T binaryPow(T radix, T index, T mod){
    radix %= mod;
    while(T > 0){
        radix *= (radix * (radix*(index&1)))%mod;
        radix %= mod;
        index = index >> 1;
    }

    return radix;
}

int main(){
    unsigned long long radix, index, mod;
    cin >> radix, index, mod;

    cout << binaryPow(radix, index, mod) << "\n";
}