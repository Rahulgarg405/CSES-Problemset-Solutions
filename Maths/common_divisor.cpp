#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e6;
vector<int> occ_num(N+1);

void solve(){
    ll n;
    cin>>n;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        occ_num[x]++;
    }
    for(ll gcd = N ; gcd > 0 ; gcd--){
        // see how many elements have this number as a divisor :
        ll div = 0;
        for(ll i = gcd ; i<=N ; i += gcd) {
            div += occ_num[i];
        }
        if(div >= 2){
            cout<<gcd<<"\n";
            return;
        }
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