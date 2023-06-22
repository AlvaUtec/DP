    //https://codeforces.com/contest/837/problem/D
     
    #include <bits/stdc++.h>
    using namespace std;
     
    typedef long long ll;
    typedef long double ld;
     
    #define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL)
    #define rep(i,a,b) for(ll i=a;i<b;i++)
     
    const int MAXN = 201;
    const int mod = 1e9+7;
     
    ll DP[MAXN][MAXN][MAXN] = {INT32_MAX}, pw2[MAXN], pw5[MAXN], arr[MAXN] = {0};
    ll n,k;
     
    void dp(){
        // Base cases
        rep(i,0,n+1) 
            rep(j,0,k+1)
                rep(l,0,k+1) 
                    if (i == 0 || j == 0 || l == 0) 
                        DP[i][j][l] = 0;
     
        rep(i,0,n+1) 
            rep(j,0,k+1)
                rep(l,0,k+1){
                    DP[i + 1][j + 1][l + pw5[i]] = max(DP[i + 1][j + 1][l + pw5[i]], DP[i][j][l] + pw2[i]);
                    DP[i + 1][j][l] = max(DP[i + 1][j][l], DP[i][j][l]);
                }
    }
     
    void solve(){ 
        cin>>n>>k;
        for(ll i=0;i<n;i++)
            cin>>arr[i];
     
        for(ll i=0;i<n;i++){
            ll temp = arr[i];
            while(temp%2==0)
                pw2[i]++, temp/=2;
            temp = arr[i];
            while(temp%5==0)
                pw5[i]++, temp/=5;
        }
     
        dp();
     
        ll ans = 0;
        rep(i,0,n+1)
            ans = max(ans, min(i, DP[n][k][i]));
     
        cout<<ans<<"\n";
    }
     
    int main(){
        FASTIO;
        int t=1;
        // cin >> t;
        while(t--)
            solve();
    }