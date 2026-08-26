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
 
void doumo_same_desu(){
  int n, k, x,a, b, c;
  cin >> n >> k >> x >> a >> b >> c;
 
  vector<int>ar(n);
  ar[0] = x;
  for(int i = 1; i < n; i++) ar[i] = (ar[i-1] * a + b) % c;
 
  // actual number, or value up to that index
  vector<array<int, 2>> masuk, keluar;
  for(int i = 0; i < k; i++) {
    if(i == 0) masuk.push_back({ar[i], ar[i]});
    else masuk.push_back({ar[i], masuk.back()[1] | ar[i]});
  }
 
  int res = masuk.back()[1];
  dbg(res);
  for(int i = k; i < n; i++){
    
    if(keluar.empty()){
      while(masuk.size()){
        auto now = masuk.back();
        masuk.pop_back();
 
        if(keluar.empty()) keluar.push_back({now[0], now[0]});
        else keluar.push_back({now[0], keluar.back()[1] | now[0]}); 
      }
    }
    
    keluar.pop_back();
//    for(auto[p1, p2] : keluar) cout << p1 << ' ' << p2 << '\n';
    if(masuk.empty()) masuk.push_back({ar[i], ar[i]});
    else masuk.push_back({ar[i], masuk.back()[1] | ar[i]}); 
 
    int tmp = 0; 
    if(masuk.size()) tmp |= masuk.back()[1];
    if(keluar.size()) tmp |= keluar.back()[1];
    res ^= tmp;
  }
  cout << res << '\n';
}
 
/*
 
*/
