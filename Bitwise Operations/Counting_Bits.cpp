#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const int MOD = 1e9+7;

ll lcm(ll a, ll b){
	return (a*b)/__gcd(a, b);
}

ll countFactors(ll n){
	ll count = 0;
	for(ll i = 1 ; i*i <= n ; i++){
		if(n%i == 0){
			count++;
			if(n/i != i) count++;
		}
	}
	return count;
}

bool isPrime(ll n)
{
    ll count = 0;
    for(ll i = 1 ; i*i<=n ; i++){
        if(n%i == 0){
            count++;
            if(n/i != i) count++;
        }
    }
    return count==2;
}


ll power(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b&1){
			ans = ans*a;
		}
		a = a*a;
		b = b>>1;
	}
	return ans;
}

bool endsWith(const string &a, const string &suffix){
	if(suffix.size() > a.size()) return false;
	return (a.compare(a.size()-suffix.size(), suffix.size(), suffix) == 0);
}



void solve(){
	ll n;
	cin>>n;
	int msb = 63 - __builtin_clzll(n);
	// cout<<msb<<endl;
	ll ans = 0;
	for(int i = 0 ; i<msb ; i++){
		ll pw = power(2, i+1);            // 2^(i+1)
        ll full_blocks = n / pw;          // <<< floor, not ceil
        ll bits = (1LL<<i) * full_blocks; // ones from full blocks

        ll rem = n % pw;                  // remainder (last partial block size)
        ll add = max(0LL, rem - (1LL<<i) + 1); // ones from partial block
        bits += add;

        ans += bits;
	}
	ans += n - power(2, msb) + 1;
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