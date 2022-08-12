#include <bits/stdc++.h>
using namespace std;

int LPSConvert(vector<vector<int>> &t, string x, string y, int n, int m){
    for(int i = 1; i < t.size(); i++){
        for(int j = 1; j < t[0].size(); j++){
            if(x[i - 1] == y[j - 1]){
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else{
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    
    return (n - t[n][m]);
}

int main(){
    string x, y;
    int n, m;
    
    cin >> x;
    
    n = x.length();
    
    y = x;
    
    reverse(y.begin(), y.end());
    
    m = y.length();
    
    vector<vector<int>> t(n + 1, vector<int>(m + 1));
    
    for(int i = 0; i < m + 1; i++){
        t[0][i] = 0;
    }
    
    for(int i = 0; i < n + 1; i++){
        t[i][0] = 0;
    }
    
    cout << "Minimum Deletions: " << LPSConvert(t, x, y, n, m);
    
    return 0;
}