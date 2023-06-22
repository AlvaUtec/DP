//https://cses.fi/problemset/task/1653/

#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;

const int mod = 1e9+7;

int weights[21];

// rides(S) minimun number of rides for subset S
// last(S) minimun weight of the last ride for subset S

pair<int,int> dp[1<<20]; // rides(S), last(S)


int main(){
    FASTIO;
    ll n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++)
        cin>>weights[i];
    
    dp[0] = {1,0}; // for the empty set, we need 1 ride and the last ride has weight 0

    for(int s = 1; s< (1<<n); s++){     //Iterate through all subsets in order
        dp[s] = {n+1,0};              //Initialize dp[s] to a large value
        for(int i = 0; i<n; i++){       //Iterate through all elements in the subset
            if(s & (1<<i)){             //If the element is in the subset
                auto option = dp[s^(1<<i)]; //Get the dp option for the subset without the element
                if(option.second + weights[i] <= x){ //If the last ride is less than x
                    option.second += weights[i];     //Add the weight of the last ride
                }else{                              
                    option.first++;                 //Add a new ride
                    option.second = weights[i];     //Set the weight of the last ride
                }
                dp[s] = min(dp[s],option);      //Update the dp option for the subset
            }
        }
    } 

    cout<<dp[(1<<n)-1].first<<"\n"; //Print the number of rides for the full set
}