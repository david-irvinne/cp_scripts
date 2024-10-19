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

void doumo_same_desu(){	
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // cost, destination
    priority_queue<pair<int, int>> pq;

    // start with node 1
    for(auto[v, w] : adj[1]) pq.push({-w, v});
    vector<bool>vis(n + 1);
    vis[1] = true;

    int mst = 0;
    while(pq.size()){
        auto[w, v] = pq.top();
        pq.pop();
        if(vis[v]) continue;

        // take v
        vis[v] = true;
        mst += w * -1;
        // include all neighbour of v
        for(auto[dest, cost] : adj[v]){
            pq.push({-cost, dest});
        }
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            // dbg(i);
            cout << "IMPOSSIBLE\n";
            return ;
        }
    }
    cout << mst << "\n";
}
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(5);

	int tc = 1;
	// cin >> tc;
	while(tc--) doumo_same_desu();
}
/*

10 20
7 9 8
3 10 1
4 8 8
1 7 1
1 3 9
4 5 10
7 10 8
5 6 8
6 7 9
2 3 7
7 8 6
3 7 6
1 2 2
9 10 1
6 10 4
4 6 6
8 9 10
5 8 9
8 10 5
3 4 9

*/