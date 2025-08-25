
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

