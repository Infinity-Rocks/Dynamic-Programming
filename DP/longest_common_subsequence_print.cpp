#include <bits/stdc++.h>
using namespace std;

string LCS(vector<vector<int>> &t, string x, string y, int n, int m){
    for(int i = 1; i < t.size(); i++){
        for(int j = 1; j < t[0].size(); j++){
            if(x[i - 1] == y[j - 1]){
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else{
                t[i][j] = 0;
            }
        }
    }
    
    int i = n, j = m;
    string output = "";
    
    while(i > 0 && j > 0){
        if(x[i - 1] == y[j - 1]){
            output += x[i - 1];
            i--;
            j--;
        }
        else{
            t[i][j - 1] > t[i - 1][j] ? j-- : i--;
        }
    }
    
    reverse(output.begin(), output.end());
    
    return output;
}

int main(){
    string x, y;
    int n, m;
    
    cin >> x;
    cin >> y;
    
    n = x.length();
    m = y.length();
    
    vector<vector<int>> t(n + 1, vector<int>(m + 1));
    
    for(int i = 0; i < m + 1; i++){
        t[0][i] = 0;
    }
    
    for(int i = 0; i < n + 1; i++){
        t[i][0] = 0;
    }
    
    cout << LCS(t, x, y, n, m);
    
    return 0;
}