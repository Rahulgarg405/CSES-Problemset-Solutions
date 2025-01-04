#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


void solve(){
	int n;
	cin>>n;	
	queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    bool skip = true;
    while (!q.empty()) {
        int val = q.front();
        q.pop();
        if (skip) {
            q.push(val);
        } else {
            cout << val << " ";
        }
        skip = !skip;
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