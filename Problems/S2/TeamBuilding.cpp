// https://codeforces.com/contest/1316/problem/E

#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;

const int mod = 1e9+7;
const int MAXN = 1e5+5;

int main(){
    ll n,p,k;
    cin>>n>>p>>k;

    vector<vector<ll>> a(n,vector<ll>(p));

    for(int i=0;i<n;i++)
        for(int j=0;j<p;j++)
            cin>>a[i][j];

    sort(a.begin(),a.end()); //sort by first element

    vector<vector<ll>> dp(n+1,vector<ll>(1<<p,0)); //max strenght choosing from first i elements and using mask j for positions

    for(int i=0;i<n;i++)
        dp[i][0] = 1;

    for(int i=1,i<n;i++){
        for(int s=0;s<(1<<p);s++){
            int remaining = i-1- __builtin_popcount(s); //(ones in mask)
            if (c<k)
                dp[i][s] = dp[i-1][s] + a[i][]
        }
    }
}
