#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


// Recursive Binary Exponentiation :
// ll power(ll a, ll b){
//     if(b == 0) return 1;
//     ll res = power(a, b/2);
//     if(b%2 == 0) return (res*res)%MOD;
//     else return ((res*res)%MOD*a)%MOD;
// }


// Iterative Implementation :
ll power(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1ll){
            res = (res*a)%MOD;
        }
        a = (a*a)%MOD;
        b = b>>1;
    }
    return res;
}

void solve(){
    ll a, b;
    cin>>a>>b;
    cout<<power(a, b)<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}