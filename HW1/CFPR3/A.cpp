//
// Created by Kirixo on 23/12/2023.
//
#include <bits/stdc++.h>

int main() {
    int t;
    for(std::cin >> t; t--;) {
        int n;
        std::cin >> n;
        bool u = 0, r = 0, d = 0, l = 0;
        for(int i = 0; i < n; ++i) {
            int x, y;
            std::cin >> x >> y;
            if(x > 0) {
                r = 1;
            } else if (x < 0) {
                l = 1;
            }
            if(y > 0) {
                u = 1;
            } else if(y < 0) {
                d = 1;
            }
        }
        if(u+d+l+r > 3) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}