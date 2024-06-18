#include <bits/stdc++.h>
using namespace std;
#define FAST_DOT_COM  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
const int N = 2e5+5 ,MOD=1e9+7, INF=0X3F3F3F3F , MAX= 1e12+5;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
//bool comp(pair<int, int> &a,pair<int,int> &b) {
//    if (a.first != b.first) return a.first > b.first;
//    return a.second < b.second;
//}
const int SQ= ceil(sqrt(N)) , num_of_queries=1e5+5;
//struct query{
//    int l , r , blk_idx , q_idx ;
//    query(){}
//    query(int _l , int _r ,int _q_idx){
//        l=_l , r=_r , q_idx=_q_idx , blk_idx=_l/SQ;
//    }
//    // sort queries
//    bool operator<(const query &q)const{
//        if(blk_idx!=q.blk_idx){
//            return blk_idx<q.blk_idx;
//        }
//        return r<q.r;
//    }
//};
//int mp[100009], q ,k,res=0 , a[N],ans[num_of_queries];
//query qu[num_of_queries];
//void add(int idx){
//    mp[a[idx]]++;
//    res+=mp[a[idx]^k];
//    res-=(k==0);
//}
//void remove(int idx){
//    res-=(mp[a[idx]^k]);
//    mp[a[idx]]--;
//    res+=(k==0);
//}
//void MO_Process(){
//    sort(qu,qu+q);
//    int l=1 , r=0 ;
//    for (int i = 0; i < q; ++i) {
//        while (l<qu[i].l)remove(l++);
//        while (l>qu[i].l)add(--l);
//        while (r<qu[i].r)add(++r);
//        while (r>qu[i].r)remove(r--);
//        ans[qu[i].q_idx]=res;
//    }
//}
vector<int>block,v;
int ign = 1e9+5 ;
int mrg(int a , int b){
    return a^b;
}
void build(){
    block.assign(SQ,0);
    for (int i = 0; i < v.size(); ++i) {
        int bl_idx=i/SQ;
        block[bl_idx]=mrg(block[bl_idx],v[i]);
    }
}
void update(int i , int val){
    int l = i-i%SQ , r = l+SQ-1 , res=0;
    v[i]=val;
    for (int j = l; j <= r ; ++j) {
        res=mrg(res,v[j]);
    }
    block[i/SQ]=res;
}
int query(int l , int r) {
    int res = 0;
    while (l <= r && l % SQ) {
        res = mrg(res, v[l]);
        l++;
    }
    while (l + SQ - 1 <= r) {
        res = mrg(res, block[l / SQ]);
        l += SQ;
    }
    while (l <= r) {
        res = mrg(res, v[l]);
        l++;
    }
    return res;
}
void solve() {
    int n , q ;
    cin >> n >> q ;
    v= vector<int>(n);
    for(auto & i : v)cin >> i ;
    build();
    while (q--){
//        int type ;
//        cin >> type ;
//        if(type==1){
//            int pos , val ;
//            cin >> pos >> val ;
//            update(--pos,val);
//        }
//        else {
            int l , r ;
            cin >> l >> r ;
            cout<<query(--l,--r)<<"\n";
//        }
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
