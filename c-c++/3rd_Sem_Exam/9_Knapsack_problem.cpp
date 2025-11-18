/*#include<iostream>
#include<vector>

using namespace std;


int solve(vector<int> &value,vector<int> &weight,int capacity,int index){
    if(index==0){
        if(weight[index]<=capacity){
            return value[index];
        }
        else{
            return 0 ;
        }
    }
    
    int include = 0;
    if(weight[index] <= capacity){
        include = value[index] + solve(value,weight,capacity-weight[index],index-1);
    }
    int exclude = solve(value,weight,capacity,index-1);
    return max(include,exclude);

}

int main() {

    vector<int> value  = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int capacity = 50;

    int n = value.size();

    cout << "Maximum value the knapsack can hold = "
         << solve(value, weight, capacity, n - 1)
         << endl;

    return 0;
}*/




#include<iostream>
#include<vector>

using namespace std;


int solve(vector<int> &value,vector<int> &weight,int capacity,int index,vector<vector<int>> &dp){
    if(index==0){
        if(weight[index]<=capacity){
            return value[index];
        }
        else{
            return 0 ;
        }
    }
    if(dp[index][capacity] != -1)return dp[index][capacity];
    
    int include = 0;
    if(weight[index] <= capacity){
        include = value[index] + solve(value,weight,capacity-weight[index],index-1,dp);
    }
    int exclude = solve(value,weight,capacity,index-1,dp);

    dp[index][capacity] = max(include,exclude);

    return max(include,exclude);

}

int solveTab(vector<int> &value,vector<int> &weight, int capacity,int n){
    vector<vector<int>> dp(n,vector<int>(capacity+1,-1));

    for(int w=weight[0];w<=capacity;w++){
        if(weight[0]<=capacity){
            dp[0][w] = value[0];
        }
        else{
            dp[0][w] = 0;
        }
    }
}



int main() {

    vector<int> value  = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int capacity = 50;

    int n = value.size();


    vector<vector<int>> dp(n,vector<int>(capacity+1,-1));



    cout << "Maximum value the knapsack can hold = "
         << solve(value, weight, capacity, n - 1,dp)
         << endl;

    return 0;
}