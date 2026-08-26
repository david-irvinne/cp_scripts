#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define Int __int128_t

#ifdef DEBUG
#define dbg(x) cout << "["<< #x <<"] : "<< (x) <<endl;
#else
#define dbg(x)
#endif

int bpow(int a, int b, int64_t mod = LLONG_MAX) {
	int res=1;while(b){if(b%2)res=res*a%mod;a=a*a%mod;b/=2;}return res;
}
int inv(int a, int mod=1e9+7){ return bpow(a, mod-2, mod); }

void doumo_same_desu(); int TC, ALLTC;
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(5);

	// cin >> ALLTC; for(TC=1;TC<=ALLTC;TC++)
  doumo_same_desu();
}

template<typename T>
struct segment_tree {
//INGAT: kalau pake 1-based index, buat array source nya 1-based index, bukan segment tree nya.
  vector<T> tree, lz;
  int sz = 1;
  bool lazy_propagation = false;
  segment_tree(vector<T>&ar, bool lp = false){
    lazy_propagation = lp;

    int n = ar.size();
    while(sz < n) sz *= 2;
    tree.resize(2 * sz);
    if(lazy_propagation){
      lz.resize(2 * sz);
    }
    build(ar);
  }
  // TO-DO: fill this build function
  void build(vector<T>&ar){
    int n = ar.size();
    // isi leaf nya
    for(int i = 0; i < n; i++) tree[sz + i] = ar[i];
    // isi internal nodes 
    for(int i = sz - 1; i >= 1; i--) tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
  }
  // TO-DO: merge behaviour between two nodes
  T merge(T a, T b){
    return max(a, b);
  }
  // TO-DO: change the default return value of out of range
  T range_query(int ql, int qr, int t, int tl, int tr){
    if(lazy_propagation && lz[t]){ // check kalau ada update di lz
      tree[t] += lz[t];
      if(tl != tr){
        lz[2 * t] += lz[t];
        lz[2 * t + 1] += lz[t];
      }
      lz[t] = 0;
    }

    if(ql <= tl && tr <= qr) return tree[t];
    if(tl > qr || ql > tr) return -(int)(2e15);// default outside value
    int mid = (tl + tr) / 2;
    return merge(range_query(ql, qr, 2 * t, tl, mid) , range_query(ql, qr, 2 * t + 1, mid + 1, tr));
  }
  T range_query(int ql, int qr){
    return range_query(ql, qr, 1, 0, sz - 1);
  }
  // TO-DO: updatenya increase apa change?
  void point_update(int idx, T new_val){
    idx += sz;
    tree[idx] = new_val;
    for(idx /= 2; idx >= 1; idx /= 2){
      tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    }
  }
  // TO-DO: LAZY PROPAGATION, increase range atau update range?
  void range_update(int ql, int qr, int val, int t, int tl, int tr){
    if(lz[t]){ // check kalau ada update
      tree[t] += lz[t];
      if(tl != tr){
        lz[2 * t] += lz[t];
        lz[2 * t + 1] += lz[t];
      }
      lz[t] = 0;
    }

    if(ql <= tl && tr <= qr){
      tree[t] += val ; // increase range
      if(tl != tr){
        lz[2 * t] += val ;
        lz[2 * t + 1] += val ;
      }
      return ;
    }
    if(qr < tl || ql > tr) return ;

    int mid = (tl + tr) / 2;
    range_update(ql, qr, val, 2 * t, tl, mid);
    range_update(ql, qr, val, 2 * t + 1, mid + 1, tr);
    tree[t] = merge(tree[2 * t] , tree[2 * t + 1]);
  }
  // implement lazy_propagation
  void range_update(int ql, int qr, int val){
    if(!lazy_propagation){
      cout << "ERROR: MUST IMPLEMENT LAZY PROPAGATION\n"; return ;
    }
    range_update(ql, qr, val, 1, 0, sz - 1);
  }
  void _print(){
    for(int i = 1; i < 2 * sz; i++){
      cout << i << ": " << tree[i] << '\n';
    }
  }
};

void doumo_same_desu(){
  int n, q;
  cin >> n >> q;
  vector<int> ar(n + 1);
  for(int i = 1; i <= n; i++){
    cin >> ar[i];
    ar[i] += ar[i-1];
  }

//  for(int i = 1; i <= n; i++) cout << ar[i] << ' ';
//  cout <<"\n";
  
  // segment tree nya adalah nilai max dari prefix array
  segment_tree<int> st(ar, true);
  while(q--){
    int t;
    cin >> t;
    if(t == 1){ // update value ke-k jadi u
      int k, u;
      cin >> k >> u;
      int old = st.range_query(k, k) - st.range_query(k - 1, k - 1); // ambil nilai sebenarnya, bukan prefix sum
      int d = u - old;

      // increase elemen di range(k, n) dengan value d
      st.range_update(k, n, d);
    }
    else { // ambil maximum prefix
      int a, b;
      cin >> a >> b;
//      cout << "ambil range: " << a << ' ' << b << "\n";
      dbg(st.range_query(a, b));
      dbg(st.range_query(a - 1, a - 1));
      cout << max(0ll, st.range_query(a, b) - st.range_query(a-1, a-1))  << "\n";
    }
  }

}

/*

*/
