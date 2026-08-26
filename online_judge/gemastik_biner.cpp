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

int C[60][60];
void doumo_same_desu(); int TC, ALLTC;
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(5);

  for(int i = 1; i < 60; i++){
    for(int j = 0; j <= i; j++){
      if(j == 0 || i == j) C[i][j] = 1;
      else C[i][j] = C[i-1][j] + C[i-1][j - 1];
    }
  }

//	cin >> ALLTC; for(TC=1;TC<=ALLTC;TC++)
  doumo_same_desu();
}


void doumo_same_desu(){
  int n;
  cin >> n;
  int cnt0 = 0;
  while(C[cnt0 + 29][cnt0] < n){
    n -= C[cnt0 + 29][cnt0];
    cnt0++;
  }

  dbg(cnt0);
  vector<int> res;
  int cnt1 = 29;
  res.push_back(1);
  
  // konfigurasi sekarang: 10...111....
  while(cnt0 + cnt1 > 0){
    if(cnt0 == 0){
      res.push_back(1);
      cnt1--;
      continue;
    }
    if(cnt1 == 0){
      res.push_back(0);
      cnt0--;
      continue;
    }

    if(C[cnt0 + cnt1 - 1][cnt0 - 1] < n){ // banyak cara jika di posisi ini adalah nol
      // nol ga bisa ditaruh di sini
      n -= C[cnt0 + cnt1 - 1][cnt0 - 1];
      cnt1--;
      res.push_back(1);
    }
    // bisa taruh nol
    else {
      cnt0--;
      res.push_back(0);
    }
  }
  
  int ans = 0;
  for(int i = (int)res.size() - 1, j = 1; i >= 0; i--, j *= 2){
    if(res[i]) ans += j; 
  }
  cout << ans << '\n';
}

/*

*/