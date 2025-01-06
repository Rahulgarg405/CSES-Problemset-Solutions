#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


ll rec(ll n, ll k){
    if(n == 1) return 1;
    if(k <= (n+1)/2){
        if(2*k > n) return (2*k)%n;
        else return 2*k;
    }
    ll c = rec(n>>1ll, k - (n+1)/2);
    if(n&1ll) return 2*c+1;
    else return 2*c-1;
}


void solve(){
    ll n, k;
    cin>>n>>k;
    cout<<rec(n, k)<<"\n";
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