#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

ll mod(ll a, ll m = MOD) { 
    return a % m;
}
template <class T> class Math { 
    public: 
    vector<T> fact, invfact;
    Math() {} 
    Math(ll n) {
        fact.resize(n); 
        invfact.resize(n); 
        fact[0] = invfact[0] = 1; 
        for (ll i = 1; i < n; i++) { 
            fact[i] = mod(i * fact[i - 1]); 
            invfact[i] = modinv(fact[i]);       
        } 
    } 
    T modinv(T x, T m = MOD) { 
        return expo(x, m - 2, m);       
    } 
    T expo(T base, T exp, T m = MOD) { 
        T res = 1; 
        while (exp) { 
            if (exp & 1) res = mod(res * base, m); 
            base = mod(base * base, m); 
            exp >>= 1; 
        } 
        return res;    
    } 
    T choose(T n, T k) { 
        if (k < 0 || k > n) return 0; 
        T ans = fact[n]; 
        ans = mod(ans * invfact[n - k]); 
        ans = mod(ans * invfact[k]); 
        return ans;   
    }
};


// n -> childrens and m apples, so :
// Distribution can be :
// x1 + x2 + x3 + ........... + xn = m,
// where xi = no. of apples given to ith child and xi >= 0;
// so stars and bars concept can be used so :
// ans = (m + n - 1) C (n - 1);

Math<ll> math(2e6+1);

void solve(){
    ll n, m;
    cin>>n>>m;
    ll ans = math.choose(m+n-1, n-1);
    cout<<ans<<endl;
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