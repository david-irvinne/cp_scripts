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

const int MAXN = 1e5+5, LOG = 20;

int N, depth[MAXN], anc[MAXN][LOG];
vector <pair<int, int>> adj[MAXN];
int dist[MAXN], p;
vector<int> player;

// ngisi tabel dist, jarak dari root ke tiap node lain
void dfs2(int now, int prv){
	for(auto[next, cost] : adj[now]){
		if(next == prv) continue;
		dist[next] = dist[now] + cost;
		dfs2(next, now);
	}
}

void dfs(int now,int par) {
    anc[now][0] = par;
    for (int i=1; i<LOG; i++) {
        // dari now naik 2^i langkah
        // dari now naik 2^(i-1) naik lagi 2^(i-1)
        // dari anc[now][i-1] naik lagi 2^(i-1)
        int x = anc[now][i-1];
        anc[now][i] = anc[x][i-1];
    }
    depth[now] = depth[par] + 1;
    for (auto[next, cost] : adj[now]) {
        if (next == par) {
            continue;
        }
        dfs(next,now);
    }
}

int lca(int x,int y) {
    if (depth[x] < depth[y]) {
        swap(x, y);
    }

    for (int i=LOG-1; i>=0; i--) {
        if (depth[anc[x][i]] >= depth[y]) {
            x = anc[x][i];
        }
    }
    if (x == y) {
        return y;
    }

    for (int i=LOG-1; i>=0; i--) {
        if (anc[x][i] != anc[y][i]) {
            x = anc[x][i];
            y = anc[y][i];
        }
    }
    return anc[x][0];
}

void doumo_same_desu(){	
	cin >> N >> p;
    for (int i=1; i < N; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for(int i = 0; i < p; i++){
    	int x; cin >> x; player.push_back(x);
    }

    dfs(1,1);
    dist[1] = 0;
    dfs2(1, 1);

    // coba dirikan server di tiap lokasi player
    int res = LLONG_MAX;
    // dbg(res);
    for(int i : player){
    	int need = 0;
    	// dbg(i);
    	for(int j : player) if(i != j){
    		int l = lca(i, j);
    		need += dist[i] + dist[j] - 2 * dist[l];
    	}
    	res=min(res,need);
    }
    cout << res<<'\n';        
}
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(5);

	int tc = 1;
	// cin >> tc;
	while(tc--) doumo_same_desu();
}
/*

1 2
2 3
2 4

5 3
1 2 1
1 3 2
1 4 3
1 5 4
1 3 5

*/