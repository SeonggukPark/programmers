#include <string>
#include <vector>

using namespace std;

int balance_idx(string p){
    int cnt = 0;
    
    for(int i = 0; i < p.length(); i++){
        if(p[i] == '(') cnt++;
        else cnt--;
        
        if(cnt == 0) return i;
    }
    
    return -1;
}

bool is_proper(string p){
    int cnt = 0;
    for(int i = 0; i < p.length(); i++){
        if(p[i] == '(') cnt++;
        else{
            if(cnt == 0) return false; // 쌍 안맞으면 false 리턴
            
            cnt--;
        }
    }
    return true;
}

string solution(string p) {
    string answer = "";
    if (p == "") return answer;
    int idx = balance_idx(p);
    string u = p.substr(0, idx + 1);
    string v = p.substr(idx + 1);
    
    if (is_proper(u)) answer = u + solution(v);
    
    else{
        answer = "(";
        answer += solution(v);
        answer += ")";
        
        u = u.substr(1, u.size() - 2);
        
        for (int i = 0; i < u.size(); i++) {
            if (u[i] == '(') u[i] = ')';
            else u[i] = '(';
        }
        answer += u;   
    }
    
    return answer;
}