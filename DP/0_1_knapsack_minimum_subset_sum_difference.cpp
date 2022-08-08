#include <bits/stdc++.h>
using namespace std;

void subsetSum(vector<vector<bool>> &t, vector<int> array, int sum){
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
}

int main(){
    vector<int> array;
    vector<int> matrix;
    int sum = 0, length, val, mn = INT_MAX;
    
    cin >> length;
    
    for(int i = 0; i < length; i++){
        cin >> val;
        array.push_back(val);
        sum += val;
    }
    
    vector<vector<bool>> t(length + 1, vector<bool>(sum + 1));
    
    for(int i = 0; i < sum + 1; i++){
        t[0][i] = false;
    }
    
    for(int i = 0; i < length + 1; i++){
        t[i][0] = true;
    }

    subsetSum(t, array, sum);
    
    for(int i = 1; i < (sum + 1) / 2; i++){
        if(t[array.size()][i] == true){
            matrix.push_back(i);
        }
    }

    for(int i = 0; i < matrix.size(); i++){
        mn = min(mn, sum - 2 * matrix[i]);
    }

    return mn;
}