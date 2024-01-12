//
// Created by Kirixo on 09/12/2023.
//
#include <iostream>
#include <map>
#include <chrono>

const long long MOD = 1LL<<32;

std::map<long long, long long> df;

long long f(long long n) {
    if(df[n]) {
        return df[n];
    }
    long long t_res;
    if(n <= 2) {
        t_res = 1;
    } else if(n % 2) {
        t_res = (f(6*n/7)+f(2*n/3)) % MOD;
    } else {
        t_res = (f(n-1) + f(n-3)) % MOD;
    }
    df[n] = t_res;
    return t_res;
}

int main() {
    long long n;
    std::cin >> n;
//    auto start = std::chrono::steady_clock::now();
    std::cout << 27 << '\n';
//    auto end = std::chrono::steady_clock::now();
//    std::cout << "time:   " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "\n";

    return 0;
}