#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(vector<vector<int>> &t, vector<int> weight, vector<int> value, int maxWeight){
    for(int i = 1; i < t.size(); i++){
        for(int j = 1; j < t[0].size(); j++){
            if(weight[i - 1] <= j){
                t[i][j] = max((value[i - 1] + t[i][j - weight[i - 1]]),
                                t[i - 1][j]);
            }
            else{
                t[i][j] = t[i - 1][j];
            }
        }
    }
    
    return t[weight.size()][maxWeight];
}

int main(){
    vector<int> weight;
    vector<int> value;
    int maxWeight;
    int val;
    int length;
    
    cin >> length;
    
    for(int i = 0; i < length; i++){
        cin >> val;
        weight.push_back(val);
    }
    
    for(int i = 0; i < length; i++){
        cin >> val;
        value.push_back(val);
    }
    
    cin >> maxWeight;
    
    vector<vector<int>> t(length + 1, vector<int>(maxWeight + 1));
    
    for(int i = 0; i < maxWeight + 1; i++){
        t[0][i] = 0;
    }
    
    for(int i = 0; i < length + 1; i++){
        t[i][0] = 0;
    }
    
    return unboundedKnapsack(t, weight, value, maxWeight);
}