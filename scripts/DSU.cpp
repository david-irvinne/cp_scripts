
struct DSU{
	static const int N = 1e5+5;
	int par[N], sz[N], mx_size = 1, comp = N;

	void init(){
		for(int i = 0; i < N; i++){
			par[i]=i;
			sz[i] = 1;
		}
	}	
	int findRep(int a){
		if(a == par[a]) return a;
		sz[par[a]]=sz[findRep(par[a])];
		return par[a] = findRep(par[a]);
	}
	bool same(int a, int b){
		return findRep(a) == findRep(b);
	}
	void join(int a, int b){
		if(same(a, b)) return ;
		a = findRep(a);
		b = findRep(b);
		mx_size = max(mx_size, sz[a] + sz[b]);
		sz[a] += sz[b];
		par[b] = a;
		comp--;
	}
};