#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<int> seq;
    
    for(int i = 0; i < (int)dungeons.size(); ++i){
        seq.push_back(i);
    }
    
    int cnt, cur_tired, maxi = 0;
    do{
        cnt = 0, cur_tired = k;
        
        for(int i : seq){
            if(dungeons[i][0] > cur_tired) break;
            cur_tired -= dungeons[i][1];
            cnt++;
        }
        
        maxi = max(maxi, cnt); 
        
    } while(next_permutation(seq.begin(), seq.end()));
    
    
    return maxi;
}