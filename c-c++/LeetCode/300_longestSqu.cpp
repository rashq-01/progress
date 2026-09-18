#include<bits/stdc++.h>

using namespace std;



int solve(vector<int> &nums,int prev,int curr){
    if(curr == nums.size()) return 0;

    int notTake = solve(nums,prev,curr+1);

    int take = 0;
    
    if(prev==-1 || (nums[curr]>nums[prev])){
        take = 1 + solve(nums,curr,curr+1);
    }

    return ((take>=notTake)?take:notTake);
}

int main(){
    vector<int> nums = {0,1,0,3,2,3};
    int n = nums.size();

    cout<<solve(nums,-1,0);


    return 0;
}