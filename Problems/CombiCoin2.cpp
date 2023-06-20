// https://cses.fi/problemset/result/6312428/

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;


const int MAXN = 1e8+8;
const int mod = 1e9+7;

ll DP[MAXN] = {0};
ll coins[101] = {0};

int n,x;



void dp(){
    DP[0] = 1;
    
    for(int i=1;i<=n;i++)
        for(int w=0;w<=x;w++)
            if(w-coins[i-1]>=0)
                DP[w] += (DP[w-coins[i-1]]), DP[w]%=mod;


}

void solve(){
    cin>>n>>x;
    for(int i=0;i<n;i++)
        cin>>coins[i];

    dp();
    cout<<DP[x]<<"\n";
}

int main(){
    FASTIO;
    int t=1;
    // cin >> t;
    while(t--)
        solve();
    
    return 0;
}
