#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 69;
#define LL long long
LL arr[maxn], tree[4 * maxn], lazy[4 * maxn];

void build(int i, int l, int r){
    if(l == r){
        tree[i] = arr[l];
        lazy[i] = 0;
        return;
    }
    int mid = l + (r - l) / 2;
    build(2 * i + 1, l, mid);
    build(2 * i + 2, mid + 1, r);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

void push(int i, int l, int r){
    if(lazy[i] != 0){
        tree[i] += lazy[i] * (r - l + 1);
        if(l != r){
            lazy[2 * i + 1] += lazy[i];
            lazy[2 * i + 2] += lazy[i];
        }
        lazy[i] = 0;
    }
}

void update(int i, int l, int r, int ql, int qr, LL val){
    push(i, l, r);
    if(l > qr || r < ql) return;
    if(ql <= l && r <= qr){
        lazy[i] += val;
        push(i, l, r);
        return;
    }
    int mid = l + (r - l) / 2;
    update(2 * i + 1, l, mid, ql, qr, val);
    update(2 * i + 2, mid + 1, r, ql, qr, val);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

LL query(int i, int l, int r, int ql, int qr){
    push(i, l, r);
    if(l > qr || r < ql){
        return 0;
    }
    if(ql <= l && r <= qr){
        return tree[i];
    }
    int mid = l + (r - l) / 2;
    return query(2 * i + 1, l, mid, ql, qr) + query(2 * i + 2, mid + 1, r, ql, qr);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    build(0, 0, n - 1);
    while(q--){
        int x;
        cin >> x;

        if(x == 1){
           LL l, r, val;
           cin >> l >> r >> val;
           --l, --r;
           update(0, 0, n - 1, l, r, val);
        } else{
            LL l, r;
            cin >> l >> r;
            --l, --r;
            LL ans = query(0, 0, n - 1, l, r);
            cout << ans << '\n';
        }
    }
    return 0;
}
