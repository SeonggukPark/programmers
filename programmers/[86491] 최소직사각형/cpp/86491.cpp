#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

priority_queue<int> pq_big, pq_small;

int solution(vector<vector<int>> sizes) {
    for(auto size : sizes){
        if(size[0] > size[1]) pq_big.push(size[0]), pq_small.push(size[1]);
        else pq_big.push(size[1]), pq_small.push(size[0]);
    }
           
    return pq_big.top() * pq_small.top();
}
