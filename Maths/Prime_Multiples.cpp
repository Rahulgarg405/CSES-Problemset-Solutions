#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

// In this we use inclusion-exclusion principle ,
// to compute multiples of all primes ,
// as there can be common multiples also, so we need to remove them ,so we use inclusion-exclusion,
// There can be 2^k subsets of k numbers,
// so we generate all subsets,
// => no of multiples of num till n = n/num;
// so we use this to get number of multiples for each subset,
// and add if subset size is odd,
// and subtract if even;

// The inclusion-exclusion principle can be expressed as follows:
// To compute the size of a union of multiple sets, 
// it is necessary to sum the sizes of these sets separately, 
// and then subtract the sizes of all pairwise intersections of the sets, 
// then add back the size of the intersections of triples of the sets, 
// subtract the size of quadruples of the sets, 
// and so on, up to the intersection of all sets.

// So we add when size of set is odd, 
// and subtract when size of set is even;


void solve(){
    ll n, k;
    cin>>n>>k;
    vector<ll> v(k);
    for(int i = 0 ; i<k ; i++) cin>>v[i];

    ll ans = 0;
    int subsets = (1<<k);

    for(int i = 1 ; i<subsets ; i++){
        ll num = n;
        for(int j = 0 ; j<k ; j++){
            if(i&(1<<j)) num = num/v[j];
        }
        if(__builtin_popcount(i)&1) ans += num;
        else ans -= num;
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