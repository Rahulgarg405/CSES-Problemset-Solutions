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

ll numberOfDivisors(vector<pair<ll,ll>> &v){
    ll ans = 1;
    for(auto p : v){
        ll k = p.second;
        ans = (ans*(1+k))%MOD;
    }
    return ans;
}

ll sumOfDivisors(vector<pair<ll,ll>> &v){
    ll ans = 1;
    for(auto p : v){
        ll x = p.first, k = p.second;
        ans = (ans%MOD * (power(x, 1+k) - 1)%MOD)%MOD;
        ans = (ans%MOD * power(x-1, MOD-2)%MOD)%MOD;
    }
    return ans;
}


// Product of divisors of number n :
//  => n ^(x/2),
// where x is number of divisors of n;

ll productOfDivisors(vector<pair<ll,ll>> &v){
    int n = v.size();
    ll product = 1;
    bool oddExponent = false;
    int posOfOddExponent;
    for(int i = 0 ; i<n ; i++){
        if(v[i].second%2 == 1){
            oddExponent = true;
            posOfOddExponent = i;
        }
    }
    if(oddExponent){
        ll outerExponent = 1;
        for(int i = 0 ; i<n ; i++){
            if(i == posOfOddExponent){
                outerExponent = (outerExponent * (v[i].second+1)/2)%(MOD-1);
            }
            else{
                outerExponent = (outerExponent * (v[i].second+1))%(MOD-1);
            }
        }
        for(int i = 0 ; i<n ; i++){
            product = (product  * power(v[i].first, (v[i].second*outerExponent)%(MOD-1)))%MOD;
        }
    }
    else{
        ll outerExponent = 1;
        for(int i = 0 ; i<n ; i++){
            outerExponent = (outerExponent * (v[i].second+1))%(MOD-1);
        }
        for(int i = 0 ; i<n ; i++){
            product = (product  * power(v[i].first, ((v[i].second/2)*outerExponent)%(MOD-1)))%MOD;
        }
    }
    return product;
}

void solve(){
    ll n;
    cin>>n;
    vector<pair<ll,ll>> factors(n);
    for(ll i = 0 ; i<n ; i++){
        ll x, k;
        cin>>x>>k;
        factors[i].first = x;
        factors[i].second = k;
    }
    cout<<numberOfDivisors(factors)<<" ";
    cout<<sumOfDivisors(factors)<<" ";
    cout<<productOfDivisors(factors)<<"\n";
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