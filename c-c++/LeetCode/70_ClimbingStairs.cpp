#include<iostream>
#include<vector>
using namespace std;

// int ans(int n){
//     if(n==0)return 1;
//     if(n<0) return 0;

//     return ans(n-1)+ans(n-2);
// }

int ans(int n,vector<int>&dp){
        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        if(dp[n]) return dp[n];

        dp[n] = ans(n-1,dp)+ans(n-2,dp);
        return dp[n];


    }

int main(){
    int n=5
    ;
    vector<int> dp(n+1,0);
    cout<<ans(n,dp);
    return 0;
}