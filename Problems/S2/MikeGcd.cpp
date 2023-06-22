// https://codeforces.com/problemset/problem/798/C

#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;

const int mod = 1e9+7;
const int MAXN = 1e6+6;

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    ll ans=0;
    if(__gcd(a[0],a[1])!=1) ans++;

    for(int i=1;i<n;i++){
        if (__gcd(a[i],a[i-1])!=1){
            ans++;
            int temp = a[i-1];
            a[i-1]-=a[i];
            a[i] += temp;
        }
    }
    cout<<"YES\n"<<ans<<"\n";
}