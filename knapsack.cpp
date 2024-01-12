//
// Created by Kirixo on 04/11/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n, w;
    std::cin >> n >> w;
    std::vector<int> weights(n);
    std::vector<int> prices(n);
    for(int i = 0; i < n; ++i){
        std::cin >> weights[i];
    }
    for(int i = 0; i < n; ++i){
        std::cin >> prices[i];
    }
    std::vector<std::vector<int>> dp(w+1, std::vector<int>(n+1, 0));
    for(int i = 1; i <= w; ++i){
        for(int j = 1; j <= n; ++j){
            if(weights[j-1] <= i){
                dp[i][j] = std::max(dp[i][j-1],
                                    dp[i-weights[j-1]][j-1] + prices[j-1]);
            } else {
                dp[i][j] = dp[i][j-1];
            }

        }
    }
    for(auto vec : dp){
        for(auto i : vec){
            printf("%i  ", i);
        }
        printf("\n");
    }
    std::cout << dp[w][n];
    return 0;
}