// padded segment tree, merged with lazy propagation
template<typename T>
struct segment_tree {
//INGAT: kalau ma pake 1-based index, buat array source nya 1-based index, bukan segment tree nya.
 
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
  T merge(T&a, T&b){
    return a + b;
  }
  // TO-DO: change the default return value of out of range
  T range_sum(int ql, int qr, int t, int tl, int tr){
    if(lazy_propagation && lz[t]){ // check kalau ada update di lz
      tree[t] += lz[t];
      if(tl != tr){
        lz[2 * t] += lz[t] / 2;
        lz[2 * t + 1] += lz[t] / 2;
      }
      lz[t] = 0;
    }

    if(ql <= tl && tr <= qr) return tree[t];
    if(tl > qr || ql > tr) return 0;
    int mid = (tl + tr) / 2;
    return range_sum(ql, qr, 2 * t, tl, mid) + range_sum(ql, qr, 2 * t + 1, mid + 1, tr);
  }
  T range_sum(int ql, int qr){
    return range_sum(ql, qr, 1, 0, sz - 1);
  }

  void point_update(int idx, T new_val){
    idx += sz;
    tree[idx] = new_val;
    for(idx /= 2; idx >= 1; idx /= 2){
      tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    }
  }

  // TO-DO: increase range atau update range?
  void range_update(int ql, int qr, int val, int t, int tl, int tr){
    if(lz[t]){ // check kalau ada update
      tree[t] += lz[t];
      if(tl != tr){
        lz[2 * t] += lz[t] / 2;
        lz[2 * t + 1] += lz[t] / 2;
      }
      lz[t] = 0;
    }

    if(ql <= tl && tr <= qr){
      tree[t] += val * (tr - tl + 1); // increase range
      if(tl != tr){
        lz[2 * t] += val * (tr - tl + 1) / 2;
        lz[2 * t + 1] += val * (tr - tl + 1) / 2;
      }
      return ;
    }
    if(qr < tl || ql > tr) return ;

    int mid = (tl + tr) / 2;
    range_update(ql, qr, val, 2 * t, tl, mid);
    range_update(ql, qr, val, 2 * t + 1, mid + 1, tr);
    tree[t] = tree[2 * t] + tree[2 * t + 1];
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


