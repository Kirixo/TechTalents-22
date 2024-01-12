//
// Created by Kirixo on 05/12/2023.
//
#include <bits/stdc++.h>

int main(){
    int t;
    for(std::cin >> t; t--;) {
        std::string s;
        std::cin >> s;
        std::string res = "";
        std::stack<int> big, small;
        for (auto it : s) {
            if(it == 'b') {
                if(!small.empty()) {
                    res[small.top()] = '0';
                    small.pop();
                }
                continue;
            }
            if(it == 'B') {
                if(!big.empty()) {
                    res[big.top()] = '0';
                    big.pop();
                }
                continue;
            }
            if(it >= 'a' && it <= 'z') {
                res += it;
                small.push(res.size()-1);
                continue;
            }
            if(it >= 'A' && it <= 'Z') {
                res += it;
                big.push(res.size()-1);
                continue;
            }
        }
        for (auto it : res) {
            if(it != '0') {
                std::cout << it;
            }
        }
        std::cout << '\n';
    }
    return 0;
}