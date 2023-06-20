// https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;

const int MAXN = 1e5+5;

int DP[MAXN] = {0};
int h[MAXN] = {0};
bool vis[MAXN] = {0};
int k;

int dp(int n){
    if(n==0)
        return 0;
    if(n==1)
        return abs(h[1]-h[0]);

    if(vis[n])
        return DP[n];
    
    vis[n] = 1;

    int aux = INT32_MAX;

    for(int i= n-k;i<n;i++)
        if(i>=0)
            aux = min(aux, dp(i)+abs(h[n]-h[i]));
    
    return DP[n] = aux;
}

void solve(){
    int n;
    cin>>n>>k;
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
