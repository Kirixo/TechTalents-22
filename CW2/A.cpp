//
// Created by Kirixo on 06/01/2024.
//
#include <iostream>
#include <vector>
#include <cstdint>

struct node {
    int prev;
    int top;
    int sum;
    node() = default;
    node(int _prev, int _top, int _sum): prev(_prev), top(_top), sum(_sum) {}
};

int main() {
    int n;
    std::cin >> n;
    std::vector<node> v;
    v.reserve(n+1);
    v.emplace_back(-1, 0, 0);
    uint64_t sum = 0;
    for (int i = 1; i <= n; ++i) {
        int t, m;
        std::cin >> t >> m;
        if (m == 0) {
            v.push_back(v[v[t].prev]);
        } else {
            v.emplace_back(t, m, v[t].sum+m);
        }
        sum += v[i].sum;
    }
    std::cout << sum;
    return 0;
}
