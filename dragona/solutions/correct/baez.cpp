#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,h;
    cin >> n >> h;
    vector< vector<int> > asc(h+1);
    for (int i=0;i<n;i++){
        int ai,bi;
        cin>>ai>>bi;
        asc[ai].push_back(bi);
    }
    vector<int> dp(h+1);
    dp[h] = 0;
    for (int i=h-1;i>=1;i--){
        dp[i] = dp[i+1] + 1;
        for (int j=0;j<asc[i].size();j++){
            dp[i] = min(dp[i],dp[asc[i][j]]);
        }
    }
    cout<<dp[1]<<'\n';
    return 0;
}