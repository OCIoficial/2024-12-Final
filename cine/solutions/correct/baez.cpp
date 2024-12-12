#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector< vector<int> > a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    vector< vector<int> > dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i][j] = a[i][j];
            if (i) dp[i][j] += dp[i-1][j];
            if (j) dp[i][j] += dp[i][j-1];
            if (i && j) dp[i][j] -= dp[i-1][j-1];
        }
    }
    int ans = max(n,m);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (a[i][j] == 1) continue;
            int l=1,r=max(n,m);
            while (l != r){
                int mid = (l+r)/2;
                int ir = min(i+mid,n-1);
                int jr = min(j+mid,m-1);
                int il = max(0,i-mid);
                int jl = max(0,j-mid);
                int sum = dp[ir][jr];
                if (il) sum -= dp[il-1][jr];
                if (jl) sum -= dp[ir][jl-1];
                if (il && jl) sum += dp[il-1][jl-1];
                //cout<<i<<' '<<j<<' '<<mid<<' '<<(ir-il+1)*(jr-jl+1) - sum<<endl;
                if ( (ir-il+1)*(jr-jl+1) - sum >= k+1 ) r=mid;
                else l=mid+1;
            }
            //cout<<i<<' '<<j<<' '<<l<<'\n';
            ans = min(ans,l);
        }
    }
    cout<<ans<<'\n';
    return 0;
}