#include <bits/stdc++.h>
using namespace std;
constexpr size_t MAX_N = 1e7;
bool sieve[MAX_N];
vector<char> v;
vector<int> nums;

int solution(string numbers){
    fill(sieve, sieve + MAX_N, true);
    
    // 1. sieve
    sieve[0] = sieve[1] = false;
    for(int i = 2; i * i <= MAX_N; ++i){
        if(!sieve[i]) continue;
        
        for(int j = i * i; j <= MAX_N; j += i){
            sieve[j] = false;
        }
    }
    
    // 2. permutation
    for(char num : numbers){
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    do{
        string tmp = "";
        for(int i = 0; i < v.size(); ++i){
            tmp.push_back(v[i]);
            nums.push_back(stoi(tmp));
        }
    } while(next_permutation(v.begin(), v.end()));

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    int rst = 0;
    for(int tar : nums){

        cout << tar << ' ';
        if(sieve[tar]) rst++;
    }

    return rst;
}
 