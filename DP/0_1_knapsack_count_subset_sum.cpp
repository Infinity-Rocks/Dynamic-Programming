#include <bits/stdc++.h>
using namespace std;

int countSubsetSum(vector<vector<int>> &t, vector<int> array, int sum){
    for(int i = 1; i < t.size(); i++){
        for(int j = 1; j < t[0].size(); j++){
            if(array[i - 1] <= j){
                t[i][j] = t[i - 1][j - array[i - 1]] + t[i - 1][j];
            }
            else{
                t[i][j] = t[i - 1][j];
            }
        }
    }
    
    return t[array.size()][sum];
}

int main(){
    vector<int> array;
    int sum, length, val;
    
    cin >> length;
    
    for(int i = 0; i < length; i++){
        cin >> val;
        array.push_back(val);
    }
    
    cin >> sum;
    
    vector<vector<int>> t(array.size() + 1, vector<int>(sum + 1));
    
    for(int i = 0; i < sum + 1; i++){
        t[0][i] = 0;
    }
    
    for(int i = 0; i < array.size() + 1; i++){
        t[i][0] = 1;
    }
    
    int output = countSubsetSum(t, array, sum);
    
    return output;
}