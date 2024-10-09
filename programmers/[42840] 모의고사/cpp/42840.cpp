#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> answers) {
    int pat_1[5] = {1, 2, 3, 4, 5};
    int pat_2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int pat_3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int score[3] = {0, 0, 0};
    int idx = 0;
    
    for(int answer : answers){
        if(pat_1[idx % 5] == answer) score[0]++;
        if(pat_2[idx % 8] == answer) score[1]++;
        if(pat_3[idx % 10] == answer) score[2]++;
        idx++;
    }
    
    vector<int> rst;
    int max = -1;
    for(int i = 0; i < 3; ++i){       
        if(score[i] == max) rst.push_back(i + 1);
        if(score[i] > max){
            max = score[i];
            rst.clear();
            rst.push_back(i + 1);
        }
    }
    
    
    return rst;
}