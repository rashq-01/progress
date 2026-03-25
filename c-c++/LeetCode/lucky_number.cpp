#include<iostream>
#include<string>
using namespace std;

    
    int main(){
        string s = "iiii";
        int k = 1;
        string num = "";

        for(auto ch : s){
            int n = ch-'a'+1;
            num = num + to_string(n);
        }
        cout<<"String : "<<num<<endl;
        
        int i =0;
        int ans = 0;
        while(i<num.size()){
            ans += (num[i]-'0');
            i++;
        }
        k--;
        while(k && ans){
            int temp = 0;
            while(ans){
                temp += (ans%10);
                ans/=10;
            }
            ans = temp;
            k--;
        }

        cout<<"Ans : "<<ans;
        
        return 0;
    }