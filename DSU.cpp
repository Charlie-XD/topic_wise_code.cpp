struct DSU{
    int n, cc;
    vector<ll> par, sz;
    DSU(int n){
        this->n = n;
        this->cc = n;
        par.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(par.begin(), par.end(), 0LL);
    }
    ll find(ll x){
        if(par[x] == x){
            return x;
        }
        return par[x] = find(par[x]);
    }
    bool unite(ll x, ll y){
        x = find(x);
        y = find(y);
        if(x != y){
            if(sz[x] < sz[y]){
                swap(x, y);
            }
            par[y] = x;
            sz[x] += sz[y];
            cc--;
            return true;
        }
        return false;
    }
    bool connected(ll x, ll y){
        return find(x) == find(y);
    }
    ll size(ll x){
        return sz[find(x)];
    }
};
