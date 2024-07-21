#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void run(){
    int n, m;
    cin >> m >> n;
    vector<bool> v(n + 1, true);
    v[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if(!v[i]) continue;

        for(int j = i; i * j <= n; ++j){
            v[i * j] = false;
        }
    }

    for(int i = m; i <= n; i++){
        if(v[i]) cout << i << endl;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    run();
    return 0;
}