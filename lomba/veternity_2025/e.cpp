#include<bits/stdc++.h>
#include <climits>
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
string dig;
vector<int> ctk = {2, 3, 4, 5, 7, 8, 9};
Int dp[20][2][5][2][2]; // idx, tight, cur3, last5, started

Int f(int idx, bool tight, int cur3, bool last5, bool started){
  //cout << idx << ' ' << tight << ' ' << cur3 << ' ' << last5 << ' ' << started << endl;
  if(idx == (int)dig.size()) {
    if((Int)(started && (cur3==0 || last5))) cout << "hi\n";
    return (Int)(started && (cur3==0 || last5));
  }
  if(dp[idx][tight][cur3][last5][started] != (Int)(-1))return dp[idx][tight][cur3][last5][started];

  Int res = 0;
  if(!started){
    res += f(idx + 1, false, cur3, last5, false);
  }

  int limit = tight ? dig[idx] - '0' : 9;
  for(int i : ctk){
    if(i > limit) break;
    res += f(idx + 1, tight && i == limit, (cur3 + i) % 3, i == 5, true);
  }
  return dp[idx][tight][cur3][last5][started] = res;
}

string to_str(Int n){
  string res = "";
  while(n > (Int)0){
    res += '0' + (n % (Int)10);
    n /= (Int)10;
  }
  reverse(res.begin(), res.end());
  return res;
}

Int solve(Int k){
  dig = to_str(k);
  memset(dp, (Int)-1, sizeof(dp));

  return f(0,  true, 0, 0, false);
}

int cnt(Int k) {
  int res = 0;
  while(k > 0){
    res++;
    k/= 10;
  }
  return res;
}


void doumo_same_desu(){
  int k;
  cin >> k;

  Int l = (Int)3, r = (Int)1;
  for (int i = 0; i < 25; i++) {
    r = r * (Int)10;
  }
  cout << to_str(solve(r)) << endl;

  //cout << to_str(r) << endl;
  //cout << cnt(r) << "\n";
  //cout << solve(Int(5)) << endl;
  while(l < r){
  Int mid = l + (r - l) / 2;
  //cout << to_str(l) << " : " << to_str(r) << endl;
  //dbg(to_str(solve(mid)));
  if(solve((Int)(mid)) >= (Int)k) r = mid;
  else l = mid + 1;
  }
  cout << to_str(l) << '\n';

  // Int res = 1ll << 60;
  // for(int J = 1ll << 62; J; J /= 2){
  //   if(res - J >= 0 && solve(res - J) >= k) res -= J;
  // }
  // cout << res << '\n';

  // int l = 0, r = 1e18;
  // while (l < r) {
  //   int m = l + (r - l)/2;
  //   if (solve(m) < k) l = m + 1;
  //   else if (solve(m) == k) {
  //     if (cantik(m)) {
  //       cout << m;
  //       return;
  //     } else r = m - 1;
  //   } else r = m - 1;
  // }
  // cout << l;
}

/*

*/
