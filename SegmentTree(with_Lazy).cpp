struct SEGTREE{
    int n;
    vector<ll> a, tree, lazy;
    SEGTREE(vector<ll> &x){
        this->n = x.size();
        this->a = x;
        tree.assign(4 * n + 1, 0);
        lazy.assign(4 * n + 1, 0);
        build(0, 0, n - 1);
    }
    void push(int i, int lo, int hi){
        if(lazy[i]){
            tree[i] += (hi - lo + 1) * lazy[i];
            if(lo != hi){
                lazy[(i << 1) + 1] += lazy[i];
                lazy[(i << 1) + 2] += lazy[i];
            }
            lazy[i] = 0;
        }
    }
    void build(int i, int lo, int hi){
        if(lo == hi){
            tree[i] = a[lo];
            return;
        }
        int mid = (lo + hi) >> 1;
        build((i << 1) + 1, lo, mid);
        build((i << 1) + 2, mid + 1, hi);
        tree[i] = tree[(i << 1) + 1] + tree[(i << 1) + 2];
    }
    void update(int i, int lo, int hi, int ql, int qr, ll val){
        push(i, lo, hi);
        if(ql > hi || qr < lo){
            return;
        }
        if(ql <= lo && hi <= qr){
            lazy[i] += val;
            push(i, lo, hi);
            return;
        }
        int mid = (lo + hi) >> 1;
        update((i << 1) + 1, lo, mid, ql, qr, val);
        update((i << 1) + 2, mid + 1, hi, ql, qr, val);
        tree[i] = tree[(i << 1) + 1] + tree[(i << 1) + 2];
    }
    ll query(int i, int lo, int hi, int ql, int qr){
        push(i, lo, hi);
        if(ql > hi || qr < lo){
            return 0;
        }
        if(ql <= lo && hi <= qr){
            return tree[i];
        }
        int mid = (lo + hi) >> 1;
        ll left = query((i << 1) + 1, lo, mid, ql, qr);
        ll right = query((i << 1) + 2, mid + 1, hi, ql, qr);
        return left + right;
    }
};
