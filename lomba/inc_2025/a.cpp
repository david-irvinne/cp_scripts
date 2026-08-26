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

struct S{
  string name;
  int a, b, c, d;
  S() : name(""), a(0), b(0), c(0), d(0) {}
  S(string ss, int p, int q, int r, int s){
    name = ss;
    a = p;
    b = q;
    c = r;
    d = s;
  }
};

void doumo_same_desu(){
  int n;
  cin >> n;
  vector<S> ar(n);
  for(int i = 0; i < n; i++){
    ar[i] = S("", 0, 0, 0, 0);
    cin >> ar[i].name >> ar[i].a >> ar[i].b >> ar[i].c >> ar[i].d;
  }

  sort(ar.begin(), ar.end(), [&](S aa, S bb){
    if(aa.a + aa.c != bb.a + bb.c){
      return aa.a + aa.c > bb.a + bb.c;
    }
    if(aa.b + aa.d != bb.b + bb.d){
      return aa.b + aa.d < bb.b + bb.d;
    }
    return aa.name < bb.name;
  });

  for(auto o : ar){
    cout << o.name << '\n';
  }
}

/*

*/
