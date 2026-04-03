struct DSU{
  int n;
  vector<int> par; // if par[i] < 0, then i is the root
  int mx_size = 1, comp_cnt;

  DSU(int _n){
    n = comp_cnt = _n;
    par.resize(n + 1, -1);
  } 
  int root(int a){
    if(par[a] < 0) return a;
    return par[a] = root(par[a]);
  }
  bool same(int a, int b){
    return root(a) == root(b);
  }
  void join(int a, int b){
    a = root(a);
    b = root(b);
    if (a == b) return;
    if(par[a] < par[b]) swap(a, b);
    par[b] += par[a];
    par[a] = b;
    comp_cnt--;
	}
};

struct DSU{
  int n;
  vector<int> par, sz;
  int mx_size = 1, comp;

  DSU(int _n){
    n = _n;
    par.resize(n + 1);
    sz.resize(n + 1);
    comp = _n;
    for(int i = 0; i <= n; i++){
      par[i]=i;
      sz[i] = 1;
    }
  } 
  int findRep(int a){
    if(a == par[a]) return a;
    return par[a] = findRep(par[a]);
  }
  bool same(int a, int b){
    return findRep(a) == findRep(b);
  }
  void join(int a, int b){
    a = findRep(a);
    b = findRep(b);
    if (a == b) return;
    if(a > b) swap(a, b); // optional
    if (sz[a] < sz[b]) swap(a,b);
    par[b] = a;
    sz[a] += sz[b];
    comp--;
	}
};

