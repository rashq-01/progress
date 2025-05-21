#include<iostream>
#include<unordered_map>
using namespace std;

void twoSum(int arr[],int size,int target){
    unordered_map<int,int> m;
    for(int i=0;i<size;i++){
        m[arr[i]] = i;
    }
    for(int i=0;i<size;i++){
        int rem = target - arr[i];
        if(m.count(rem) && m[rem]!=i){
            cout<<endl<<"Index : ["<<i<<","<<m[rem]<<"]";
            return;
        }
    }
    cout<<"Index : "<<"[]";

}
int main(){
    int arr[3] = {3,2,4};
    twoSum(arr,4,6);


    return 0;
}





// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

