#include <bits/stdc++.h>
using namespace std;

vector<int> LCSConvert(vector<vector<int>> &t, string x, string y, int n, int m){
    vector<int> output;
    
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
    
    output.push_back(n - t[n][m]);
    output.push_back(m - t[n][m]);
    
    return output;
}

int main(){
    string x, y;
    int n, m;
    
    cin >> x >> y;
    
    n = x.length();
    m = y.length();
    
    vector<vector<int>> t(n + 1, vector<int>(m + 1));
    vector<int> final;
    
    for(int i = 0; i < n + 1; i++){
        t[0][i] = 0;
    }
    
    for(int i = 0; i < m + 1; i++){
        t[i][0] = 0;
    }
    
    final = LCSConvert(t, x, y, n, m);
    
    cout << "Deletion: " << final[0] << endl;
    cout << "Insertion: " << final[1] << endl;
    
    return 0;
}