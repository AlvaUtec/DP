#include <bits/stdc++.h>

using namespace std;

#define cpu() cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0)
#define ll long long
#define endl '\n'
#define lld long double

const int MAXN = 10005;
const int MOD = 1e9 + 7;

int n;
ll memo[MAXN][MAXN];
bool vis[MAXN][MAXN];

void Coeficients(int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            if (j== 0 || j==i) memo[i][j] = 1;  // Casos base
            else memo[i][j] = (memo[i-1][j-1] + memo[i-1][j]) % MOD;  // Relacion de recurrencia
        }
    }
}

ll C(int n, int m){
    if (m==0 || n==m) return memo[n][m] = 1; // Casos base
    if(vis[n][m]) return memo[n][m]; // Si ya lo calcule, no lo vuelvo a calcular
    return memo[n][m] = memo[n][n-m] = C(n-1,m-1) + C(n-1,m); // Relacion de recurrencia
}

void bottomUp(){
    cin >> n;
    Coeficients(n);
    cout<<"Coeficients of binom of grade "<<n<< ":\n";
    for(int i=0;i<=n;i++)
        cout<<memo[n][i] <<" ";
    
    cout<<endl;
    return 0;
}

void topDown(){
    int a,b;
    cin>>a>>b;

    cout<< "Combinatoria de " << a<<" en "<< b<<": "<< C(a,b) <<endl;
}

int main(){
    cpu();
    // bottomUp();
    topDown();
    return 0;
}




//Complejidad = n²