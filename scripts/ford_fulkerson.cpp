#include<bits/stdc++.h>
using namespace std;

#define int long long
#define Int __int128_t
#define dbg(x) cout<<"["<< #x <<"] : "<<(x)<<endl;
#define bpc(x) (__builtin_popcountll(x))

int bpow(int a, int b, long long mod=LLONG_MAX){
	int res=1;while(b){if(b%2)res=res*a%mod;a=a*a%mod;b/=2;}return res;
}
int inv(int a, int mod=1e9+7){ return bpow(a, mod-2, mod); }

int n, m; // n nodes, m edges

int g[100][100], rg[100][100], parent[100];
	
// return true jika ada jalan dari s ke t
bool bfs(int s, int t){
	vector<bool> vis(100);

	queue<int> q;
	q.push(s);
	vis[s] = 1;
	parent[s] = -1;

		
	while(q.size()){
		int u = q.front();
		q.pop();

		for(int v = 0; v < n; v++){
			if(vis[v] == false && rg[u][v] > 0){
				q.push(v);
				parent[v] = u;
				vis[v] = 1;
			}
		}
	}

	return vis[t];
}

void doumo_same_desu(){	

	int s = 0, t = 5;
	dbg(bfs(s, t));
	int max_flow = 0;

	while(bfs(s, t)){
		int path_flow = INT_MAX;
		for(int v = t; v != s; v = parent[v]){
			int u = parent[v];
			path_flow = min(path_flow, rg[u][v]);
		}

		for(int v = t; v != s; v = parent[v]){
			int u = parent[v];
			rg[u][v] -= path_flow;
			// rg[v][u] += path_flow;
		}
		max_flow += path_flow;
	}
	cout << max_flow << '\n';
        
}
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(5);

	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = w;
		rg[u][v] = w;
	}

	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < n; j++) {
	// 		cout << g[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }


	int tc = 1;
	// cin >> tc;
	while(tc--) doumo_same_desu();
}
/*
6 10

0 1 16
0 2 13
1 2 10
1 3 12
2 1 4
2 4 14
3 2 9
3 5 20
4 3 7
4 5 4

*/
