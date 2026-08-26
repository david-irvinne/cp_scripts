#include<bits/stdc++.h>
using namespace std;

#define int long long
#define Int __int128_t
#define bpc(x) __builtin_popcountll(x)
#define msb(x) (63-__builtin_clzll(x))

#ifdef DEBUG
#define dbg(x) cout<<"["<< #x <<"] : "<<(x)<<endl;
#else
#define dbg(x)
#endif

int bpow(int a, int b, long long mod=LLONG_MAX){
  int res=1;while(b){if(b%2)res=res*a%mod;a=a*a%mod;b/=2;}return res;
}
int inv(int a, int mod=1e9+7){ return bpow(a, mod-2, mod); }

void doumo_same_desu(); int TC, ALLTC;
signed main(){
  ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
  cout << fixed << setprecision(5);

  doumo_same_desu();
}
const int MOD = 998244353, MAXA = 200000;
int Cnt[MAXA+1], G[MAXA+1], H[MAXA+1], m[MAXA+1];

void doumo_same_desu(){
  int n; 
  cin >> n;
  int maxA = 0;
  for(int i = 0; i < n; i++){
      int x; cin >> x;
      Cnt[x]++;
      maxA = max(maxA, x);
  }
  
  for(int d = maxA; d >= 1; d--){
      long long sumCnt = 0;
      for(int mult = d; mult <= maxA; mult += d){
          sumCnt += Cnt[mult];
      }
      G[d] = sumCnt;
  }


  int mod1 = MOD - 1;  
  for(int d = 1; d <= maxA; d++){
      long long g = G[d];
      if(g >= 2) {
          long long temp = g * (g - 1) / 2; 
          H[d] = temp % mod1; 
      } else {
          H[d] = 0;
      }
  }

  
  vector<int> prime, min_prime(maxA+1, 0);
  m[1] = 1;
  for (int i = 2; i <= maxA; i++) {
    if (!min_prime[i]) {
      min_prime[i] = i;
      prime.push_back(i);
      m[i] = -1; 
    }
    for (int p: prime) {
      if (p > min_prime[i] || p*i > maxA) break;
      min_prime[p*i] = p;
      if (i % p == 0) {
        m[p*i] = 0; 
        break;
      } 
      else {
        m[p*i] = -m[i];
      }
    }
  }

  int F[MAXA+1];
  for(int d = 1; d <= maxA; d++){
    int sum = 0;
    for(int k = d; k <= maxA; k += d){
      if(m[k/d] == 0) continue;
      int val = m[k/d] * H[k];
      sum += val;
    }
      
    int tmp = sum % mod1;
    if(tmp < 0) tmp += mod1;
    F[d] = tmp;
  }
  
  int res = 1;
  for(int d = 1; d <= maxA; d++){
    if(F[d] == 0) continue;
    
    int tmp = bpow(d, F[d], MOD);
    res = (res * tmp) % MOD;
  }

  cout << res << "\n";
}

/*

*/
