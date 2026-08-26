// interative
int w[2100], h[2100], dp[2100][2100];

void solve(){	
	int bag, n;
	cin >> bag >> n;
	for(int i = 1; i <= n; i++){
		cin >> w[i] >> h[i];
	}
	for(int i = 0; i < 2100; i++)memset(dp[i], 0, sizeof(dp[i]));
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= bag; j++){
			int res = dp[i-1][j];
			if(j >= w[i]){
				res = max(res, dp[i-1][j-w[i]] + h[i]);
			}
			dp[i][j] = res;
		}
	}

	int min_w = bag;
	for(int i = bag - 1; i >= 0; i--){
		if(dp[n][bag] == dp[n][i]) min_w = i;
	}
	vector<int> c;
	for(int i = n; i > 0 && min_w > 0; i--){
		if(dp[i][min_w] != dp[i-1][min_w]){
			min_w -= w[i];
			c.push_back(i);
		}
	}
	for(int i = c.size() -1; i >= 0; i--) cout << c[i] << '\n';
}

// recursive
const int N = 2005;
int w[N], h[N], k, n, dp[N][N];

int f(int i, int bag){
	if(i < 0) return 0;
	if(dp[i][bag] != -1) return dp[i][bag];
	int res = f(i - 1, bag);
	if(bag >= w[i]) res = max(res, f(i - 1, bag - w[i]) + h[i]);
	return dp[i][bag] = res;
}

void solve(){
	cin >> n >> k;
	for(int i = 0; i < k; i++){
		cin >> w[i] >> h[i];
	}
	// reverse(w, w + k);
	// reverse(h, h + k);
	memset(dp, -1, sizeof(dp));
	f(k - 1, n);

	// for(int i = 0; i < k; i++){
	// 	for(int j = 0; j <= n; j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }return;

	int x = k - 1, y = n;
	vector<int> res;
	while(x >= 0 && y >= 0){
		if(y >= w[x] && f(x - 1, y - w[x]) + h[x] == dp[x][y]){
			res.push_back(x);
			y -= w[x];
		}
		x--;
	}
	reverse(res.begin(), res.end());
	for(int i : res) cout << i + 1 << " ";
}
