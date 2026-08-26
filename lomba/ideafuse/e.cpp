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

void doumo_same_desu(){
  int W, N;
  cin >> W >> N;

  vector<int> bad(W + 5);
  int leftmost = 1e9, rightmost = 0;
  for(int i = 0; i < N; i++){
    int x, r;
    cin >> x >> r;
    leftmost = min(leftmost, x);
    rightmost = max(rightmost, x);
    int l = max(2ll, x - r);
    r = min(W, x +r);
    bad[l]++;
    if(r + 1 <= W) bad[r + 1]--;
  }
  
  // for(int i = 0; i < W + 5; i++) cout << bad[i] << ' ';
  // cout << '\n';
  for(int i = 1; i < W + 5; i++){
    bad[i] += bad[i-1];
  }
  
  int C = 1, R = rightmost - 1;
  for(int i = 2; i <= W; i++) if(!bad[i]){
    int le = i - leftmost;
    int ri = rightmost - i;
    int mx = max(le, ri);
    if(mx < R){
      R = mx;
      C = i;
    }
  }
  cout << C << ' ' << R << '\n'; 
}

/*

*/
