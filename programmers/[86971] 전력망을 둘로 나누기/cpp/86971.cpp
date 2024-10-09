#include <bits/stdc++.h>
using namespace std;
constexpr size_t MAX_N = 101;
set<int> graph[MAX_N];
bool visited[MAX_N];
int N, rst;

void bfs(){
    fill(visited, visited + MAX_N, false);
    visited[1] = true;
    
    queue<int> q;
    q.push(1);
    int cnt = 1;
    
    while(!q.empty()){
        int top = q.front(); q.pop();
        
        for(int next : graph[top]){
            if(visited[next]) continue;
            visited[next] = true;
            q.push(next);
            cnt++;
        }
    }

    rst = min(rst, abs(N - 2 * cnt));
}


int solution(int n, vector<vector<int>> wires) {
    rst = n + 1, N = n;
    
    // graph 형성
    for(auto wire : wires){
        graph[wire[0]].insert(wire[1]);
        graph[wire[1]].insert(wire[0]);
    }
    
    // wires 요소 순회 하면서 가지 제거 후 덩어리 차이 구해가기
    for(auto wire : wires){
        graph[wire[0]].erase(wire[1]);
        graph[wire[1]].erase(wire[0]);
    
        bfs();
        
        graph[wire[0]].insert(wire[1]);
        graph[wire[1]].insert(wire[0]);
    }
      
    return rst;
}