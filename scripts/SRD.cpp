//https://cses.fi/problemset/task/1144/
struct square_root_decomposition{
  vector<int> ar;
  vector<vector<int>> s;
  int sq, n;
  square_root_decomposition(vector<int>&A){
    n = A.size();
    sq = sqrt(n) + 1;
    ar = A;
    s.resize(sq);
  }
  void build(){
    // setiap blok isi nya sorted array
    for(int i = 0; i < n; i++){
      s[i / sq].push_back(ar[i]);
    }
    for(vector<int>&v : s) if(v.size()){
      sort(v.begin(), v.end());
    }
  }

  int qry(int l, int r){ // TO-DO: sesuaikan tipe query
    int res = 0;
    for(auto&v : s){
      int sz = v.size();
      int lb = sz;
      for(int J = 1 << 9; J; J /= 2){
        if(lb - J >= 0 && v[lb - J] >= l) lb -= J;
      }

      int ub = -1;
      for(int J = 1 << 9; J; J /= 2){
        if(ub + J < sz && v[ub + J] <= r) ub += J;
      }

      res += max(0ll, ub - lb + 1);
    }
    return res;
  }
  void upd(int idx, int new_val){// idx use 0 based index
    int old_val = ar[idx];
    ar[idx] = new_val;

    int block = idx / sq;
    // hapus old_val di s[block], ganti ke new_val
    int sz = s[block].size();
    int pos = -1;
    for(int J = 1 << 9; J; J /= 2){
      if(pos + J < sz && s[block][pos + J] <= old_val) pos+=J;
    }
    s[block][pos] = new_val;
    // urutkan lagi array nya
    int j = pos;
    while(j > 0 && s[block][j-1] > s[block][j]){
      swap(s[block][j-1] , s[block][j]);
      j--;
    }
    j = pos;
    while(j + 1 < sz && s[block][j] > s[block][j+1]){
      swap(s[block][j] , s[block][j+1]);
      j++;
    }

  }
  void print(){
    for(auto v : s){
      for(int i : v){
        cout << i << ' ';
      }
      cout << '\n';
    }
    cout << '\n';
  }
};

void doumo_same_desu(){ 
  int n, q;
  cin >> n >> q;
  vector<int> ar(n);
  for(int i = 0; i < n; i++) cin >> ar[i];
  square_root_decomposition srd(ar);
  srd.build();
  // srd.print();

  while(q--){
    char t;
    int a, b;
    cin >> t >> a >> b;
    if(t == '?'){ // count number of ppl with salary a .. b
      cout << srd.qry(a, b) << '\n';
    }
    else { // ganti gaji orang ke a menjadi b
      srd.upd(a - 1, b);
    }
  }
}