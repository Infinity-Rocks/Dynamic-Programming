#include <bits/stdc++.h>
using namespace std;

bool subsetSum(vector<vector<bool>> &t, vector<int> array, int sum){
    for(int i = 1; i < t.size(); i++){
        for(int j = 1; j < t[0].size(); j++){
            if(array[i - 1] <= j){
                t[i][j] = (t[i - 1][j - array[i - 1]] || t[i - 1][j]);
            }
            else{
                t[i][j] = t[i - 1][j];
            }
        }
    }
    
    return t[array.size()][sum];
}

bool equalSumPartition(vector<int> array, int sum){
    
    for(int i = 0; i < array.size(); i++){
        sum += array[i];
    }
    
    if(sum % 2 != 0){
        return false;
    }
    
    else{
        vector<vector<bool>> t(array.size() + 1, vector<bool>(sum + 1));
    
        for(int i = 0; i < sum + 1; i++){
            t[0][i] = false;
        }
        
        for(int i = 0; i < array.size() + 1; i++){
            t[i][0] = true;
        }
    
        return subsetSum(t, array, sum / 2);
    }
}

int main(){
    vector<int> array;
    int sum, length, val;
    
    cin >> length;
    
    for(int i = 0; i < length; i++){
        cin >> val;
        array.push_back(val);
    }
    
    bool output = equalSumPartition(array, 0);
    
    if(output == true){
        return 10;
    }
    else{
        return 20;
    }
}