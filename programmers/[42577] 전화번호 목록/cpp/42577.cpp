#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> um;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(string num : phone_book){
        for(int i = 1; i < (int)num.length(); ++i){
            if(um.find(num.substr(0, i)) != um.end()) return false;
        }
        um[num] = 0;
    }
    
    return true;
}