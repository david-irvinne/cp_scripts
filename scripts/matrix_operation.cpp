

vector<vector<int>> mul(vector<vector<int>>left,vector<vector<int>>right){
    vector<vector<int>> res;
    for(int i = 0; i < left.size(); i++){
        res.push_back({});
        for(int j = 0; j < right[0].size(); j++){
            int sum = 0;
            for(int k = 0; k < left[0].size(); k++){
                sum += left[i][k] * right[k][j];
                sum = (sum + MOD) % MOD;
            }
            res.back().push_back(sum);
        }
    }
    return res;
}
vector<vector<int>> mpow(vector<vector<int>> a, int b){
    vector<vector<int>> res = { {1, 0}, {0, 1}  };
    while(b){
        if(b % 2) res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}
