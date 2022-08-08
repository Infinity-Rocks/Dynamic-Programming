#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int maxWeight, int length){
    
    if(length == 0 || maxWeight == 0){
        return 0;
    }
    
    if(weight[length - 1] <= maxWeight){
        return max(
                value[length - 1] + knapsack(weight, value, (maxWeight - weight[length - 1]), length - 1),
                knapsack(weight, value, maxWeight, length - 1)
            );
    }
    
    else{
        return knapsack(weight, value, maxWeight, length - 1);
    }
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
    
    return knapsack(weight, value, maxWeight, length);
}
