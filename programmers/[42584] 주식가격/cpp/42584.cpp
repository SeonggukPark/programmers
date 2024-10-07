#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int size = (int)prices.size();
    answer.resize(size);
    
    stack<pii> stk;
    int idx = 0;
    
    for(int price : prices){
        while(!stk.empty() && stk.top().x > price){
            answer[stk.top().y] = idx - stk.top().y;
            stk.pop();
        }
        
        stk.push({price, idx});
        idx++;
    }
    
    while(!stk.empty()){
        answer[stk.top().y] = idx - stk.top().y - 1;
        stk.pop();
    }
    
    
    return answer;
}