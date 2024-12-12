// @ocimatic should-fail=[st2,st4]
#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > asc;
vector<int> imp;
int n,h;
int solve(int ci){
    if (imp[ci] == h) return 0;
    int ans = imp[ci+1] - imp[ci] + solve(ci+1);
    for (int i=0;i<asc[imp[ci]].size();i++){
        int find_bi = ci+1;
        while (imp[find_bi] < asc[imp[ci]][i]) find_bi++;
        ans = min(ans,solve(find_bi));
    }
    return ans;
}

int main(){
    cin >> n >> h;
    imp.push_back(1);
    imp.push_back(h);
    asc.resize(h+1);
    for (int i=0;i<n;i++){
        int ai,bi;
        cin>>ai>>bi;
        asc[ai].push_back(bi);
        imp.push_back(ai);
        imp.push_back(bi);
    }
    sort(imp.begin(),imp.end());
    imp.resize(unique(imp.begin(),imp.end())-imp.begin());
    cout<<solve(0)<<'\n';
    return 0;
}