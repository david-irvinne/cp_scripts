
const int N = 1e4+5, LOG = 20;
int n, m;
vector<int> adj[N];
vector<vector<int>> anc(N, vector<int>(LOG));
vector<int> depth(N);


int get_lca(int a, int b){
	if(depth[a] > depth[b]) swap(a, b); // buat b lebih dalam

	// samakan depth dari a dan b, b lebih dalam
	int k = depth[b] - depth[a];
	for(int j = LOG - 1; j >= 0; j--){
		if(k >= (1 << j)){
			k -= (1<<j);
			b = anc[b][j];
		}
	}
	// depth sama dan node sama
	if(a == b) return a;

	// depth sama node beda
	for(int j = LOG - 1; j >= 0; j--){
		if(anc[a][j] != anc[b][j]){
			a = anc[a][j];	
			b = anc[b][j];
		}
	}
	return anc[a][0];
}

void fill_anc(int now, int par){

	anc[now][0] = par;
	for(int i = 1; i < LOG; i++){
		anc[now][i] = anc[anc[now][i-1]][i-1];
	}
	depth[now] = depth[par] + 1;
	for(int nxt : adj[now]){
		if(nxt == par) continue;
		fill_anc(nxt, now);
	}

}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for(int u = 0; u < n; u++){
		int cnt = 0;
		cin >> cnt;
		while(cnt--){
			int v; cin >> v;
			adj[u].push_back(v);
		}
	}
	fill_anc(0, 0);
	int q; cin >> q;
	while(q--){
		int a, b;
		cin >> a >> b;
		cout << get_lca(a, b) << '\n';
	}
}