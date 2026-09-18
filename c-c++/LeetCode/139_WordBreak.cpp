#include <bits/stdc++.h>
using namespace std;


bool help(int start,string &s,unordered_set<string>&dict,vector<int>&dp){
    if(start==s.size()) return 1;

    if(dp[start] != -1){
        return dp[start];
    }

    for(int idx = start+1;idx<=s.size();idx++){
        string prefix = s.substr(start,idx-start);

        if(dict.count(prefix)){
            if(help(idx,s,dict,dp)){
                return dp[start] = 1;
            }
        }
    }

    return dp[start] = 0;


}
int  main() {
    string s = "catsanddog";
    string wordDict[6] = {"cat","cats","sand","dog"};
    int n = s.size();
    unordered_set<string> dict;
    for(auto w:wordDict){
        dict.insert(w);
    }
    vector<int> dp(n,-1);

    return help(0,s,dict,dp);

}