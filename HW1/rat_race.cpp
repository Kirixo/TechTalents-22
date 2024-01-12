//
// Created by Kirixo on 25/11/2023.
//
#include <iostream>
#include <vector>
//#include <chrono>

const long long MOD = 1e9 + 7;

std::vector<std::vector<long long>> multiply(const std::vector<std::vector<long long>>& a,
                                       const std::vector<std::vector<long long>>& b) {
    long long n = a.size();
    std::vector<std::vector<long long>> result(n, std::vector<long long>(n, 0));

    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            for (long long k = 0; k < n; ++k) {
                result[i][j] += (a[i][k] * 1LL * b[k][j]) % MOD;
                result[i][j] %= MOD;
            }
        }
    }

    return result;
}

std::vector<std::vector<long long>> bin_pow(const std::vector<std::vector<long long>>& base, long long k) {
    long long n = base.size();
    std::vector<std::vector<long long>> result(n, std::vector<long long>(n, 0));

    for (long long i = 0; i < n; ++i) {
        result[i][i] = 1;
    }

    std::vector<std::vector<long long>> temp = base;
    while (k > 0) {
        if (k & 1) {
            result = multiply(result, temp);
        }
        temp = multiply(temp, temp);
        k >>= 1;
    }

    return result;
}

int main() {
    long long n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<long long>> g(n, std::vector<long long>(n, 0));
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        std::cin >> a >> b;
        g[a - 1][b - 1] ++;
    }
    //auto start = std::chrono::steady_clock::now();
    std::vector<std::vector<long long>> result_matrix = bin_pow(g, k);

    long long counter = 0;
    for (long long i = 0; i < n; ++i) {
        counter += result_matrix[0][i] % MOD;
        counter %= MOD;
    }
    //auto end = std::chrono::steady_clock::now();
    //std::cout << "time:   " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "\n";

    std::cout << counter;

    return 0;
}