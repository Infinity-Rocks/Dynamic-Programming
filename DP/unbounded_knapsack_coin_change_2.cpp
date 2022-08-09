#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<vector<int>> &t, vector<int> coins, int amount){
    for(int i = 2; i < t.size(); i++){
        for(int j = 1; j < t[0].size(); j++){
            if(coins[i - 1] <= j){
                t[i][j] = min(t[i][j - coins[i - 1]] + 1, t[i - 1][j]);
            }
            else{
                t[i][j] = t[i - 1][j];
            }
        }
    }
    
    return t[coins.size()][amount];
}

int main(){
    vector<int>coins;
    int length, val, amount;
    
    cin >> length;
    
    for(int i = 0; i < length; i++){
        cin >> val;
        coins.push_back(val);
    }
    
    cin >> amount;
    
    vector<vector<int>> t(length + 1, vector<int>(amount + 1));
    
    for(int i = 0; i < amount + 1; i++){
        t[0][i] = INT_MAX - 1;
    }
    
    for(int i = 0; i < length + 1; i++){
        t[i][0] = 0;
    }
    
    for(int i = 1; i < amount + 1; i++){
        if(i % coins[0] == 0){
            t[1][i] = i / coins[0];
        }
        else{
            t[1][i] = INT_MAX - 1;
        }
    }
    
    return coinChange(t, coins, amount);
}