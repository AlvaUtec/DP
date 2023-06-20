#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define lld long double


const int MAXN = 10005;
const int MOD = 1e9 + 7;

int n;
ll C[MAXN];

void Catalan(int n){
    C[0] = 1; //Caso base
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i-1;j++){
            C[i] += C[j]*C[i-j-1] % MOD; // Relacion de recurrencia
        }
    }
}

int main(){
    cin>>n;
    Catalan(n);
    cout<<"Numero de Catalan ("<<n<<"): "<<C[n]<<endl;
    
}