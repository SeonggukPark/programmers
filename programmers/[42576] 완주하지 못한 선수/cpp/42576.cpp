#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> um;
    for(string part : participant){
        if(um.find(part) == um.end()) um[part] = 0;
        um[part]++;
    }    
    for(string comp : completion){
        um[comp]--;
        if(um[comp] == 0) um.erase(comp);
    }
    
    for(auto rst : um) return rst.first;
}