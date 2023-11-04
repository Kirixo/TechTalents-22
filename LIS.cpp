//
// Created by Kirixo on 04/11/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }
    std::vector<int> dp(n, 1);
    std::vector<int> prev(n);
    prev[0] = -1;
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; ++j){
            if(a[j] < a[i]){
                if(dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
    }
    int last_element_index = static_cast<int>
            (std::max_element(dp.begin(), dp.end()) - dp.begin());
    printf("%i \n", dp[last_element_index]);
    std::vector<int> res;
    res.reserve(n);
    for(int i = last_element_index; i != -1; i = prev[i]){
        res.push_back(a[i]);
    }
    std::reverse(res.begin(), res.end());
    for(int i : res){
        printf("%i ", i);
    }
    return 0;
}