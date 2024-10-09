#include <bits/stdc++.h>
#define pii pair<int, int>
constexpr int INF = 987654321;
using namespace std;

int solution(vector<vector<int>> sizes) {
    int sm = 0, lar = 0;
    for(auto size : sizes){        
        sm = max(sm, min(size[0], size[1]));
        lar = max(lar, max(size[0], size[1]));
    }
           
    return sm * lar;
}
