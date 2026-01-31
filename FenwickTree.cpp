struct Fenwick{
    int n;
    vector<ll> bit;
    Fenwick(int n){
        this->n = n;
        bit.assign(n + 1, 0);
    }
    void update(int idx, ll val){
        while(idx <= n){
            bit[idx] += val;
            idx += (idx & -idx);
        }
    }
    void rng_update(int l, int r, ll val){
        update(l, val);
        update(r + 1, -val);
    }
    ll sum(int idx){
        ll s = 0;
        while(idx){
            s += bit[idx];
            idx -= (idx & -idx);
        }
        return s;
    }
    ll query(int l, int r){
        if(l > r){
            return 0;
        }
        return sum(r) - sum(l - 1);
    }
    int kth(ll k){
        int pos = 0; ll s = 0;
        for(int i = 1 << (__lg(n)); i > 0; i >>= 1){
            if(pos + i <= n && s + bit[pos + i] < k){
                pos += i;
                s += bit[pos];
            }
        }
        return ++pos;
    }
};
