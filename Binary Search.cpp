/*

    I  MAKE  MiSTAKES, BUT
    I  ALWAYS  COMEBACK ...
                     --> HAYATO

*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
#define   int          long long
#define   db           double
#define   minHeap      priority_queue <int, vector <int>, greater <int>>
#define   maxHeap      priority_queue <int>
#define   P            pair <int, int>
#define   mp           make_pair
#define   pb           push_back
#define   pp           pop_back
#define   eb           emplace_back
#define   in           insert
#define   fi           first
#define   se           second
#define   sz(x)        (int)x.size()
#define   lb           lower_bound
#define   ub           upper_bound
#define   gcd(x, y)    __gcd(x, y)
#define   lcm(x, y)    (x / gcd(x, y) * y)
#define   all(x)       x.begin(), x.end()
#define   alt(x)       x.rbegin(), x.rend()
#define   cntBit(x)    __builtin_popcountll(x)
#define   lsb(x)       __builtin_ffsll(x)
#define   msb(x)       (63 - __builtin_clzll(x))
#define   debug(x)     cerr << "-> " << #x << " = " << x << endl;
#define   debugv(x)    cerr << "-> " << #x << " = "; for(const auto &_ : x) cerr << _ << " "; cerr << endl;
const int     MOD     = 1e9 + 7;
const int     N       = 2e5 + 7;
const int     inf     = 1e18 + 7;
const double  PiE     = acos(-1.0);
const vector <int> dx = {0, 1, 0, -1};
const vector <int> dy = {1, 0, -1, 0};

void solve(){
  int n, target;
  cin >> n >> target;

  vector <P> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i].fi;
    a[i].se = i;
  }
  sort(all(a));

  int pos = -1;
  int left = 0, right = n - 1;
  while(left <= right){
    int mid = left + (right - left) / 2;
    if(a[mid].fi == target){
        cout << a[mid].se << endl;
        return;
    } else if(a[mid].fi > target){
        right = mid - 1;
    } else{
        left = mid + 1;
    }
  }
  cout << pos << endl;
}

int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t;
  while(t--)
    solve();

  return 0;
}
