//
// Created by Kirixo on 11/12/2023.
//
#include <bits/stdc++.h>

std::vector<long long> answer;

void find_lis(const std::vector<long long>& a) {
    long long n = a.size();
    std::vector<long long> d(n+1, LONG_LONG_MAX);
    d[0] = -LONG_LONG_MAX;
    std::vector<long long>  pos(n+1, 0);
    pos[0] = -1;
    std::vector<long long> prev(n, 0);
    long long length = 0;

    for(long long i = 0; i < n; ++i) {
        long long j = (std::lower_bound(d.begin(), d.end(), a[i])-d.begin());
        if(d[j-1] <= a[i] && a[i] <= d[j]) {
            d[j] = a[i];
            pos[j] = i;
            prev[i] = pos[j-1];
            length = std::max(length, j);
        }
    }

    long long p = pos[length];
    while(p != -1) {
        answer.push_back(n-p);
        p = prev[p];
    }
}

int main() {
    long long n;
    std::cin >> n;
    std::vector<long long> a(n);
    for(long long i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::reverse(a.begin(), a.end());
    find_lis(a);
    printf("%llu\n", answer.size());
    for(long long i = 0; i < answer.size(); ++i) {
        printf("%lld", answer[i]);
        if(i != answer.size()-1) {
            printf("\n");
        }
    }
    return 0;
}