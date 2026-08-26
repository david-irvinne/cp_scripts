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

//	cin >> ALLTC; for(TC=1;TC<=ALLTC;TC++)
  doumo_same_desu();
}


array<int, 16> base(char t, int k){ // buat construct leaf nya
  array<int, 16> res;
  for(int i = 0; i < 16; i++){
    if(t == '+') res[i] = (i + k) % 16;
    else res[i] = (i ^ k);
  }
  return res;
}

// padded segment tree, merged with lazy propagation
template<typename T>
struct segment_tree {
  vector<T> tree, lz;
  int sz = 1;
  segment_tree(vector<T>ar){
    int n = ar.size();
    while(sz < n) sz *= 2;
    tree.resize(2 * sz, T());
    build(ar);
  }

  // TODO: merge behaviour between two nodes
  T merge(T a, T b){
    T res;
    for(int i = 0; i < 16; i++){
      res[i] = b[a[i]]; // fungsi komposisi biasa, resulting b (yang kanan)
    }
    return res;
  }

  // TODO: fill this build function
  void build(vector<T>ar){
    // identity, bukan 0 semua
    T id;
    for(int i = 0; i < 16; i++) id[i] = i;
    int n = ar.size();
    for(int i = n; i < sz; i++) tree[sz + i] = id;
    // dbg(sz);
    // dbg(n);
    // isi leaf nya
    for(int i = 0; i < n; i++) tree[sz + i] = ar[i];

    // isi internal nodes 
    for(int i = sz - 1; i >= 1; i--) tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
  }

  // TODO: change the default return value of out of range
  T range_query(int ql, int qr, int t, int tl, int tr){

    if(ql <= tl && tr <= qr) return tree[t];
    if(tl > qr || ql > tr) return ;// put default outside value
    int mid = (tl + tr) / 2;
    return merge(range_query(ql, qr, 2 * t, tl, mid) , range_query(ql, qr, 2 * t + 1, mid + 1, tr));
  }

  T range_query(int ql, int qr){
    return range_query(ql, qr, 1, 0, sz - 1);
  }

  // TODO: updatenya increase apa change?
  void point_update(int idx, char c, int k){
    idx += sz;
    tree[idx] = base(c, k);
    for(idx /= 2; idx >= 1; idx /= 2){
      tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    }
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
  vector<pair<char, int>> op(n); // operasi, bilagna
  vector<array<int, 16>> leaf(n);
  for(int i = 0; i < n; i++){
    cin >> op[i].first >> op[i].second;
    leaf[i] = base(op[i].first, op[i].second); // leaf nya
  }
  
  segment_tree< array<int, 16> > st(leaf);

  while(q--){
    int idx, k; char c;
    cin >> idx >> c >> k;
    st.point_update(idx - 1, c , k);
    cout << st.tree[1][0] << '\n';
  }
}

/*
4 2
+ 3
x 5
x 9
+ 15
2 + 8
1 x 10
*/
