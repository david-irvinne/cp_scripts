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

double angleFromPositiveY(double x, double y) {
  double angle = atan2(x, y);   // perhatikan: (x, y), bukan (y, x)
  angle = angle * 180.0 / M_PI; // ubah ke derajat

  if (angle < 0)
    angle += 360.0;           // supaya range 0–360

  return angle;
}
int n, q;
vector<array<int, 2>> ar;
vector<float> srt;

int cnt(float lb, float ub){
  int sz = srt.size();
  int R = -1;
  for(int J = 1 << 30; J; J /= 2){
    if(R + J < sz && srt[R + J] <= ub) R += J;
  }
  if(R == -1) return 0;
  int L = sz;
  for(int J = 1 << 30; J; J /= 2){
    if(L - J >= 0 && srt[L - J] >= lb) L -= J;
  }
  if(L == sz) return 0;

  return R - L + 1;
}

void doumo_same_desu(){
  cin >> n >> q;
  srt.resize(n);
  ar.resize(n);
  for(int i = 0; i < n; i++){
    cin >> ar[i][0] >> ar[i][1];
    srt[i] = angleFromPositiveY(ar[i][0], ar[i][1]);
  }

  sort(srt.begin(), srt.end());
  
  while(q--){
    int a, b;
    cin >> a >> b;
    a--; b--;

    float st = angleFromPositiveY(ar[a][0], ar[a][1]);
    float ed = angleFromPositiveY(ar[b][0], ar[b][1]);

    if(st <= ed){
      cout << cnt(st, ed) << '\n';
    }
    else {
      cout << n - cnt(ed, st) + 2 << '\n';
    }
  }
}

/*

*/
