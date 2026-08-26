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
  string s;
  int l, r;
  cin >> s >> l >> r;

  // ubah ke pecahan
  int koma_pos = -1;
  for(int i = 0; i < (int)s.size(); i++){
    if(s[i] == '.'){
      koma_pos = i;
      break;
    }
  }
  dbg(koma_pos);
  
  int p, q;
  if(koma_pos == -1){ // udah integer biasa
    p = stoi(s);
    q = 1;
  }
  else {
    string left = s.substr(0, koma_pos);
    string right = s.substr(koma_pos + 1);
    dbg(left);
    dbg(right);

    while(!right.empty() && right.back() == '0') right.pop_back();
    // klo belakang koma nol semua, sama aja integer
    if(right.empty()){
      p = stoi(s);
      q = 1;
    }
    else {
      p = stoi(left + right);
      q = bpow(10ll, right.size());
    }
  }
  
  // sederhanain
  int g = gcd(p, q);
  p /= g; q /= g;

  // p/q < l atau p/q > r, no answer
  if(p < l * q || p > q * r) {
    cout << "-1\n"; return ;
  }

  // panjangnya pasti q (???)
  int base = l;
  int d = p - q * base; 
  vector<int> res(q);
  for(int i = 0; i < q; i++){
    int take = min(d, r - l);
    dbg(take);
    res[i] = base + take;
    d -= take;
  } 
  if(d != 0){
    cout << "-1\n"; return ;
  }
  
  cout << q << '\n';
  for(int i : res) cout << i << ' ';
  cout << '\n';
}

/*
2.79
3 5

9 
1 10

8.6
1 10
*/
