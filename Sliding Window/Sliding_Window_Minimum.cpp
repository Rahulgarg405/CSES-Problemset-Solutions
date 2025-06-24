#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


// we maintain a monotonically increasing deque;

// front of deque holds index of min element in current window;

// elements in back are removed if they are >= current value,
// to maintain monotonically increasing order of deque;

// elements in front are removed if they go out of window;


void solve(){
	ll n, k;
	cin>>n>>k;
	ll x, a, b, c;
	cin>>x>>a>>b>>c;
	vector<ll> v(n);
	v[0] = x;
	for(int i = 1 ; i<n ; i++){
		v[i] = (a*v[i-1] + b)%c;
	}
	ll ans = 0;
	deque<ll> dq;
	for(int i = 0 ; i<n ; i++){
		while(!dq.empty() && v[dq.back()] >= v[i]) dq.pop_back();
		dq.push_back(i);
		if(dq.front() <= i-k) dq.pop_front();
		if(i >= k-1) ans ^= v[dq.front()];
	}
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