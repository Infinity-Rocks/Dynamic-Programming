#include <bits/stdc++.h>
using namespace std;

int LCS(string x, string y, int n, int m){
    if(n == 0 || m == 0){
        return 0;
    }
    
    if(x[n - 1] == y[n - 1]){
        return 1 + LCS(x, y, n - 1, m - 1);
    }
    else{
        return max(LCS(x, y, n, m - 1), LCS(x, y, n - 1, m));
    }
}

int main(){
    string x;
    string y;
    
    cin >> x;
    cin >> y;
    
    return LCS(x, y, x.length(), y.length());
}