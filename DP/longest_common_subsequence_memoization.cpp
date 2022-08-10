#include <bits/stdc++.h>
using namespace std;

int LCS(vector<vector<int>> &t, string x, string y, int n, int m){
    if(n == 0 || m == 0){
        return 0;
    }
    
    if(t[n][m] != -1){
        return t[n][m];
    }
    
    if(x[n - 1] == y[m - 1]){
        return t[n][m] = 1 + LCS(t, x, y, n - 1, m - 1);
    }
    else{
        return t[n][m] = max(LCS(t, x, y, n - 1, m), LCS(t, x, y, n, m - 1));
    }
}

int main(){
    string x, y;
    int n, m;
    cin >> x;
    cin >> y;
    
    n = x.length();
    m = y.length();

    vector<vector<int>> t(n + 1, vector<int>(m + 1, -1));

    LCS(t, x, y, n, m);
    
    cout << t[n][m];
}