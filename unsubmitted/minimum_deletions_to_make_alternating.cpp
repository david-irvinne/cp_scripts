// https://leetcode.com/problems/minimum-deletions-to-make-alternating-substring/description/
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define dbg(x) cout << "["<< #x <<"] : "<< (x) <<endl;
#else
#define dbg(x)
#endif

class Solution {
public:
  // segment tree, leaf[i] = 1 jika s[i] == s[i-1]
  vector<int> tree;
  int n, sz;

  int range_query(int ql, int qr, int t, int nl, int nr){
    if(ql <= nl && nr <= qr) return tree[t];
    if(ql > nr || qr < nl) return 0;

    int mid = (nl + nr) / 2;
    return range_query(ql, qr, 2 * t, nl, mid) + range_query(ql, qr, 2 * t + 1, mid + 1, nr);
  }
  int range_query(int ql, int qr){
    return range_query(ql, qr, 1, 0, sz - 1);
  }

  void point_update(int idx, string&s){
    s[idx] = (s[idx] == 'A' ? 'B' : 'A');
    if(idx > 0){
      tree[sz + idx] = s[idx] == s[idx - 1];
      int tmp = sz+ idx;
      tmp /= 2;
      while(tmp >= 1) tree[tmp] = tree[tmp * 2] + tree[tmp * 2 + 1], tmp /= 2;
    }
    idx++;
    if(idx < n) tree[sz + idx] = s[idx] == s[idx - 1];
    if(idx + sz < 2 * sz){
        idx += sz;
        idx /= 2;
        while(idx >= 1) tree[idx] = tree[idx * 2] + tree[idx * 2 + 1], idx /= 2;    
    }
    
  }

  vector<int> minDeletions(string s, vector<vector<int>> qry) {
    vector<int> res;
    n = s.size();
    sz = 1;
    while(sz < n) sz *= 2;
    tree.resize(2 * sz);
    
    // build leaf
    for(int i = 1; i < n; i++){
      if(s[i] == s[i-1]) tree[sz + i] = 1;
    }

    // build inner tree
    for(int i = sz - 1; i >= 1; i--) tree[i] = tree[2 * i] + tree[2 * i + 1];

    for(int loop = 0; loop < (int)qry.size(); loop++){
      int t = qry[loop][0];
      if(t == 1){ // point update
        int j = qry[loop][1];
        point_update(j, s);
        // dbg(s);
      }
      else { // range query
        int l = qry[loop][1];
        int r = qry[loop][2];
        res.push_back(range_query(l, r) - (l > 0 && s[l] == s[l-1]));
        for(int i = 1; i < 2 * sz; i++) cout << tree[i] << ' ';
        cout << '\n';
        cout << res.back() << '\n';
      }
    } 
    return res; 
  }
};

int main(){
  Solution sol;
  // sol.minDeletions( "ABA", {{2,1,2},{1,1},{2,0,2}});
  // sol.minDeletions( "ABB", {{2,0,2},{1,2},{2,0,2}});
  sol.minDeletions( "BABA", {{2,0,3},{1,1},{2,1,3}});
}
