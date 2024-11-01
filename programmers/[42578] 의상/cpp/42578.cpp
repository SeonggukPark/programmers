#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

int solution(vector<vector<string>> clothes) {
    int rst = 1;
    unordered_map<string, int> um;
    
    for(auto cloth : clothes){
        if(um.find(cloth[1]) == um.end()) um[cloth[1]] = 0;
        um[cloth[1]]++;
    }
    
    for(auto cloth : um){
        rst *= cloth.y + 1;
    }
    
    return rst - 1;
}

