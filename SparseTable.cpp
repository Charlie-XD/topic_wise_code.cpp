struct SparseTable{
    int n, k;
    vector<vector<ll>> t;
    vector<ll> a;
    vector<int> lg;
    SparseTable(vector<ll> &x){
        this->n = x.size();
        this->a = x;
        this->k = 31 - __builtin_clz(n);
        t.assign(k + 1, vector<ll> (n + 1, 0));
        lg.assign(n + 1, 0);
        build();
    }
    void build(){
        for(int i = 2; i <= n; i++){
            lg[i] = lg[i / 2] + 1;
        }
        for(int i = 0; i < n; i++){
            t[0][i] = a[i];
        }
        for(int i = 1; i <= k; i++){
            for(int j = 0; j + (1 << i) <= n; j++){
                t[i][j] = min(t[i - 1][j], t[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    ll query(int l, int r){
        int i = lg[r - l + 1];
        return min(t[i][l], t[i][r - (1 << i) + 1]);
    }
};
