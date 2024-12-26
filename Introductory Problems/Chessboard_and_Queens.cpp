#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

vector<string> v;
ll total = 0;

bool canPlace(int i, int j, int place[]){
	if(v[i][j] == '*') return false;
	for(int k = 0 ; k<i ; k++){
		if(place[k] == j || abs(place[k] - j) == abs(k-i)) return false;
	}
	return true;
}

ll rec(int i, int place[]){
	if(i == 8) return 1;
	ll ans = 0;
	for(int j = 0 ; j<8 ; j++){
		if(canPlace(i, j, place)){
			place[i] = j;
			ans += rec(i+1,place);
		}
	}
	return ans;
}

void solve(){
	for(int i = 0 ; i<8 ; i++){
		string s;
		cin>>s;
		v.push_back(s);
	}
	int place[8] = {0};
	cout<<rec(0, place)<<endl;
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