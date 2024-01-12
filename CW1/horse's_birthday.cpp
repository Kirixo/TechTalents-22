//
// Created by Kirixo on 09/12/2023.
//
#include <iostream>
#include <vector>
#include <cmath>

long long min_start = -INT_MAX, min_end = INT_MAX;

void func(int* a, int pos, int start, int end) {
    if(*a == -1) {
        if((end-start) < (min_end-min_start)) {
            min_end = end;
            min_start = start;
        }
        return;
    }
    if(pos < start) {
        start = pos;
    } else if(pos > end) {
        end = pos;
    }

    func(a+1, pos-(*a), start, end);
    func(a+1, pos+(*a), start, end);
}

int main() {
    int t;
    for(std::cin >> t; t--; ) {
        int n;
        std::cin >> n;
        std::vector<int> a(n+1);
        for(int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        a.push_back(-1);
        min_start = -INT_MAX, min_end = INT_MAX;

        func(&a[0], 0, 0, 0);
        std::cout << min_end-min_start << '\n';

    }

    return 0;
}