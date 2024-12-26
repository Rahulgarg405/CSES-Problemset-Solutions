#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

map<string , bool> mp;
int n;
void rec(string s){
	if(mp.find(s) != mp.end()) return;
	cout<<s<<endl;
	mp[s] = 1;
	
	for(int i = 0 ;i<n ; i++){
		string temp = s;
		temp[i] = (temp[i] == '0') ? '1' : '0';
		rec(temp);
	}
}

void solve(){
	
	cin>>n;
	string s(n, '0');
	rec(s);
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