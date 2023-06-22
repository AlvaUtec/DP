#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll DP[1000001];

const int MOD = 1e9 + 7;

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> coins(n);
	for (int i = 0; i < n; i++)
        cin >> coins[i];
	for (int i = 0; i <= x; i++) 
        DP[i] = INT_MAX;

	DP[0] = 0;

	for (int i = 1; i <= n; i++) 
		for (int weight = 0; weight <= x; weight++) 
			if (weight - coins[i - 1] >= 0) 
				DP[weight] = min(DP[weight], DP[weight - coins[i - 1]] + 1);
		
		
	
	cout << (DP[x] == INT_MAX ? -1 : DP[x]) << '\n';
}