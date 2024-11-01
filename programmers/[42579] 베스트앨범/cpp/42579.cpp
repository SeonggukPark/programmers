#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

struct cmp{
    bool operator()(const pii & a, const pii & b){
        if(a.x != b.x) return a.x > b.x; // 재생 횟수 ascending
        return a.y < b.y; // 고유번호 descending
    }
};

bool cmp_vec(const pair<int, priority_queue<pii, vector<pii>, cmp> > & a, const pair<int, priority_queue<pii, vector<pii>, cmp> > & b){
    return a.x < b.x; // 카테고리 재생 횟수 ascending
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    int idx_cnt = 0;
    unordered_map<string, int> idx_map;
    vector<pair<int, priority_queue<pii, vector<pii>, cmp> > > vec;
    
    for(int i = 0; i < (int)genres.size(); ++i){
        auto & gen = genres[i];
        if(idx_map.find(gen) == idx_map.end()) {
            idx_map[gen] = idx_cnt++;
            vec.push_back({0, {}});
        }
        
        int cur_idx = idx_map[gen];
        vec[cur_idx].x += plays[i];
        vec[cur_idx].y.push({plays[i], i});
        if(vec[cur_idx].y.size() > 2) vec[cur_idx].y.pop();
    }
    
    sort(vec.begin(), vec.end(), cmp_vec);
    
    for(auto cur : vec){
        auto cur_pq = cur.y;
        
        while(!cur_pq.empty()){
            answer.push_back(cur_pq.top().y);
            cur_pq.pop();
        }
    }

    reverse(answer.begin(), answer.end());
    return answer;
}