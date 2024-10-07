#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int acc = 0, idx = 0, out_cnt = 0, time = 0;
    queue<int> q;
    
    while(true){
        time++;
        
        if(acc + truck_weights[idx] <= weight) {
            acc += truck_weights[idx];
            q.push(truck_weights[idx++]);
        }
        
        else q.push(0);
        
        if(q.size() == bridge_length){
            if(q.front() != 0) out_cnt++;
            acc -= q.front();
            q.pop();
        }
        
        if(out_cnt == (int)truck_weights.size()) return time + 1;
    }
}