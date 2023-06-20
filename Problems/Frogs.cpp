// https://atcoder.jp/contests/dp/tasks/dp_a

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;

const int MAXN = 1e5+5;

int DP[MAXN] = {0};
int h[MAXN] = {0};
bool vis[MAXN] = {0};

int dp(int n){
    if(n==0)
        return 0;
    if(n==1)
        return abs(h[1]-h[0]);

    if(vis[n])
        return DP[n];
    
    vis[n] = 1;

    return DP[n] = min(dp(n-1)+abs(h[n]-h[n-1]), dp(n-2)+abs(h[n]-h[n-2]));
}

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>h[i];

    cout<<dp(n-1)<<"\n";
    
}

int main(){
    FASTIO;
    int t=1;
    // cin >> t;
    while(t--)
        solve();
    
    return 0;
}
