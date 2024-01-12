//
// Created by Kirixo on 06/01/2024.
//
#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> heights(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> heights[i];
    }
    std::vector<int> pref(n);
    pref[0] = heights[0];
    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i-1]+heights[i];
    }
    for (;m--;) {
        short q;
        std::cin >> q;
        int l, r;
        std::cin >> l >> r;
        --l;
        --r;
        if (q) {
            std::reverse(heights.begin()+l, heights.begin()+r+1);
            for(int i = l > 0 ? l : (pref[0] = heights[0], l+1); i < r; ++i) {
                pref[i] = pref[i-1]+heights[i];
            }
        } else {
            std::cout << ((l > 0) ? pref[r]-pref[l-1] : pref[r] ) << '\n';
        }
    }
    return 0;
}
