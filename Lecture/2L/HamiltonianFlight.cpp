#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
const int mod = 1e9+7;

vector<int> adj[21];
ll dp[1<<20][21]; //amount of ways in subset S that ends in node i


int main(){
    FASTIO;

    int n,m;
    cin>>n>>m;

    for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[b].push_back(a);
	}

	dp[1][1] = 1; // base case

	for(int s = 2; s < (1<<n); s++) { // loop through each subset starting from 2

		if((s & (1 << (n-1))) && s != ((1<<n) - 1))
            continue;

		for(int d = 1; d <= n; d++) { // loop through each node

			if((s & (1 << (d-1))) == 0) // if d is not in the mask
                continue;

			for(int v : adj[d]) { // loop through each node adjacent to d

				if(s & (1<<(v-1))) { // if v is in the mask

					dp[s][d] += dp[s-(1<<(d-1))][v]; // add the amount of ways to get to v from s without d
					dp[s][d] %= mod; 
				}
			}
		}
	}

	cout << dp[(1<<n)-1][n] % mod; // print the amount of ways to get to n from all subsets

    return 0;
}



// for (int i=0;i<(1<<n);i++){
//         //process each subset
//     }

//     /*
    

//     total[s][d] = total[s][d-1]; //Best price on day d

//     if(s&(1<<x)) // x in subset s

//     total[s^(1<<x)][d-1] // Best total forn any subset without x, d-1 means on any day before d

//     price[x][d] // Price of x on day d

//     total[s][d] = min(total[s][d], total[s^(1<<x)][d-1]+price[x][d]);

//     */

//    for(int d = 1; d < n; d++) {
//         for(int s = 0; s < (1<<k); s++) {
//             total[s][d] = total[s][d-1];
//             for(int x = 0; x < k; x++) 
//                 if(s&(1<<x)) 
//                     total[s][d] = min(total[s][d], total[s^(1<<x)][d-1]+price[x][d]);    
//         }
//     }