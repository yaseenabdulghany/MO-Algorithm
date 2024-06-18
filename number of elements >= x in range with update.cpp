#include <bits/stdc++.h>
using namespace std;
#define FAST_DOT_COM  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
const int N = 5e5+5 ,MOD=1e9+7, INF=0X3F3F3F3F , MAX= 1e12+5;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int SQ= 317 , num_of_queries=1e5+5;
vector<int>block[SQ];
vector<int>v;
//int ign = 1e9+5 ;
bool mrg(int a , int b) {
    return a >= b;
}
void build() {
    for (int i = 0; i < v.size(); ++i) {
        block[i/SQ].emplace_back(v[i]);
    }
    for (auto &i: block)sort(i.begin(), i.end());
}
void update(int i , int val) {
    int l = i - i % SQ, r = l + SQ - 1, res = 0;
    v[i] = val;
    block[i / SQ] = vector<int>(v.begin() + l, v.begin() + r + 1);;
    sort(block[i / SQ].begin(), block[i / SQ].end());
}
int query(int l , int r , int c) {
    int res = 0;
    while (l <= r && l % SQ) {
        res += (mrg(v[l], c)) ? 1 : 0;
        l++;
    }
    while (l + SQ - 1 <= r) {
        res += block[l / SQ].end() - lower_bound(block[l / SQ].begin(), block[l / SQ].end(), c);
        l += SQ;
    }
    while (l <= r) {
        res += (mrg(v[l], c)) ? 1 : 0;
        l++;
    }
    return res;
}
void solve() {
    int n, q;
    cin >> n;
    v = vector<int>(n);
    for (auto &i: v)cin >> i;
    build();
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos, val;
            cin >> pos >> val;
            update(--pos, val);
        } else {
            int l, r , c;
            cin >> l >> r >> c;
            cout << query(--l, --r,c) << "\n";
        }
    }
}
int32_t main(){
    FAST_DOT_COM
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
    int t=1 ;
//    cin>>t ;
    while (t--) solve();
    return 0;
}
