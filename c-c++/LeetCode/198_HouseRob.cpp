#include<iostream>
#include<vector>
using namespace std;

int robb(vector<int>&nums,int n){
    if(n==0){
        return nums[0];
    }
    if(n<0)return 0;

    return max(,robb(nums,n-2));
}

int main(){



    return 0;
}