struct prefsum_2d{
	int n, m;
	vector<vector<int>> pf;
	void init(vector<vector<int>>&ar, int _n, int _m){
		n = _n;
		m = _m;
		pf = ar;
	}
	void build(){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				pf[i][j] += pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
			}
		}
	}
	int get_sum(int r1, int c1, int r2, int c2){
		if(r1 <= 0) r1=1;
		if(r2 <= 0) r2=1;
		if(r1 > n) r1=n;
		if(r2 > n) r2=n;
		if(c1 <= 0) c1=1;
		if(c2 <= 0) c2=1;
		if(c1 > m) c1=m;
		if(c2 > m) c2=m;
		return pf[r2][c2] - pf[r1-1][c2] - pf[r2][c1-1] + pf[r1-1][c1-1];
	}
};