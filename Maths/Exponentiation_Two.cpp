#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


// According to fermats theorem :
// a^(m-1)%m = 1;
// where a, m are co-prime;
// if we calculate a^b % mod ,
// as mod is prime so a, mod are coprime,
// therefore a^(mod-1) can be equated to 1,
// rest power b%(mod-1) is remaining as a's exponent;
// so we only use b%(mod-1) as power of a;
// this concept is uses when calculating : a^(b^c),
// we calculate (b^c)%(mod-1) and use it as exponent of a;


ll power(ll a, ll b, ll mod){
    ll res = 1;
    while(b){
        if(b&1ll){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b = b>>1;
    }
    return res;
}

void solve(){
    ll a, b, c;
    cin>>a>>b>>c;
    ll mid = power(b, c, MOD-1);
    cout<<power(a, mid, MOD)<<"\n";
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