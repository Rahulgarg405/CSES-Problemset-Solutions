#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

const int maxValue = 1e6+10;

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(int i = 0 ; i<n ; i++) cin>>v[i];
    
    vector<vector<int>> divisorsOf(maxValue);
    for(int i = 2 ; i<maxValue ; i++){
        if(divisorsOf[i].size() == 0){
            divisorsOf[i].push_back(i);
            for(int j = 2*i ; j<maxValue ; j+=i){
                divisorsOf[j].push_back(i);
            }
        }
    }
    vector<int> valuesDivisibleBy(maxValue);
    vector<int> primeDivisorsOf(maxValue);
    for(int i = 0 ; i<n ; i++){
        int val = v[i];
        for(int mask = 1 ; mask < (1<<(divisorsOf[val].size())) ; mask++){
            int combination = 1, primeDivisors = 0;
            for(int pos = 0 ; pos < divisorsOf[val].size() ; pos++){
                if((1<<pos)&mask){
                    combination *= divisorsOf[val][pos];
                    primeDivisors++;
                }
            }
            valuesDivisibleBy[combination]++;
            primeDivisorsOf[combination] = primeDivisors;
        }
    }
    ll totalNumberOfPairs = (n*(n-1))/2;
    ll validPairs = 0;
    for(int i = 0 ; i<maxValue ; i++){
        if(primeDivisorsOf[i]%2){
            validPairs += ((ll)valuesDivisibleBy[i]*((ll)valuesDivisibleBy[i]-1))/2;
        }
        else{
            validPairs -= ((ll)valuesDivisibleBy[i]*((ll)valuesDivisibleBy[i]-1))/2;
        }
    }
    cout<<totalNumberOfPairs-validPairs<<"\n";
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