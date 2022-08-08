#include <bits/stdc++.h>
using namespace std;

int maxRodProfit(vector<vector<int>> &t, vector<int> length, vector<int> price, int size){
    for(int i = 1; i < t.size(); i++){
        for(int j = 1; j < t[0].size(); j++){
            if(length[i - 1] <= j){
                t[i][j] = max(price[i - 1] + t[i][j - length[i - 1]],
                                t[i - 1][j]);
            }
            else{
                t[i][j] = t[i - 1][j];
            }
        }
    }
    
    return t[length.size()][size];
}

int main(){
    vector<int> length;
    vector<int> price;
    int size, val, n;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> val;
        length.push_back(val);
    }
    
    for(int i = 0; i < n; i++){
        cin >> val;
        price.push_back(val);
    }
    
    cin >> size;
    
    vector<vector<int>> t(length.size() + 1, vector<int>(size + 1));
    
    for(int i = 0; i < size + 1; i++){
        t[0][i] = 0;
    }
    
    for(int i = 0; i < length.size() + 1; i++){
        t[i][0] = 0;
    }
    
    return maxRodProfit(t, length, price, size);
}