//
// Created by Kirixo on 25/11/2023.
//
#include <iostream>
#include <map>
//#include <random>
//#include <ctime>
//#include <chrono>

long long K;

std::map<long long, long long> dp;

long long func(long long n, long long res = 0) {
    if(n <= K) {
        return 1;
    }
    return func(n/2, res+1)+((n%2) ? func((n/2)+1, res+1) : func(n/2, res+1));
}

long long solve(long long n, long long res = 0) {
    if(dp[n]) {
        return dp[n];
    }
    if(n <= K) {
        return 1;
    }

    long long x1 = solve(n/2, res+1);
    dp[n/2] = x1;
    long long x2;
    if(n%2) {
        x2 = solve((n/2)+1, res+1);
        dp[(n/2)+1] = x2;
    } else {
        x2 = solve(n/2, res+1);
    }

    return x1+x2;
}



int main() {
//    std::srand(std::time(nullptr));

    long long n;
    std::cin >> n >> K;
    long long res = solve(n);
//    auto start = std::chrono::steady_clock::now();

    //std::cout << solve(n);

//    auto end = std::chrono::steady_clock::now();
//    std::cout << "\ntime:   " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    for(auto i : dp){
        printf("(%lli; %lli)\n", i.first, i.second);
    }

    std::cout << "[" << res << "; " << func(n) << "      " << ((res == func(n)) ? "true" : "false         !!!!!!!!!!!!!!!!!!!!!!!!") << "]\n";


    return 0;
}