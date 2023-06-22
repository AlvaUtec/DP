#include <bits/stdc++.h>
     
using namespace std;
    
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long

ll dp[2005][2005];

struct item
{
    ll val,cnt;
    friend bool operator < (item x,item y)
    {
        return x.val > y.val;
    }
};
int main(){
    FASTIO;
    ll m,n;
    cin >> m >> n;
    vector < vector < item > > vt(m+1);
    for (ll i=1;i<=n;i++){
        ll v,w,t;
        cin >> v >> w >> t;
        vt[w].push_back({v,t});
    }
    ll i=0;
    for (ll w=1;w<=m;w++){
        i++;
        sort(vt[w].begin(),vt[w].end());
        ll cw=0,cv=0;
        for (ll j=1;j<=m;j++)
            dp[i][j]=dp[i-1][j];
        
        for (auto f:vt[w]){
            if (cw>m) break;
            for (ll k=1;k<=f.cnt;k++){
                cw+=w;
                cv+=f.val;
                if (cw>m) break;
                for (ll j=cw;j<=m;j++)
                    dp[i][j]=max(dp[i][j],dp[i-1][j-cw]+cv);
            }
        }
    }
    ll ans=0;
    for (ll j=1;j<=m;j++) ans=max(ans,dp[i][j]);
    cout << ans;
    return 0;
}