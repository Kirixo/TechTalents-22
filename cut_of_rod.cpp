//
// Created by Kirixo on 03/11/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> cut(int n, const std::vector<int>& prices, std::vector<int>& splits){
    std::vector<int> results(n+1);
    splits.resize(n);
    results[0] = 0;
    for(int i = 1; i <= n; ++i){
        int res = 0;
        for(int j = 1; j <= i; ++j){
            int possible_res = std::max(res, prices[j - 1] + results[i - j]);
            if(possible_res > res){
                res = possible_res;
                splits[i-1] = j;
            }
        }
        results[i] = res;
    }
    return results;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for(int i = 0; i < n; ++i){
        std::cin >> p[i];
    }
    std::vector<int> splits;
    std::vector<int> res = std::move(cut(n, p, splits));
    printf("%i \n", res[n]);
    for(auto i : res){
        printf("%i  ", i);
    }
    printf("\n   ");
    for(auto i : splits){
        printf("%i  ", i);
    }
    return 0;
}