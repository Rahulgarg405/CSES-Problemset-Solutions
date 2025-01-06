#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
const int MOD = 1e9+7;

typedef tree<ll,null_type,less<ll>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

// ll rec(ll n, ll k){
//     if(n == 1) return 1;
//     return (rec(n-1, k)+k-1)%n+1;
// }

void solve(){
    ll n, k;
    cin>>n>>k;
    indexed_set st;
    for(ll i = 1 ; i<=n ; i++){
        st.insert(i);
    }
    ll ind = k%n;
    while(n--){
        auto it = st.find_by_order(ind);
        cout<<*it<<" ";
        st.erase(it);
        if(n) ind = (ind%n + k)%n;
    }
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