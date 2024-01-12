//
// Created by Kirixo on 18/11/2023.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

int main(){
    long long n;
    std::cin >> n;
    auto start = std::chrono::steady_clock::now();
    std::vector<long long> results(n+1, -1);
    std::vector<std::vector<std::pair<long long, long long>>> dp;
    dp.reserve(n);
    dp.push_back(std::move(std::vector<std::pair<long long, long long>>(1, std::pair<long long, long long>(1, 0))));
    results[1] = 0;
    long long counter = 0;
    for(long long j = 0; j < dp.size(); ++j){
        dp.push_back(std::move(std::vector<std::pair<long long, long long>>()));
        for(long long i = 0; i < dp[j].size(); ++i){
            long long temp;
            temp = dp[j][i].first * 2;
            if(temp <= n && results[temp] == -1){
                dp[j+1].push_back(std::move(std::pair<long long, long long>(temp, dp[j][i].first)));
                results[temp] = j + 1;
                counter++;
            }
            temp = dp[j][i].first * 3;
            if(temp <= n && results[temp] == -1){
                dp[j+1].push_back(std::move(std::pair<long long, long long>(temp, dp[j][i].first)));
                results[temp] = j + 1;
                counter++;
            }
            temp = dp[j][i].first + 1;
            if(temp <= n && results[temp] == -1){
                dp[j+1].push_back(std::move(std::pair<long long, long long>(temp, dp[j][i].first)));
                results[temp] = j + 1;
                counter++;

            }
        }
        if(results[n] > -1){
            break;
        }
    }

    printf("%lld   %lld\n", results[n], dp[results[n]].size());

    std::vector<long long> res;
    res.reserve(dp.size());
    res.push_back(n);
    for(long long tn = n, i = results[tn]; tn > 1; ){
        for(auto j : dp[i]){
            if(j.first == tn) {

                tn = j.second;
                i = results[tn];
                res.push_back(tn);
                break;
            }
        }
    }

    std::reverse(res.begin(), res.end());

    for(auto i : res){
        printf("%lld ", i);
    }

    auto end = std::chrono::steady_clock::now();
    std::cout << "time:   " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
/*
    printf("\n\n\n");
    for(const auto &i : dp){
        for(const auto &j : i){
            printf("%lld(%lld) ", j.first, j.second);
        }
        printf("\n");
    }

    printf("\n");
    for(auto i : results){
        printf("%lld ", i);
    }
    */
    return 0;
}