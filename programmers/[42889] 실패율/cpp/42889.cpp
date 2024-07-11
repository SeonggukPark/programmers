#include <bits/stdc++.h>
using namespace std;

struct datum{
    int node;
    float rate;
};

bool cmp(const datum & a, const datum & b){
    if(a.rate != b.rate) return a.rate > b.rate;
    return a.node < b.node;
}

vector<datum> v;

vector<int> solution(int N, vector<int> stages) {
    sort(stages.begin(), stages.end());
    
    int prev = 0, next = 0, size = stages.size();
    
    for(int i = 1; i <= N; ++i){
        int cnt = 0;
        prev = next;
        
        while(stages[next] == i){
            cnt++;
            next++;
        }
        
        cout << i << ' ' << cnt << ' ' << size - prev << ' ' << (float)(cnt)/(size - prev) << endl;
        
        if(cnt == 0) v.push_back({i, 0});
        else v.push_back({i, (float)(cnt)/(size - prev)});
    }
    
    sort(v.begin(), v.end(), cmp);

    vector<int> answer;
    
    for(auto i : v){
        cout << i.node << ' ' << i.rate << endl;
        answer.push_back(i.node);
    }
    
    return answer;
}