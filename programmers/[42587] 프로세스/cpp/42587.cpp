#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    multiset<int, greater<>> s;
    queue<pii> q;

    int idx = 0;
    for(int data : priorities){
        s.insert(data);
        q.push({data, idx++});
    }


    int cnt = 0;
    while(!q.empty()){
        pii top = q.front();
        q.pop();

        if(*s.begin() == top.x){
            s.erase(s.begin());
            cnt++;

            if(top.y == location) return cnt;
        }

        else{
            q.push(top);
        }
    }

    return answer;
}
