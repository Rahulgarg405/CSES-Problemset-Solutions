#include <bits/stdc++.h>
using namespace std;

int n,cnt[1000001];

void solve(){
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        for(int p=1; p*p<=x ; p++){
            if(x%p==0){
                cnt[p]++;
                if(x/p != p) cnt[x/p]++;
            }
        }
    }
    for(int i=1000000 ; i>=1 ; i--){
        if(cnt[i]>=2){
            cout<<i<<"\n";
            break;    
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