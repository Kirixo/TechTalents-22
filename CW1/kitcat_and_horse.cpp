//
// Created by Kirixo on 11/12/2023.
//
#include <bits/stdc++.h>

std::vector<long long> cards;
std::vector<long long> cards2;


void print(long long n, long long w, const std::vector<std::vector<long long>>& dp, std::multiset<long long>& v) {
    if(dp[w][n] == 0) {
        return;
    }
    if(dp[w][n-1] == dp[w][n]) {
        print(n-1, w, dp, v);
    } else {
        print(n-1, w-cards[n-1], dp, v);
        v.insert(cards[n-1]);
    }
}

void print1(long long n, long long w, const std::vector<std::vector<long long>>& dp) {
    if(dp[w][n] == 0) {
        return;
    }
    if(dp[w][n-1] == dp[w][n]) {
        print1(n-1, w, dp);
    } else {
        print1(n-1, w-cards2[n-1], dp);
        printf("%lld ", n);
    }
}

int main(){
    long long weight, n;
    std::cin >> weight >> n;
    cards.resize(n);

    long long sum = 0;
    for(long long i = 0; i < n; ++i) {
        std::cin >> cards[i];
        sum += cards[i];
    }
    sum -= weight;

    long long maxV;
    std::multiset<long long> v1;
    std::vector<std::vector<long long>> dp1(sum+1, std::vector<long long>(n+1, 0));
    {

        for(long long i = 1; i <= sum; ++i){
            for(long long j = 1; j <= n; ++j){
                if(cards[j-1] <= i){
                    dp1[i][j] = std::max(dp1[i][j-1],
                                        dp1[i-cards[j-1]][j-1] + cards[j-1]);
                } else {
                    dp1[i][j] = dp1[i][j-1];
                }
            }
        }
        maxV = dp1[sum][n];
        print(n, sum, dp1, v1);
    }





    if(maxV == sum) {
        cards2 = cards;
        std::sort(cards.begin(), cards.end(), [](long long a, long long b){return a > b;});
        std::vector<std::vector<long long>> dp(sum+1, std::vector<long long>(n+1, 0));
        for(long long i = 1; i <= sum; ++i){
            for(long long j = 1; j <= n; ++j){
                if(cards[j-1] <= i){
                    dp[i][j] = std::max(dp[i][j-1],
                                        dp[i-cards[j-1]][j-1] + cards[j-1]);
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        std::multiset<long long> v2;
        print(n, sum, dp, v2);


        if(v1 != v2) {
            std::cout << -1;
        } else {

            std::map<long long, long long> mm;
            for(auto it : cards) {
                if(mm[it]) {
                    mm[it]++;
                } else {
                    mm[it] = 1;
                }
            }

            for(auto it : v1) {
                if (mm[it] > v1.count(it)) {
                    std::cout << -1;
                    return 0;
                }
            }

            print1(n, sum, dp1);
        }
    } else {
        std::cout << 0;
    }
//    printf("\n\n");
//    for(auto vec : dp){
//        for(auto i : vec){
//            printf("%i  ", i);
//        }
//        printf("\n");
//    }
    return 0;
}