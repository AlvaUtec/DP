//https://codeforces.com/problemset/problem/1418/C

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;

const int MAXN = 1e6+6;
const int mod = 1e9+7;

void solve(){
    int n, skips;
    cin>>n>>skips;
    int ones=0;
    for(int i=1;i<n;i++){
        int temp;
        cin>>temp;
        ones+=temp;
        if(temp == 0) skips+=ones/3, ones=0;
    }

    cout<<skips+ones/3<<"\n";

}

int main(){
    FASTIO;
    int t=1;
    cin >> t;
    while(t--)
        solve();
}