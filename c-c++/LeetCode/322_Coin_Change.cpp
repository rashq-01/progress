#include<iostream>
#include <vector>
#include <climits>
using namespace std;

// int coinChange(vector<int>&nums,int target){
//     //Base case
//     if(target==0)return 0;
//     if(target<0)return INT_MAX;

//     int mini = INT_MAX;

//     for(int i=0;i<nums.size();i++){
//         int ans = coinChange(nums,target-nums[i]);
//         if(ans != INT_MAX) mini = min(mini,1+ans);
//     }
//     return mini == INT_MAX ? -1 : mini;

// }
int coinChangeMem(vector<int>&nums,int target,vector<int>& dp){
    //Base case
    if(target==0)return 0;
    if(target<0)return INT_MAX;
    if(dp[target] != -2)return dp[target];

    int mini = INT_MAX;

    for(int i=0;i<nums.size();i++){
        int ans = coinChangeMem(nums,target-nums[i],dp);
        if(ans != INT_MAX) mini = min(mini,1+ans);
    }
    dp[target] = mini==INT_MAX?-1:mini;
    return dp[target];

}

int main(){
    
    vector<vector<int>> testCoins = {
    {1, 2, 5},       // case 1
    {2},             // case 2
    {1},             // case 3
    {5, 10, 25},     // case 4
    {2, 3, 7},       // case 5
    {1, 3, 4},       // case 6
    // {1, 2, 5},       // case 7 (large amount)
    {5, 2, 2, 1},    // case 8
    // {},              // case 9 (empty coins)
    // {186, 419, 83, 408}, // case 10
    {2, 5, 7}        // case 11 (amount = 0)
    };
    vector<int> testAmounts = {
        11,   // case 1
        3,    // case 2
        0,    // case 3
        3,    // case 4
        7,    // case 5
        6,    // case 6
        // 1000, // case 7
        11,   // case 8
        // 5,    // case 9
        // 6249, // case 10
        0     // case 11
    };
    vector<int> expectedAnswers = {
        3,   // case 1 -> 5 + 5 + 1
        -1,   // case 2 -> impossible
        0,   // case 3 -> amount=0
        -1,   // case 4 -> impossible (all coins too large)
        1,   // case 5 -> 7
        2,   // case 6 -> 3 + 3
        // 200,   // case 7 -> many 5’s, min coins is 200
        3,   // case 8 -> 5 + 5 + 1
        // -1,   // case 9 -> impossible (no coins)
        // 20,   // case 10 -> known tricky case
        0    // case 11 -> amount=0
    };
    for (int i = 0; i < testCoins.size(); i++) {
        vector<int> dp(testAmounts[i]+1,-2);
        int result = coinChangeMem(testCoins[i], testAmounts[i],dp);
        cout << "Case " << i+1 
            << ": got " << result 
            << ", expected " << expectedAnswers[i] 
            << (result == expectedAnswers[i] ? " ✅" : " ❌") 
            << endl;
    }



    return 0;
}