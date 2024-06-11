#include <bits/stdc++.h>
using namespace std;
#define FAST_DOT_COM  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
const int N = 3e4+5 ,MOD=1e9+7, INF=0X3F3F3F3F , MAX= 1e9+7;
bool comp(pair<int, int> &a,pair<int,int> &b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}
const int SQ= sqrt(N) , num_of_queries=2e5+5;
struct query{
    int l , r , blk_idx , q_idx ;
    query(){}
    query(int _l , int _r ,int _q_idx){
        l=_l , r=_r , q_idx=_q_idx , blk_idx=_l/SQ;
    }
    // sort queries
    bool operator<(const query &q)const{
        if(blk_idx!=q.blk_idx){
            return blk_idx<q.blk_idx;
        }
        return r<q.r;
    }
};
int n , q ,res=0 , vis[1000005] , L=0 ,R=0 , a[N],first=1,ans[num_of_queries];
query qu[num_of_queries];
void add(int idx){
    if(!vis[a[idx]]){
        res++;
    }
    vis[a[idx]]++;
}
void remove(int idx){
    vis[a[idx]]--;
    if(!vis[a[idx]]){
        res--;
    }
}
void MO_process(){
    sort(qu,qu+q);
    int l=1 , r=0 ;
    for (int i = 0; i < q; ++i) {
        while (l<qu[i].l)remove(l++);
        while (l>qu[i].l)add(--l);
        while (r<qu[i].r)add(++r);
        while (r>qu[i].r)remove(r--);
        ans[qu[i].q_idx]=res;
    }
}
void solve() {
    cin >> n ;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> q ;
    for (int i = 0; i < q; ++i) {
        int l , r ;
        cin >> l >> r ;
        l--, r--;
        // i:query index
        qu[i]=query(l,r,i);
    }
    MO_process();
    for (int i = 0; i < q; ++i) {
        cout<<ans[i]<<"\n";
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
