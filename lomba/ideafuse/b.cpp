#include<bits/stdc++.h>
using namespace std;

#define int long long

int bpow(int a, int b, int MOD){
  int res = 1;
  while(b){
    if(b % 2) res = res * a % MOD;
    a = a * a % MOD;
    b /= 2;
  }
  return res;
}

int inv(int a, int MOD){
  return bpow(a, MOD - 2, MOD);
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  
  const int N = 2e6 + 5, MOD = 998244353;
  vector<int> fac(N + 5);
  fac[0] = 1;
  for(int i= 1; i <= N; i++){
    fac[i] = fac[i-1] * i % MOD;
  }

  int q;
  cin >> q;
  while(q--){
    int n;
    cin >> n;

    int bawah = inv(fac[n] * fac[n] % MOD, MOD);
    int atas = fac[2 * n]; 
    int res = atas * bawah % MOD;
    cout << res << '\n';
  }
}


/*
6 2
2 4 5 3 1 6
*/
