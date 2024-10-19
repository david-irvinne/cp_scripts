struct RabinKarp{
  static const int MOD = 1e9 + 9;
  int PP = 53;
  vector<int> H, P; // uses 1-base index
  string S;

  void init(string s, int _PP = 53){
    S = " " + s;
    PP = _PP;
    int sz = s.size();
    H = vector<int>(sz + 1);
    P = vector<int>(sz + 1);

    P[0]=1;
    for(int i = 1; i <= sz; i++){
        P[i] = (P[i-1] * PP) % MOD;
    }
    // calculate hash table for S
    for(int i = 1; i <= sz; i++){
        H[i] = (H[i-1] + (S[i]-'a'+1) * P[i]) % MOD;
    }
  }
  int get_hash(int l, int r){ // remember to use 1-based index
    int res = (H[r]-H[l-1]+MOD)%MOD;
    res *= inv(P[l], MOD);
    res %= MOD;
    return res;
  }
};