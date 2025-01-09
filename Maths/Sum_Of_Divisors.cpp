#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


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
    ll x;
    cin>>x;
    ll ans = 0;
    ll i = 1;
    ll modInvTwo = power(2, MOD-2);
    while(i <= x){
        ll q = x/i;
        ll j = x/q + 1;
        ll rangeTillJMinusOne = (((j%MOD)*((j-1)%MOD))%MOD * modInvTwo)%MOD;
        ll rangeTillIMinusOne = (((i%MOD) * ((i-1)%MOD))%MOD * modInvTwo)%MOD;
        ll range = (rangeTillJMinusOne - rangeTillIMinusOne + MOD)%MOD;
        ans = (ans + (q%MOD)*range)%MOD;
        i = j;
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}