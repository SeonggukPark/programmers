#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int x = ((brown + 4) + sqrt(pow(brown + 4, 2) - 16 * (brown + yellow)))/4;
    cout << x;
    
    
    return {x, (brown + 4) / 2 - x};
}