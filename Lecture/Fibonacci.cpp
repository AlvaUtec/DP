#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int MAXN = 1e6 + 5;:

int n;
bool vis[MAXN];
ll F[MAXN];

ll fibonacci(int n){
    if (n == 1 or n == 2) return 1;
    ll a=1,b=1,c;
    for(int i=3;i<=n;i++){
        c = a+b;
        a=b;
        b=c;
    }
    return c;
}

void bottomUp(){
    cin>>n;
    cout<<"Fibonacci ("<<n<<"): "<<fibonacci(n)<<endl;
}

ll fibo(int n){
    if (n == 1 or n == 2) return 1;
    if(vis[n]) return F[n]; // Si ya lo calcule, no lo vuelvo a calcular
    return F[n] = fibo(n-1) + fibo(n-2);
}

void topDown(){
    cin>>n;
    cout<<"Fibonacci ("<<n<<"): "<<fibo(n)<<endl;
}

int main(){
    // bottomUp();
    topDown();
    return 0;
}