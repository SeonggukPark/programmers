#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for(int tar : scoville){
        pq.push(tar);
    }
    
    int new_food;
    
    while(pq.size() >= 2 && pq.top() < K){
        answer++;
        new_food = 0;
        new_food += pq.top(); pq.pop();
        new_food += 2 * pq.top(); pq.pop();
        pq.push(new_food);
    }
    
    if(pq.size() >= 2 || (pq.size() == 1 && pq.top() >= K)) return answer;
    return -1;
}