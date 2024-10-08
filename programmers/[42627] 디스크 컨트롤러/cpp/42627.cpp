#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

struct wait_cmp{
    bool operator()(const pii & a, const pii & b){
        if(a.x != b.x) return a.x > b.x;
        return a.y > b.y;
    }
};

struct cmp{
    bool operator()(const pii & a, const pii & b){
        if(a.y != b.y) return a.y > b.y;
        return a.x > b.x;
    }
};

priority_queue<pii, vector<pii>, wait_cmp> wait_q;
priority_queue<pii, vector<pii>, cmp> going_q;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    for(auto job : jobs){
        wait_q.push({job[0], job[1]});
    }
    
    going_q.push(wait_q.top()); wait_q.pop();
    int cur_time = going_q.top().x;
    
    while(!going_q.empty()){
        auto top = going_q.top(); going_q.pop();
        cur_time += top.y;

        while(!wait_q.empty() && wait_q.top().x <= cur_time){
            going_q.push(wait_q.top()); wait_q.pop();
        }
        
        // cout << cur_time << endl;
        answer += (cur_time - top.x);
        
        if(going_q.empty() && !wait_q.empty()){
            cur_time = wait_q.top().x;
            going_q.push(wait_q.top()); wait_q.pop();
        }
    }
    
    answer /= (int)jobs.size();
    return answer;
}