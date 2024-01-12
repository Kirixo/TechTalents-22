//
// Created by Kirixo on 05/12/2023.
//
#include <bits/stdc++.h>

int main() {
    int t;
    for(std::cin >> t; t--; ) {
        int n;
        std::string s;
        std::cin >> n;
        std::string ss;
        std::cin >> ss;
        s += ss;
        std::map<char, int> counter;
        for(int i = 0; i < n; ++i) {
            if(counter[s[i]]) {
                counter[s[i]]++;
            } else {
                counter[s[i]] = 1;
            }
        }
        while(1) {
            int max = 0;
            int index = -1;
            for(int i = 1; i < s.size(); ++i) {
                if(s[i] != s[i-1]) {
                    if(counter[s[i]] + counter[s[i-1]] > max) {
                        max = counter[s[i]] + counter[s[i-1]];
                        index = i;
                    }
                }
            }
            if(index == -1) {
                break;
            } else {
                counter[s[index]]--;
                counter[s[index-1]]--;
                s.erase(index-1, 2);
            }
        }
        std::cout << int(s.size()) << '\n';
    }
    return 0;
}