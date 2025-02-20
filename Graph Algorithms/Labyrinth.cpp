#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


ll n, m, srcX, srcY, desX, desY;
vector<vector<int>> dir = {
	{0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

void solve(){
	cin>>n>>m;
	vector<vector<char>> v(n, vector<char>(m));
	for(int i = 0 ; i<n ; i++){
		for(int j = 0 ; j<m ; j++){
			cin>>v[i][j];
			if(v[i][j] == 'A'){
				srcX = i, srcY = j;
			}
			if(v[i][j] == 'B'){
				desX = i, desY = j;
			}
		}
	}

	vector<vector<ll>> dist(n, vector<ll>(m, 1e9));
	dist[srcX][srcY] = 0;
	vector<vector<pair<int, int>>> path(n, vector<pair<int, int>>(m));

	queue<pair<int, int>> q;
	q.push({srcX, srcY});
	
	while(!q.empty()){
		int x = q.front().first, y = q.front().second;
		q.pop();
		for(auto d : dir){
			int nx = x + d[0], ny = y + d[1];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m || v[nx][ny] == '#') continue;
			if(dist[nx][ny] == 1e9){
				dist[nx][ny] = 1 + dist[x][y];
				q.push({nx, ny});
				path[nx][ny] = {x, y};
			}
		}
	}

	if(dist[desX][desY] == 1e9){
		cout<<"NO\n";
		return;
	}

	vector<pair<int, int>> p;
	int x = desX, y = desY;
	while(x != srcX || y != srcY){
		p.push_back({x, y});
		int tempX = path[x][y].first, tempY = path[x][y].second;
		x = tempX, y = tempY;
	} 

	p.push_back({x, y});
	reverse(p.begin(), p.end());
	string s = "";

	for(int i = 1 ; i<p.size() ; i++){
		int curX = p[i].first, curY = p[i].second;
		int prevX = p[i-1].first, prevY = p[i-1].second;
		if(curX == prevX+1) s += 'D';
		else if(curX == prevX-1) s += 'U';
		else if(curY == prevY+1) s += 'R';
		else s += 'L';
	}
	cout<<"YES\n";
	cout<<dist[desX][desY]<<"\n";
	cout<<s<<"\n";
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