#include <bits/stdc++.h>
using namespace std;
#define FAST_DOT_COM  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
const int N = 3e4+5 ,MOD=1e9+7, INF=0X3F3F3F3F , MAX= 1e9+7;
bool comp(pair<int, int> &a,pair<int,int> &b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}
struct Query {
    int l, r, iq;
};
int n ,ans=0 , vis[1000005] ;
vector<int>a;
void add(int x) {
    if (!vis[x]) {
        ans++;
    }
    vis[x]++;
}
void remove(int x) {
    vis[x]--;
    if (!vis[x]) {
        ans--;
    }
}
vector<int> MO_process(vector<Query>&qu) {
    const int SQ=ceil(sqrt(n))+1 ;
    sort(qu.begin(), qu.end(),
         [&](const Query &x , const Query &y) -> bool {
             if(x.l/SQ == y.l/SQ)
                 return x.r<y.r;
             return x.l/SQ < y.l/SQ;
        }
    );
    int l = qu[0].l, r = qu[0].l;
    add(a[qu[0].l]);
    vector<int>res(qu.size());
    for(const auto & [lq,rq,iq] : qu){
        while (l < lq)remove(a[l++]);
        while (l > lq)add(a[--l]);
        while (r < rq)add(a[++r]);
        while (r > rq)remove(a[r--]);
        res[iq] = ans;
    }
    return res;
}
void solve() {
    cin >> n;
    a.assign(n,{});
    for(auto &i : a)cin >> i ;
    int q ;
    cin >> q;
    vector<Query>Q(q);
    for (int i = 0; i < q; ++i) {
        cin >> Q[i].l >> Q[i].r ;
        --Q[i].l , --Q[i].r;
        Q[i].iq=i;
    }
    auto res = MO_process(Q);
    for(auto it : res)cout<<it<<"\n";
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
