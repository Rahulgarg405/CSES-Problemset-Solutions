#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

const int N = 1000010;
vector<ll> spf(N, 1e9);

void solve(){
    ll x;
    cin>>x;
    ll ans = 1;
    while(x != 1){
        ll prime = spf[x];
        ll k = 0;
        while(x%prime == 0){
            k++;
            x = x/prime;
        }
        ans *= (1+k);
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0 ; i<N ; i++){
        spf[i] = i;
    }
    for(ll i = 2 ; i<N ; i++){
        if(spf[i] == i){
            for(ll j = i*i ; j<N ; j+=i){
                spf[j] = min(spf[j] , i);
            }
        }
    }
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}