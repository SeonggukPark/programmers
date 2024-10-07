#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int len = (int)progresses.size();
    queue<int> q;
    vector<int> answer;
    
    for(int i = 0; i < len; ++i){
        int day = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i] != 0) day++;
        
        if(!q.empty() && q.front() < day){
            answer.push_back((int)q.size());
            q = {};
        }

        q.push(day);
    }
    
    if(!q.empty()){
        answer.push_back((int)q.size());
    }
    
    return answer;
}