// https://atcoder.jp/contests/abc442/tasks/abc442_e
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

struct vec {
  int x, y;

  int half(){
    return (y > 0 || (y == 0 && x > 0)) ;
  }

  void simp(){
    int g = gcd(abs(x), abs(y));
    x /= g;
    y /= g;
  }
  pair<int,int> to_pair(){
    return {x, y};
  }
};

int cross(vec a, vec b){
  return a.x * b.y - a.y * b.x;
}

void doumo_same_desu(){
  int N, Q;
  cin >> N >> Q;

  vector<vec> ori(N), srt(N);
  for(int i = 0; i < N; i++){
    cin >> ori[i].x >> ori[i].y;
    ori[i].simp();
    srt[i] = ori[i];
  }

  sort(srt.begin(), srt.end(), [&](vec l, vec r){
    if (l.half() != r.half()) return l.half() > r.half();
    return cross(l, r) > 0;
  });

  map<pair<int, int>, int> first_pos, last_pos, cnt;
  for(int i = 0; i < N; i++){
    if(first_pos[srt[i].to_pair()] == 0) first_pos[srt[i].to_pair()] = i + 1;
    last_pos[srt[i].to_pair()] = i + 1;
    cnt[srt[i].to_pair()]++;
  }

  while(Q--){
    int a, b;
    cin >> a >> b;

    swap(a, b);
    a--; b--;
    if(ori[a].x == ori[b].x && ori[a].y == ori[b].y) {
      cout << cnt[ori[a].to_pair()] << '\n';
      continue;
    }
    int st = first_pos[ori[a].to_pair()];
    int ed = last_pos[ori[b].to_pair()];

    if (st < ed){
      cout << ed - st + 1 << '\n';
      continue;
    }
    swap(a, b);
    
    st = first_pos[ori[a].to_pair()];
    ed = last_pos[ori[b].to_pair()];
    cout << N - (ed - st + 1) + cnt[ori[a].to_pair()] + cnt[ori[b].to_pair()] << '\n';
  }
  // cout << '\n'; 
  // for(auto v : srt) cout << v.x << ' ' << v.y << '\n';
}

/*

*/
