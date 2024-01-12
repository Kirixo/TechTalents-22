//
// Created by Kirixo on 05/12/2023.
//
#include <bits/stdc++.h>


int main () {
    int t;
    for (std::cin >> t; t--;){
        std::string s;
        std::cin >> s;
        char l = s[0];
        int n = int(s[1]) - 48;
        for(int i = 1; i < n; ++i) {
            std::cout << l << i << '\n';
        }
        for(int i = n+1; i <= 8; ++i) {
            std::cout << l << i << '\n';
        }

        for(char i = 'a'; i < l; ++i) {
            std::cout << i << n << '\n';
        }
        for(char i = l+1; i <= 'h'; ++i) {
            std::cout << i << n << '\n';
        }
    }

    return 0;
}