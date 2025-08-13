// https://www.spoj.com/problems/PR003004/
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

	cin >> ALLTC; for(TC=1;TC<=ALLTC;TC++)
  doumo_same_desu();
}

pair<int,int> dp[17][2]; // {total sum, banyak cara konfigurasi bisa dilakukan}

pair<int,int> f(int idx, bool tight, string&s){
  if(idx == (int)s.size()){
    return {0, 1};
  }
  if(dp[idx][tight].first != -1) return dp[idx][tight];

  int sum = 0, way = 0, limit = tight ? s[idx] - '0' : 9; 
  for(int i = 0; i <= limit; i++){
    auto[subsum, subway] = f(idx + 1, tight && i == limit, s);

    way += subway;
    sum += i * subway + subsum;
  }
  return dp[idx][tight] = {sum, way};

}
int solve(int x){
  string s = to_string(x);
  for(int i = 0; i < 17; i++){
    for(int j = 0; j < 2; j++){
      dp[i][j] = {-1, -1};
    }
  }
  return f(0, true, s).first;
}

void doumo_same_desu(){
  int L, R; cin >> L >> R; cout << solve(R) - solve(L - 1) << '\n';
}

/*

*/
