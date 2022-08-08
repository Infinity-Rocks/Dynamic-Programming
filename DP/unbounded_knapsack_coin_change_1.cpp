#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<vector<int>> &t, vector<int> coins, int sum){
    for(int i = 1; i < t.size(); i++){
        for(int j = 1; j < t[0].size(); j++){
            if(coins[i - 1] <= j){
                t[i][j] = t[i][j - coins[i - 1]] + t[i - 1][j];
            }
            else{
                t[i][j] = t[i - 1][j];
            }
        }
    }
    
    return t[coins.size()][sum];
}

int main(){
    vector<int> coins;
    int length, val, sum;
    
    cin >> length;
    
    for(int i = 0; i < length; i++){
        cin >> val;
        coins.push_back(val);
    }
    
    cin >> sum;
    
    vector<vector<int>> t(length + 1, vector<int>(sum + 1));
    
    for(int i = 0; i < sum + 1; i++){
        t[0][i] = 0;
    }
    
    for(int i = 0; i < length + 1; i++){
        t[i][0] = 1;
    }
    
    return coinChange(t, coins, sum);
}