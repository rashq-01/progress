#include<iostream>
#include<vector>

using namespace std;

    void generate(int zero,int one,vector<vector<int>>& binaryArr,int countOne,int countZero,vector<int>& curr){
        if(curr.size()==(zero+one) && countOne==one && countZero==zero){
            binaryArr.push_back(curr);
            return;
        }
        if(curr.size()==(zero+one))return;

        curr.push_back(0);
        generate(zero,one,binaryArr,countOne,countZero+1,curr);
        curr.pop_back();
        curr.push_back(1);
        generate(zero,one,binaryArr,countOne+1,countZero,curr);
        curr.pop_back();
    }

    bool isValid(vector<int> arr,int limit){
        int totalOne = 0;
        int totalZero = 0;
        int i;
        for(i=0;i<arr.size() && i<=limit;i++){
            if(arr[i]==1)totalOne++;
            if(arr[i]==0)totalZero++;
        }
        if(totalOne==0 || totalZero==0)return false;

        while(i<arr.size()){
            if(arr[i]==0){
                totalZero++;
            }
            else{
                totalOne++;
            }

            if(arr[i-limit-1]==0){
                totalZero--;
            }
            else{
                totalOne--;
            }

            if(totalZero==0 || totalOne==0)return false;

            i++;
        }

        return true;
    }


    int numberOfStableArrays(int zero, int one, int limit) {
        int count = 0;
        vector<vector<int>> binaryArr;
        vector<int> curr;
        generate(zero,one,binaryArr,0,0,curr);
        vector<bool> ans(binaryArr.size(),false);
        for(int i=0;i<binaryArr.size();i++){
            if(isValid(binaryArr[i],limit))ans[i]=true;
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i])count++;
        }

        return count;
    }


    int main(){
        int limit = 59;
        int zero = 14;
        int one = 13;

        cout<<numberOfStableArrays(zero,one,limit);

        return 0;
    }